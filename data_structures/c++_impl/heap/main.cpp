#include <iostream>
#include "min_heap.h"


using namespace  std;

int main() {

  minHeap myHeap;
  myHeap.Push(2);
  myHeap.Push(3);
  myHeap.Push(4);
  myHeap.Push(5);
  myHeap.Push(6);
  myHeap.Push(7);
  myHeap.Push(8);
  myHeap.Push(9);
  std::cout << myHeap.getMin() << std::endl;
  myHeap.Pop();
  std::cout << myHeap.getMin() << std::endl;
  myHeap.Pop();
  std::cout << myHeap.getMin() << std::endl;
  return 0;
}
