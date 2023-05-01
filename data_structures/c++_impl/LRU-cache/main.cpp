#include <iostream>
#include "LRU_cache.h"

using namespace std;

int main() {

  LRUCache<int, int> cache(3);

  cache.set(1, 10);
  cache.set(2, 20);
  cache.set(3, 30);
  cache.read(1);
  cache.read(3);
  cache.set(4, 40);
  
  for (auto& el: cache)
  {
   std::cout<<"key: "<<el.first<<", value: "<<el.second<<"\n";
  }

  return 0;
}
