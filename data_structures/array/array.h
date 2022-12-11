//
// Created by Ebi on 2/27/21.
//

#ifndef ARRAY__ARRAY_H_
#define ARRAY__ARRAY_H_

#include "iterator.h"

namespace Example{


template<class Type, int MAX_SIZE>
class Array {

  typedef class Iterator<Type> FieldIterator;
  typedef const Type ConstType;
  typedef class Iterator<ConstType> ConstFieldIterator;
 public:

  Array():
  size(MAX_SIZE),
  ptr(0){}

  int getSize()
  {
    return size;
  }

  int resize(int newSize)
  {
    size = newSize;
    return size;
  }

  Type& operator[](int index)
  {
    return data[index];
  }

  const Type& operator[](int index) const
  {
    return data[index];
  }

  const Type& push_back(const Type& element)
  {
    data[ptr]=element;
    int prePtr = ptr;
    ptr = (ptr+1)%MAX_SIZE;
    return data[prePtr];
  }

  FieldIterator begin()
  {
    return FieldIterator(data);
  }

  FieldIterator end()
  {
    return FieldIterator(&data[size]);
  }

   ConstFieldIterator begin() const
  {
    return ConstFieldIterator(data);
  }

  ConstFieldIterator end() const
  {
    return ConstFieldIterator(&data[size]);
  }

 private:
  Type data[MAX_SIZE];
  int size;
  int ptr;

};

}

#endif //ARRAY__ARRAY_H_
