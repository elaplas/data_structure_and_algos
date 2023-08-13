#include <iostream>
#include "dynamic_queue.h"
#include "static_queue.h"



int main() {

  StaticQueue<int, 10> que;
  for (int i = 0; i < 15; ++i)
  {
    que.push_back(i);
  }
  while (!que.empty())
  {
    std::cout<<que.front()<<"\n";
    que.pop_front();
  }

  using TQue = Queue<int>;
  TQue que;
  for (int i=0; i < 10; ++i)
  {
      que.push_back(i);
  }
  const TQue& refQue = que;
  for (auto el: refQue)
  {
      std::cout<<el<<"\n";
  }


  return 0;
}
