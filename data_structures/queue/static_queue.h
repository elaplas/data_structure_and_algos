//
// Created by z639627 on 2/27/21.
//

#ifndef QUEUE__STATIC_QUEUE_H_
#define QUEUE__STATIC_QUEUE_H_

template <class Type, int MAX_SIZE>
class StaticQueue {
 public:
  StaticQueue():
  front_(0),
  back_(MAX_SIZE-1)
  {}


  Type& push(const Type& element)
  {
    back_=(back_+1)%MAX_SIZE;
    data_[back_]=element;
    return data_[back_];
  }

  Type& pop()
  {
    int oldFront = front_;
    front_ = (front_+1)%MAX_SIZE;
    return data_[oldFront];
  }

  Type& operator[](int i)
  {
    return data_[(front_+i)%MAX_SIZE];
  };

  Type& front()
  {
    return data_[front_];
  }

  Type& back()
  {
    return data_[back_];
  }


 private:
  Type data_[MAX_SIZE];
  int front_;
  int back_;
};

#endif //QUEUE__STATIC_QUEUE_H_
