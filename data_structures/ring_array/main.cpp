#include <iostream>
#include "static_ring_array.h"

int main() {

  StaticRingArray<int, 10> ringArray;
  for (int i=0; i < 10; ++i)
  {
    ringArray.add(i*2);
  }

  ringArray.remove(3);
  ringArray.remove(7);

  std::cout<<ringArray.add(12)<<std::endl;
  std::cout<<ringArray.add(22)<<std::endl;

  return 0;
}
