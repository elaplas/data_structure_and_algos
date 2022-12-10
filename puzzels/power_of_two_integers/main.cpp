#include <iostream>
#include <cmath>

bool IsPowerOfTwoIntegers(int number)
{
  bool res = false;
  for(int i=2; i<number/2; ++i)
  {
    float log_i = std::log(number) / std::log(i);
    float tmp = log_i - static_cast<int>(log_i);
    if (!tmp)
    {
      res = true;
      break;
    }
  }
  return res;
}


int main() {
  std::cout << IsPowerOfTwoIntegers(8) << std::endl;
  std::cout << IsPowerOfTwoIntegers(9) << std::endl;
  std::cout << IsPowerOfTwoIntegers(7) << std::endl;
  return 0;
}
