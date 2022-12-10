#include <iostream>
#include <vector>
#include "dynamic_tree.h"




int main() {
  DynamicTree mytree;

  std::vector<int> vec{3,6,1,9,2,10,11,4};

  for (int i=0; i<vec.size(); ++i)
  {
    mytree.insert(vec[i]);
  }

  std::cout <<"res: "<< mytree.FindClosestPoint(4)<< std::endl;
  std::cout <<"res: "<< mytree.FindClosestPoint1(4)<< std::endl;
  std::cout << "depth: "<<mytree.FindDepth()<< std::endl;
  std::cout << "depth: "<<mytree.FindDepthRecursive()<< std::endl;
  return 0;
}
