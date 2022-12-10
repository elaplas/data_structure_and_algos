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

#ifndef __CALLFREQUENCY_H__
#define __CALLFREQUENCY_H__

#include <string>
#include <iostream>
#include <mutex>

#ifndef LOG_FREQUENCIES
#define LOG_FREQUENCIES true
#endif //!LOG_FREQUENCIES
#ifndef LOG_PROFILING
#define LOG_PROFILING false
#endif //!LOG_PROFILING

namespace supra
{

/// comment: there is no doxygen documentation for the class, its methods and member variables!
class CallFrequency {
 public:

  CallFrequency(std::string name);

  /// comment: define destructor as a virtual function in order to make sure the future derived class object is deleted
  ~CallFrequency();

  void measure();

  void measureEnd();

  void print();

  std::string getTimingInfo();

  /// comment: pass the function parameter "name" by const reference
  void setName(std::string name);

 private:
  /// pass the function parameter "name" by const reference
  static void printFrequency(std::string name, double frequency);
  /// pass the function parameter "name" by const reference
  static void printFrequencyAndRuntime(std::string name, double frequency, double runtime);
  /// pass the function parameter "name" by const reference
  static void printEnd(std::string name, int callNum);

  /// comment: it shall be better to initialize "m_fFilter" using curly brackets
  const double m_fFilter = 0.025;
  std::string m_name;
  double m_flastTime;
  double m_ffiltTimeDelta;
  double m_filtRuntime;
  double m_lastPrint;
  int m_callNum;
  bool m_initialized;
  bool m_runTimeInitialized;
};
}
#endif // !__CALLFREQUENCY_H__
