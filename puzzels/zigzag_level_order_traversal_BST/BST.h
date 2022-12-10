#ifndef ZIGZAG_LEVEL_ORDER_TRAVERSAL_BST__BST_H_
#define ZIGZAG_LEVEL_ORDER_TRAVERSAL_BST__BST_H_

#include <stack>
#include <vector>
#include <algorithm>


using namespace std;

struct Node{
  Node* left;
  Node* right;
  int value;
  Node(int v): value(v), left(nullptr), right(nullptr)
  {
  }
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

  vector<vector<int>> zigzagLevelOrderTraversal()
  {
    stack<vector<Node*>> myStack;
    myStack.push(vector<Node*>({root}));
    vector<vector<int>> res;
    int order =1;

    while(!myStack.empty())
    {
      vector<int> vec;
      vector<Node*> vecNodes;
      for (auto node: myStack.top())
      {
        vec.push_back(node->value);
        if(node->left)
          vecNodes.push_back(node->left);

        if(node->right)
          vecNodes.push_back(node->right);
      }
      myStack.pop();
      if(!vecNodes.empty())
        myStack.push(vecNodes);
      if( order % 2 == 0)
        reverse(vec.begin(), vec.end());
      res.push_back(vec);
      ++order;
    }
    return res;
  }

 private:
  Node* root{nullptr};

};



#endif//ZIGZAG_LEVEL_ORDER_TRAVERSAL_BST__BST_H_
