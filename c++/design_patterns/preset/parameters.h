#ifndef CHALLENGE_PARAMETERS_H_
#define CHALLENGE_PARAMETERS_H_

#include "motor_parameters.h"
#include "image_processing_parameters.h"


namespace Task
{

/**
 * Struct for parameters
 *
 * @tparam AddressType address type
 */
template<typename AddressType>
struct Parameters
  {
    /// Motor parameters
    MotorParameters<AddressType> motorParameters;
    /// Image processing parameters
    ImageProcessingParameters imageProcessingParameters;
  };

/**
 * Configuration policy
 */
struct ConfigInProgress
  {
    typedef Parameters<int> Params;
  };
}

#endif //CHALLENGE_PARAMETERS_H_
