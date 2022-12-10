#include <iostream>
#include "colorful_number.h"

int main() {

  ColorfulNumber colorfulNumber;
  std::cout << colorfulNumber.isColorful(3245) << std::endl;
  std::cout << colorfulNumber.isColorful(326) << std::endl;
  return 0;
}
