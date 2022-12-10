#include <iostream>
#include "vector.h"


using namespace P;




int main() {

  Vector<int> vector1;

  for (int i = 0; i < 25; ++i)
  {
    vector1.push_back(i);
  }

  for (int i = 0; i < 25; ++i)
  {
    std::cout<< vector1[i]<< "\n";
  }

  std::cout<<"............................................"<<std::endl;

  for (auto it = vector1.begin(); it != vector1.end(); it++)
  {
    std::cout<< *it << "\n";
  }


  return 0;
}
