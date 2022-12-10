#include <iostream>
#include "BST.h"

int main() {

  BST bst;

  bst.insert(3);
  bst.insert(2);
  bst.insert(1);
  bst.insert(5);
  bst.insert(8);
  bst.insert(11);
  bst.insert(8.5);

  std::cout << bst.isSumInTree(10.5) << std::endl;
  std::cout << bst.isSumInTree(13) << std::endl;
  std::cout << bst.isSumInTree(19) << std::endl;
  std::cout << bst.isSumInTree(19.5) << std::endl;
  std::cout << bst.isSumInTree(15) << std::endl;
  std::cout << bst.isSumInTree(20) << std::endl;

  std::cout <<"................................."<<"\n";

  std::cout << bst.isSumInTreeUsingTwoPointers(10.5) << std::endl;
  std::cout << bst.isSumInTreeUsingTwoPointers(13) << std::endl;
  std::cout << bst.isSumInTreeUsingTwoPointers(19) << std::endl;
  std::cout << bst.isSumInTreeUsingTwoPointers(19.5) << std::endl;
  std::cout << bst.isSumInTreeUsingTwoPointers(15) << std::endl;
  std::cout << bst.isSumInTreeUsingTwoPointers(20) << std::endl;

  return 0;
}
