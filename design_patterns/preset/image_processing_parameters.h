#ifndef CHALLENGE_IMAGE_PROCESSING_PARAMETERS_H_
#define CHALLENGE_IMAGE_PROCESSING_PARAMETERS_H_



namespace Task {

/**
 * Struct for image processing parameters
 */
struct ImageProcessingParameters {

  /// Cut off threshold
  float cutOff {0.f};
  /// Smoothing
  float smoothing {0.f};

  /**
   * Setter for cut-off
   *
   * @param cf cut-off
   */
  void SetCutOff(const float cf) {
    cutOff = cf;
  }

  /**
   * Setter for smoothing
   *
   * @param sg smoothing
   */
  void SetSmoothing(const float &sg) {
    smoothing = sg;
  }
};
}
#endif //CHALLENGE_IMAGE_PROCESSING_PARAMETERS_H_
