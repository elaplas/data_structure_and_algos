// ================================================================================================
//
// If not explicitly stated: Copyright (C) 2016, all rights reserved,
//      Rüdiger Göbl
//		Email r.goebl@tum.de
//      Chair for Computer Aided Medical Procedures
//      Technische Universität München
//      Boltzmannstr. 3, 85748 Garching b. München, Germany
//
// ================================================================================================

#include "CallFrequency.h"

#include "utility.h"
#include <utilities/Logging.h>


#include <sstream>

using namespace std;

namespace supra
{
CallFrequency::CallFrequency(std::string name)
    : m_name(name)
    , m_initialized(false)
    , m_runTimeInitialized(false)
    , m_callNum(0)
    /// common: initialize the following member variables with "0.0" as they are double
    , m_filtRuntime(0)
    , m_flastTime(0)
    , m_lastPrint(0)
    , m_ffiltTimeDelta(0)
{}

CallFrequency::~CallFrequency()
{
  printEnd(m_name, m_callNum);
}

void CallFrequency::measure() {
  double thisTime = getCurrentTime();
  logging::log_profiling_if(LOG_PROFILING, "Profiling ", m_name, " ", thisTime, " S ", m_callNum);
  /// comment: "if (m_initialized)" can be replaced by "if (m_callNum > 1)", so "m_initialized" is redundant
  if (m_initialized) {
    double delta = thisTime - m_flastTime;
    m_ffiltTimeDelta = m_ffiltTimeDelta - (m_fFilter * (m_ffiltTimeDelta - delta));
  }
  else {
    if (m_callNum == 1)
    {
      m_ffiltTimeDelta = thisTime - m_flastTime;
      m_initialized = true;
    }
    m_lastPrint = thisTime;
  }
  m_flastTime = thisTime;
  m_callNum++;

  if (thisTime - m_lastPrint > 1) {
    print();
    m_lastPrint = thisTime;
  }
}

void CallFrequency::measureEnd()
{
  double thisTime = getCurrentTime();
  logging::log_profiling_if(LOG_PROFILING, "Profiling ", m_name, " ", thisTime, " E ", m_callNum-1);
  /// comment: why you need a line to be called 10 times to measure the runtime from that line to another line?
  /// you shall remove the condition "if (m_initialized && m_callNum > 10)" and replace it with
  /// "if (m_callNum > 0)". Additionally the condition "if (!m_runTimeInitialized)" can be replaced with "if (m_callNum == 1)"
  if (m_initialized && m_callNum > 10)
  {
    double timeDiff = thisTime - m_flastTime;
    if (!m_runTimeInitialized)
    {
      m_filtRuntime = timeDiff;
      m_runTimeInitialized = true;
    }
    else {
      m_filtRuntime = m_filtRuntime - (m_fFilter * (m_filtRuntime - timeDiff));
    }
  }
}

void CallFrequency::print() {
  /// comment: in the two following divisions the case of zero division is not handled
  /// you should use the smallest value of your system and define it as zero and through exception (or ignore it)
  /// if dominator is smaller than the smallest value
  if (!m_runTimeInitialized)
  {
    printFrequency(m_name, 1 / m_ffiltTimeDelta);
  }
  else {
    printFrequencyAndRuntime(m_name, 1 / m_ffiltTimeDelta, m_filtRuntime);
  }
}

string CallFrequency::getTimingInfo()
{
  ///comment: the second nested "if condition" shall be taken out from the first "if condition" since "measureEnd()"
  /// can be called before we call "measure()". Additionally no handle of zero division
  string ret;
  if (m_initialized)
  {
    double frequency = 1 / m_ffiltTimeDelta;
    stringstream s;
    s << std::setprecision(3) << frequency << " Hz";
    if (m_runTimeInitialized)
    {
      bool logInMs = m_filtRuntime < 0.5;
      s << ", " << std::setprecision(3) << (logInMs ? m_filtRuntime * 1000 : m_filtRuntime) << (logInMs ? " ms" : " s");
    }
    ret = s.str();
  }
  return ret;
}

void CallFrequency::setName(std::string name)
{
  m_name = name;
}

void CallFrequency::printFrequency(string name, double frequency) {
  logging::log_log_if(LOG_FREQUENCIES, "Freq ", name, " ", frequency, " Hz");
}

void CallFrequency::printFrequencyAndRuntime(std::string name, double frequency, double runtime)
{
  bool logInMs = runtime < 0.5;
  logging::log_log_if(LOG_FREQUENCIES, "Freq ", name, " ", frequency, " Hz, ", (logInMs ? runtime * 1000 : runtime), (logInMs ? " ms" : " s"));
}

void CallFrequency::printEnd(string name, int callNum) {
  logging::log_log_if(LOG_FREQUENCIES, "CallFrequency ", name, " was called ", callNum, " times.");
}
}