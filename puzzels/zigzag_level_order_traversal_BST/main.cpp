#include <iostream>
#include "BST.h"

int main() {

  BST bst;

  bst.insert(3);
  bst.insert(2);
  bst.insert(20);
  bst.insert(15);
  bst.insert(22);
  bst.insert(14);
  bst.insert(17);
  bst.insert(21);
  bst.insert(25);

  auto res = bst.zigzagLevelOrderTraversal();

  return 0;
}
