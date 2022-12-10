#include <iostream>
#include "dynamic_queue.h"
#include "static_queue.h"

int main() {

  DynamicQueue<int> queue1;

  for (int i = 0; i < 10; ++i) {
    queue1.push(i);
  }

  /// test dynamic queue
  std::cout << queue1[0].data_ << std::endl;
  queue1.pop();
  std::cout << queue1.front() << std::endl;
  std::cout << queue1.back() << std::endl;
  std::cout <<"..........................."<<std::endl;

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
