#ifndef HEAP__MIN_HEAP_H_
#define HEAP__MIN_HEAP_H_

#include <vector>

using namespace std;

class minHeap{

 public:
  int getParentIndex(int i){
    return (i-2)/2;
  }
  int getLeftChildIndex(int i)
  {
    return (i*2)+1;
  }
  int getRightChildIndex(int i)
  {
    return (i*2)+2;
  }
  bool hasParent(int i)
  {
    return getParentIndex(i) >= 0;
  }

  bool hasLeftChild(int i)
  {
    return getLeftChildIndex(i) < data_.size();
  }

  bool hasRightChild(int i)
  {
    return getRightChildIndex(i) < data_.size();
  }

  int getMin()
  {
    return data_[0];
  }

  void heapifyDown()
  {
      int currentIndex =0;
      while (hasLeftChild(currentIndex) && ( data_[currentIndex] > data_[getLeftChildIndex(currentIndex)] ||
                                                                  data_[currentIndex] > data_[getRightChildIndex(currentIndex)]) )
      {
        int childIndex = getLeftChildIndex(currentIndex);
        if (data_[getLeftChildIndex(currentIndex)] > data_[getRightChildIndex(currentIndex)])
        {
           childIndex = getRightChildIndex(currentIndex);
        }
        swap ( data_[currentIndex], data_[childIndex]);
        currentIndex = childIndex;
      }
  }
  void heapifyUp()
  {
    int currentIndex = data_.size() - 1;
    while (hasParent(currentIndex) && data_[getParentIndex(currentIndex)] > data_[currentIndex])
    {
      swap(data_[getParentIndex(currentIndex)], data_[currentIndex] );
    }
  }

  void Push(int value)
  {
    data_.push_back(value);
    heapifyUp();
  }

  int Pop()
  {
    int tmp = data_[0];
    data_[0] = data_.back();
    data_.pop_back();
    heapifyDown();
    return tmp;
  }

 private:
  vector<int> data_;
};


#endif//HEAP__MIN_HEAP_H_
