#include <iostream>
#include <unordered_map>
#include "unordered_map.h"


using namespace P;


int main() {

  unordered_map<float, float> myMap;

  myMap[4] = 10.5;
  myMap[6] = 9.5;

  myMap[2] = 8.5;
  myMap[2.5] = 6.5;

  for(auto el: myMap)
  {
    std::cout<<el.first<<std::endl;
    std::cout<<el.second<<std::endl;
    // The following commented line shouldn't fail
    //el.first = 5;
  }

  std::cout<<"..............................."<<std::endl;

  const auto& yourMap = myMap;
  for(const auto& el: yourMap)
  {
    std::cout<<el.first<<std::endl;
    std::cout<<el.second<<std::endl;
    // The following commented line should fail
    //el.first = 5;
  }

  return 0;
}
