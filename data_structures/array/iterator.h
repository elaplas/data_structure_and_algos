//
// Created by z639627 on 2/27/21.
//

#ifndef ARRAY__ITERATOR_H_
#define ARRAY__ITERATOR_H_

namespace Example
{

template<class Type> class Iterator {

 public:
  Iterator(Type *pointer) :
      pointer_(pointer) {}

  Iterator operator++(int) {
    pointer_++;
    return *this;
  }

  Type& operator*()
  {
    return *pointer_;
  }

  bool operator==(const Iterator &other) {
    return pointer_ == other.pointer_;
  }

  bool operator!=(const Iterator &other) {
    return pointer_ != other.pointer_;
  }

 protected:
  Type* pointer_;
};
}

#endif //ARRAY__ITERATOR_H_
