#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <chrono>
#include <thread>

#include "doctest.h"
#include "preset.h"

TEST_CASE("testing meta data related methods of preset object") {
  // Instantiate an object
  Task::Preset preset;
  // Check name, version ...
  CHECK(preset.GetName() == "Preset");
  CHECK(preset.GetDescription() == "I am a Preset");
  CHECK(preset.GetVersion() == "00.0.00");
  // Check creation date
  time_t t = time(0);
  struct tm * timeStruct = localtime(&t);
  const auto& presetTime = preset.GetTime();
  CHECK(presetTime.year == timeStruct->tm_year);
  CHECK(presetTime.month == timeStruct->tm_mon);
  CHECK(presetTime.day == timeStruct->tm_mday);
  CHECK(presetTime.hour == timeStruct->tm_hour);
  CHECK(presetTime.min == timeStruct->tm_min);
}

TEST_CASE("testing setters and getters for parameters") {
  // Instantiate an object
  Task::Preset preset;
  // Set parameters
  auto& params1 = preset.GetParams();
  params1.imageProcessingParameters.SetCutOff(0.5f);
  params1.imageProcessingParameters.SetSmoothing(0.9f);
  params1.motorParameters.SetAcceleration(30.2f);
  params1.motorParameters.SetSpeed(20.1f);
  params1.motorParameters.SetAddress(12569);
  // Get parameters
  const auto& params2 = preset.GetParams();
  // Check the parameters
  CHECK(params2.imageProcessingParameters.cutOff == 0.5f);
  CHECK(params2.imageProcessingParameters.smoothing == 0.9f);
  CHECK(params2.motorParameters.acceleration == 30.2f);
  CHECK(params2.motorParameters.speed == 20.1f);
  CHECK(params2.motorParameters.address == 12569);
}

TEST_CASE("testing copy assignment methods") {
  // Instantiate an object
  Task::Preset preset;
  // Set parameters
  auto& params1 = preset.GetParams();
  params1.imageProcessingParameters.SetCutOff(0.5f);
  params1.imageProcessingParameters.SetSmoothing(0.9f);
  params1.motorParameters.SetAcceleration(30.2f);
  params1.motorParameters.SetSpeed(20.1f);
  params1.motorParameters.SetAddress(12569);
  // make a copy of preset
  Task::Preset presetCopy = preset;
  // Check consistency of meta data
  CHECK(presetCopy.GetName() == preset.GetName());
  CHECK(presetCopy.GetDescription() == preset.GetDescription());
  CHECK(presetCopy.GetVersion() == preset.GetVersion());
  // Get params of copied preset object
  const auto& params2 = presetCopy.GetParams();
  // Check consistency of parameter values
  CHECK(params2.imageProcessingParameters.cutOff == 0.5f);
  CHECK(params2.imageProcessingParameters.smoothing == 0.9f);
  CHECK(params2.motorParameters.acceleration == 30.2f);
  CHECK(params2.motorParameters.speed == 20.1f);
  CHECK(params2.motorParameters.address == 12569);

  // Make a copy of cofig
  const auto& config = preset.GetConfig();
  Task::ConfigurationImpl configCopy = config;
  // Get params and copied params
  const auto& configParams = config.GetParams();
  const auto& configParamsCopy = configCopy.GetParams();
  CHECK(configParamsCopy.imageProcessingParameters.cutOff == 0.5f);
  CHECK(configParamsCopy.imageProcessingParameters.smoothing == 0.9f);
  CHECK(configParamsCopy.motorParameters.acceleration == 30.2f);
  CHECK(configParamsCopy.motorParameters.speed == 20.1f);
  CHECK(configParamsCopy.motorParameters.address == 12569);
}

// NOTE: doctest already implements a main(), no explicit implementation needed here
// for more information about doctest, see https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md