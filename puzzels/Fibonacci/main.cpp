#include <iostream>
#include "Fibonacci.h"

int main() {
  std::cout << FibRec(6) << std::endl;
  std::cout << FibRecWithMem(6) << std::endl;
  std::cout << FibLoop(6) << std::endl;
  return 0;
}
