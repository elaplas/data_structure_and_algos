#ifndef TWO_SUM_BST__BST_H_
#define TWO_SUM_BST__BST_H_

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
  Node* left;
  Node* right;
  int value;
  Node(int v): value(v), left(nullptr), right(nullptr)
  {}
};

class BST{

 public:

  void insert(int value)
  {
    auto currNode = root;
    while (currNode)
    {
      if (value < currNode->value)
      {
        if(!currNode->left)
        {
          currNode->left = new Node(value);
          break;
        }
        currNode = currNode->left;
      }
      else
      {
        if(!currNode->right)
        {
          currNode->right= new Node(value);
          break;
        }
        currNode = currNode->right;
      }
    }
    if(!root)
    {
      root = new Node(value);
    }
  }

  /**
   * it determines whether the sum of two nodes in the BST is equal to a given number
   * Hint: this function uses O(D) space complexity where D is the depth of tree
   *
   * @param B sum of two nodes
   * @return if true, sum exists in BST
   */
  bool isSumInTree(int B)
  {
    Node* rootLeft = root;
    Node* rootRight = root;
    while(rootLeft)
    {
      leftStack.push(rootLeft);
      rootLeft = rootLeft->left;
    }
    while(rootRight)
    {
      rightStack.push(rootRight);
      rootRight = rootRight->right;
    }

    rootLeft = leftStack.top();
    rootRight = rightStack.top();

    while(rootLeft->value < rootRight->value)
    {
      rootLeft = leftStack.top();
      rootRight = rightStack.top();

      if (rootLeft->value + rootRight->value == B)
        return true;

      if(rootLeft->value + rootRight->value > B)
      {
        if (rootRight->left)
        {
          rootRight = rootRight->left;
          rightStack.pop();
          rightStack.push(rootRight);
          continue;
        }
        else
        {
          rightStack.pop();
          continue;
        }
      }
      if(rootLeft->value + rootRight->value < B)
      {
        if (rootRight->right)
        {
          rootRight = rootRight->right;
          rightStack.pop();
          rightStack.push(rootRight);
          continue;
        }
      }

      if(rootLeft->value + rootRight->value < B)
      {
        if(rootLeft->right)
        {
          rootLeft = rootLeft->right;
          leftStack.pop();
          leftStack.push(rootLeft);
          continue;
        }
        else
        {
          leftStack.pop();
          continue;
        }
      }
      if(rootLeft->value + rootRight->value > B)
      {
        if(rootLeft->left)
        {
          rootLeft = rootLeft->left;
          leftStack.pop();
          leftStack.push(rootLeft);
          continue;
        }
      }
    }
    return false;
  }

  /**
  * it determines whether the sum of two nodes in the BST is equal to a given number
  * Hint1: this function uses O(n) space complexity where n is number of nodes of BST
  * Hint2: the also is based on two pointers
  * @param B sum of two nodes
  */
  bool isSumInTreeUsingTwoPointers(int B)
  {
    vector<int> inorder;
    traverse(root, inorder);
    int smallValueIndex = 0;
    int bigValueIndex = inorder.size() -1;

    while(smallValueIndex < bigValueIndex)
    {
      if (inorder[smallValueIndex] + inorder[bigValueIndex] == B)
        return true;

      if(inorder[smallValueIndex] + inorder[bigValueIndex] < B)
      {
        ++smallValueIndex;
      }

      if(inorder[smallValueIndex] + inorder[bigValueIndex] > B)
      {
        --bigValueIndex;
      }

    }
    return false;
  }

  /**
   *
   * traverse in BST inorder and store values in a vector
   * Hint: vector elements are stored in increasing order
   *
   */
  void traverse(Node* root, vector<int>& inorder)
  {
    if (!root)
      return;

    if (root->left)
      traverse(root->left,inorder );

    inorder.push_back(root->value);

    if (root->right)
      traverse(root->right, inorder);
  }


 private:
  Node* root{nullptr};
  stack<Node*> leftStack;
  stack<Node*> rightStack;

};
#endif//TWO_SUM_BST__BST_H_
