
#ifndef RING_ARRAY__STATIC_RING_ARRAY_H_
#define RING_ARRAY__STATIC_RING_ARRAY_H_

/**
 * Hint: ring buffer or circular buffer is de facto in literature the static queue, which has a fixed size. It follows
 *       FIFO policy. As we can walk around it using modulo operation, it is called "ring or circular buffer".
 *
 *       but here in this class the so called "ring array" is an array where we can add/process elements in random positions (indices) and remove
 *       elements from random positions. When an element is added, we search for an empty position. An application of it is the maintenance
 *       of a certain number of tracks, or rather, adding tracks when they are created and removing them as they are gone.
 *
 */


template<class Type, int MAX_SIZE>
class StaticRingArray {

  struct Element
  {
    Type value_;
    bool isUsed_{false};
  };

 public:

  int next()
  {
    int tested{0};
    int res{-1};
    while (tested<MAX_SIZE && data_[next_].isUsed_)
    {
      next_ = (next_+1)%MAX_SIZE;
      ++tested;
    }
    if (tested < MAX_SIZE)
    {
      res = next_;
    }
    return res;
  }


  int add(const Type& value)
  {
    int index = next();
    if(index != -1)
    {
      Element element;
      element.value_ = value;
      element.isUsed_ = true;
      data_[index]=element;
    }
    return index;
  }

  void remove(int index)
  {
    data_[index].isUsed_= false;
  }

  void reset()
  {
    for (int i=0; i<MAX_SIZE; ++i)
    {
      data_[i].isUsed_=false;
    }
  }


 private:
  Element data_[MAX_SIZE];
  int next_{0};
};

#endif //RING_ARRAY__STATIC_RING_ARRAY_H_
