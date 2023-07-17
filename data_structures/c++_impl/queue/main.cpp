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
    std::cout<<que.pop_front()<<"\n";
  }

  return 0;
}
