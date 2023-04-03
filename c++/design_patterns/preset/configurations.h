#ifndef CHALLENGE_CONFIGURATIONS_H_
#define CHALLENGE_CONFIGURATIONS_H_

#include "parameters.h"


namespace Task
{
/**
 * Generic class for configuration
 *
 * @tparam configPolicy  configuration policy
 */
template<class configPolicy>
class Configuration
{
   public:
    /// Data type definition
    typedef typename configPolicy::Params Params;

    /**
     * Copy assignment
     *
     * @param other Configuration object to be copied
     * @return Configuration
     */
    Configuration operator=(const Configuration& other)
    {
      params_ = other.params_;
      return *this;
    }

    /**
     * Const getter for parameters
     *
     * @return parameters
     */
    const Params& GetParams() const noexcept
    {
      return params_;
    }

    /**
     * Getter for parameters
     *
     * @return parameters
     */
    Params& GetParams()
    {
      return params_;
    }

   private:
    /// Parameters
    Params params_;
};

/**
 * Actual implementation of configuration
 */
class ConfigurationImpl: public Configuration<ConfigInProgress>
{
};

}
#endif //CHALLENGE_CONFIGURATIONS_H_
