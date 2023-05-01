#include <iostream>
#include "dynamic_queue.h"
#include "static_queue.h"

int main() {

  DynamicQueue<int> que;

  que.push_back(1);
  que.push_back(2);
  que.push_back(3);
  que.push_back(4);
  que.push_back(5);

  while (que.size())
  {
      std::cout<<que.pop_front() << std::endl;
  }

  StaticQueue<int, 10> queue2;

  for (int i = 0; i < 10; ++i) {
    queue2.push(i);
  }
  /// test static queue
  std::cout << queue2[0] << std::endl;
  queue2.pop();
  std::cout << queue2.front() << std::endl;
  std::cout << queue2.back() << std::endl;
  std::cout <<"..........................."<<std::endl;

  return 0;
}
