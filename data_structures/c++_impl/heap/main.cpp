#include <iostream>
#include "min_heap.h"




int main() {

  MinHeap<char, float> minHeap;
  minHeap.push('A', 9.5);
  minHeap.push('B', 7.5);
  minHeap.push('C', 10.5);
  minHeap.push('D', 5.5);
  minHeap.push('F', 1.5);
  
  while (!minHeap.empty())
  {
      cout<<"value: "<<minHeap.top().value<<", cost: "<<minHeap.top().cost<<"\n";
      minHeap.pop();
  }

  return 0;
}
