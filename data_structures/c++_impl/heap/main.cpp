#include <iostream>
#include "min_heap.h"




int main() {

  MinHeap<int> minHeap;
  minHeap.push( MinHeap<int>::Node{1, 3.5});
  minHeap.push( MinHeap<int>::Node{2, 5.5});
  minHeap.push( MinHeap<int>::Node{3, 2.5});
  minHeap.push( MinHeap<int>::Node{4, 0.5});
  minHeap.push( MinHeap<int>::Node{5, 0.75});
  while ( minHeap.size())
  {
      auto res = minHeap.pop();
      std::cout<< "value: "<<res.value << ", cost: "<<res.cost<<"\n";
  }

  return 0;
}
