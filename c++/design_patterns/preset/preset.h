#ifndef CHALLENGE_PRESET_H_
#define CHALLENGE_PRESET_H_

#include "meta_data.h"
#include "configurations.h"

namespace Task
{

/**
 * Class for preset
 */
class Preset
{
 public:

  /**
   * Preset constructor
   */
  Preset()
  {
    metaData_.name = "Preset";
    metaData_.description = "I am a Preset";
    metaData_.version = "00.0.00";
    time_t t = time(0);
    struct tm * timeStruct = localtime(&t);
    metaData_.time.setTime(timeStruct->tm_year, timeStruct->tm_mon, timeStruct->tm_mday,
                           timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);
  }

  /**
   * Copy assignment
   *
   * @param other Preset object
   * @return Preset object
   */
  Preset operator=(const Preset& other)
  {
    metaData_.name = other.metaData_.name;
    metaData_.version = other.metaData_.version;
    metaData_.description = other.metaData_.description;
    metaData_.name += "_copied";
    return *this;
  }

  /**
   * Getter for name
   *
   * @return string
   */
  const std::string &GetName() const noexcept
  {
    return metaData_.name;
  }

  /**
   * Getter for description
   *
   * @return string
   */
  const std::string &GetDescription() const noexcept
  {
    return metaData_.description;
  }

  /**
   * Getter for version
   *
   * @return string
   */
  const std::string &GetVersion() const noexcept
  {
    return metaData_.version;
  }

  /**
   * Getter for time
   *
   * @return string
   */
  const Time &GetTime() const noexcept
  {
    return metaData_.time;
  }

  /**
   * Const getter for parameters
   *
   * @return parameters
   */
  const ConfigurationImpl::Params &GetParams() const noexcept
  {
    return config_.GetParams();
  }

  /**
   * Getter for parameters
   *
   * @return parameters
   */
  ConfigurationImpl::Params &GetParams() noexcept
  {
    return config_.GetParams();
  }

  /**
   * Const getter for configuration
   *
   * @return
   */
  const ConfigurationImpl& GetConfig() const noexcept
  {
    return config_;
  }

 private:
  /// Meta data
  MetaData metaData_;
  /// Configuration
  ConfigurationImpl config_;
 };

}

#endif //CHALLENGE_PRESET_H_


