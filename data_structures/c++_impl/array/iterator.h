//
// Created by Ebi on 2/27/21.
//

#ifndef ARRAY__ITERATOR_H_
#define ARRAY__ITERATOR_H_

namespace Example
{

template<class Type> class Iterator {

 public:
  Iterator(Type *pointer) :
      pointer_(pointer) {}


  Iterator& operator++()
  {
    ++pointer_;
    return *this;
  }

  Iterator operator++(int) 
  {
    auto tmpIt = *this; 
    pointer_++;
    return tmpIt;
  }

  Type& operator*()
  {
    return *pointer_;
  }

  bool operator==(const Iterator &other) 
  {
    return pointer_ == other.pointer_;
  }

  bool operator!=(const Iterator &other) 
  {
    return pointer_ != other.pointer_;
  }

 protected:
  Type* pointer_;
};
}

#endif //ARRAY__ITERATOR_H_
