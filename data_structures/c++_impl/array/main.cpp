#include <iostream>
#include "array.h"


int main() {

  /// example 1
  Example::Array<int, 10> A;
  int i=0;
  for (auto it = A.begin(); it !=A.end(); it++ ) {
    *it = i;
    i++;
  }

  /// accessing through non-const iterator
  for (auto it = A.begin(); (Example::Iterator<int>) it !=A.end(); it++ ) {
    std::cout<<*it<<std::endl;
  }


  /// accessing through const iterator
  const auto& constRef = A;
  for (auto it=constRef.begin(); it != constRef.end(); it++)
  {
     std::cout<<*it<<std::endl;
  }

  return 0;
}
