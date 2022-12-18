#include <iostream>
#include "deque.h"


using namespace P;


int main() {

  deque<int> deq;
  std::cout<<".................push back..................."<<std::endl;
  for (std::uint32_t i=0; i < 55; ++i)
  {
    if (i == 50)
    {
      int k = 0;
    }
    deq.push_back(i);
  }

  for (std::uint32_t i=0; i < deq.size(); ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  std::cout<<"..................pop back.................."<<std::endl;

  for (std::uint32_t i=0; i < 10; ++i)
  {
    deq.pop_back();
  }

  for (std::uint32_t i=0; i < deq.size(); ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  std::cout<<"................pop front...................."<<std::endl;

  for (std::uint32_t i=0; i < 10; ++i)
  {
    deq.pop_front();
  }

  for (std::uint32_t i=0; i < deq.size(); ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  std::cout<<".................push front.................."<<std::endl;
  for (std::int32_t i=10; i >= 0; --i)
  {
    deq.push_front(i);
  }

  for (std::uint32_t i=0; i < deq.size(); ++i)
  {
    std::cout<<deq[i]<<std::endl;
  }

  return 0;
}
