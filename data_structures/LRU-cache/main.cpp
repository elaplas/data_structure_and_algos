#include <iostream>
#include <queue>
#include <list>
#include "LRU_cache.h"

using namespace std;

int main() {

  LRU<int, float> rlu(4);
  // Insert some elements
  rlu.insert(1, 1.5);
  rlu.insert(2, 2.5);
  rlu.insert(3, 3.5);
  rlu.insert(4, 4.5);
  // Get some elements
  rlu.get(1);
  rlu.get(2);
  // Insert some elements
  rlu.insert(5, 5.5);
  rlu.insert(6, 6.5);

  // The recently least used elements should be removed from RLU-cache
  for(auto& el: rlu)
  {
    cout<<"( "<<el.first<<", "<<el.second.first<<")"<<std::endl;
  }

  return 0;
}
