#include <iostream>
#include "deque.h"


using namespace P;


int main() {

  deque<int> deq;
  for (std::uint32_t i=0; i < 25; ++i)
  {
    deq.push_back(i);
  }

  for (std::uint32_t i=0; i < 25; ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  for (std::uint32_t i=0; i < 10; ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  for (std::uint32_t i=0; i < 25; ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  return 0;
}
