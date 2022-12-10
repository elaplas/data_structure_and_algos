#include <iostream>

using namespace std;

struct Node{

  int val;
  Node* left;
  Node* right;
};

int maxPath(Node* root, int& res)
{

  if (!root)
    return 0;

  int l = maxPath(root->left, res);
  int r = maxPath(root->right, res);

  int max_one_node = max( max(l+root->val, r + root->val), root->val);
  int max_top = max(max_one_node, l+r+root->val);

  res = max(res, max_top);

  return max_one_node;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
