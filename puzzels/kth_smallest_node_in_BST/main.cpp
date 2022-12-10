#include <iostream>
#include "BST.h"

int main() {

  BST bst;

  bst.insert(2);
  bst.insert(8);
  bst.insert(5);
  bst.insert(3);
  bst.insert(1);
  bst.insert(4);
  bst.insert(7);


  std::cout << bst.getKthSmallestNodeUsingRecursion(3) << std::endl;
  std::cout << bst.getKthSmallestNodeUsingStack(3) << std::endl;

  return 0;
}
