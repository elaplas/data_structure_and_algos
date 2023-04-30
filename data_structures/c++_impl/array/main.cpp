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
  for (auto it = A.begin(); it !=A.end(); it++ ) {
    std::cout<<*it<<std::endl;
  }


  /// accessing through const iterator
  const auto& constRef = A;
  for (auto it=constRef.begin(); it != constRef.end(); it++)
  {
    std::cout<<*it<<std::endl;
  }

  
  // Creates two iterator objects once at the beginning and deletes them at the end 
  // it calls pre-increment operator so range based-for loop preferred
  for(auto& a: A)
  {
    std::cout<<a<<"\n";
  }

  std::cout<<"................"<<"\n";

  // Creates and deletes multiple iterator objects (because it switches b/w different scopes) 
  // it calls pre-increment operator (not preferred)
  for (auto it = A.begin(); it != A.end(); ++it)
  {
    std::cout<<*it<<"\n";
  }

  std::cout<<"................"<<"\n";

  // Creates and deletes multiple iterator objects (because it switches b/w different scopes) 
  // it calls post-increment operator (not preferred)
  for (auto it = A.begin(); it != A.end(); it++)
  {
    std::cout<<*it<<"\n";
  }


  return 0;
}
