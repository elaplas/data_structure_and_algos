#include <iostream>
#include "array.h"

class B{
  B(int size1):size(size1){}
 protected:
  int size;
};

/// Hint1: a class can access private members through an object of itself!
/// Hint2: a class cannot access private members through the object of another class
class A{
 public:
  A(int size1):size(size1){}

  /// based on Hint1, this will work
  bool isEqual (A& other)
  {
     return size ==other.size;
  }

  /// based on Hint2, the commented function will not work
  /**
   * bool isEqual (B& other)
   * {
   *    return size ==other.size;
   * }
   */


 private:
  int size;
};


template<class Type>
class C{

 public:

  int getSize()
  {
    return size;
  }

 protected:
  int size{10};
  Type data[10];

    };

template<class Type>
class D: public C<Type>{

 public:

  /// Hint: to access member variables and methods of templated base class (parent class)
  /// you should use the following syntax
  int getArraySize()
  {
     return C<Type>::getSize();
  }

  int getData(int i)
  {
    return C<Type>::data[i];
  }
};



int main() {


  /// example 1
  D<float> d;

  std::cout<<d.getArraySize()<<std::endl;
  std::cout<<d.getData(2)<<std::endl;


  /// example 2
  Example::Array<int, 10> A;
  int i=0;
  for (auto it = A.begin(); it !=A.end(); it++ ) {
    *it = i;
    i++;
  }

  for (auto it = A.begin(); (Example::Iterator<int>) it !=A.end(); it++ ) {
    std::cout<<*it<<std::endl;
  }

  return 0;
}
