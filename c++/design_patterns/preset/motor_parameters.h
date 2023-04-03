#ifndef CHALLENGE_MOTOR_PARAMETERS_H_
#define CHALLENGE_PARAMETERS_H_


namespace Task {

/**
 * Struct for motor parameters
 *
 * @tparam AddressType
 */
template<typename AddressType>
struct MotorParameters {

  /// Acceleration
  float acceleration {0.f};
  /// Speed
  float speed {0.f};
  /// Address
  AddressType address{};

  /**
   * Setter for acceleration
   *
   * @param accel acceleration
   */
  void SetAcceleration(const float accel) noexcept {
    acceleration = accel;
  }

  /**
   * Setter for speed
   *
   * @param velocity  speed
   */
  void SetSpeed(const float velocity) noexcept {
    speed = velocity;
  }

  /**
   * Setter for address
   *
   * @param addr address
   */
  void SetAddress(const AddressType &addr) noexcept {
    address = addr;
  }
};

}

#endif //CHALLENGE_VENDOR_MOTOR_PARAMETERS_H_
