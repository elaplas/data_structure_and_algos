#include <iostream>
#include <queue>
#include <list>
#include "LRU_catch.h"

using namespace std;

int main() {

  LRU rlu(2);
  cout<<rlu.get(2)<<"\n";
  rlu.insert(2,6);
  cout<<rlu.get(1)<<"\n";
  rlu.insert(1,5);
  rlu.insert(1,2);
  cout<<rlu.get(1)<<"\n";
  cout<<rlu.get(2)<<"\n";


  std::cout << "Hello, World!" << std::endl;
  return 0;
}
