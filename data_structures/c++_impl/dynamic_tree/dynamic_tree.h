//
// Created by z639627 on 3/9/21.
//

#ifndef DYNAMIC_TREE__DYNAMIC_TREE_H_
#define DYNAMIC_TREE__DYNAMIC_TREE_H_

#include<queue>
#include<map>

using namespace std;


struct Node {

  int value{0};
  Node* left{nullptr};
  Node* right{nullptr};

  Node(int data):value(data){}
};

class DynamicTree
{
 public:

  void insert(int data)
  {
    Node* currentRoot;
    currentRoot= root;

    while (currentRoot != nullptr)
    {
      if(data <= currentRoot->value)
      {
        if(currentRoot->left == nullptr)
        {
          currentRoot->left = new Node(data);
          break;
        }
        currentRoot=currentRoot->left;
      }
      else
      {
        if(currentRoot->right == nullptr)
        {
          currentRoot->right = new Node(data);
          break;
        }
        currentRoot = currentRoot->right;
      }
    }
    if(root== nullptr)
    {
      root = new Node(data);
    }
  }

  /// non-recursive
  int FindDepth()
  {
    if (!root)
      return 0;

    queue<pair<Node*, int>> NodeToProcess;
    NodeToProcess.push(pair<Node*, int>(root, 1));
    int depth = 0;
    while(!NodeToProcess.empty())
    {
      if (NodeToProcess.front().first->left)
        NodeToProcess.push(pair<Node*, int>(NodeToProcess.front().first->left, NodeToProcess.front().second + 1));
      if (NodeToProcess.front().first->right)
        NodeToProcess.push(pair<Node*, int>(NodeToProcess.front().first->right, NodeToProcess.front().second + 1));

      depth = max(depth, NodeToProcess.front().second );
      NodeToProcess.pop();
    }
    return depth;
  }

  /// recursive
  int FindDepthRecursive()
  {
    FindDepthRecursive(root);
  }

  int FindDepthRecursive(Node* r)
  {
    if (!r)
      return 0;

    int leftDepth = FindDepthRecursive(r->left);
    int rightDepth = FindDepthRecursive(r->right);

    if (leftDepth > rightDepth)
      return ++leftDepth;
    else
      return ++rightDepth;
  }

  /// needs the BST to be balanced
  int FindClosestPoint(int data)
  {
    int res = -1;

    Node* currentRoot = root;

    while (currentRoot != nullptr)
    {
      if(res!=-1 && std::abs(res-data) < std::abs(currentRoot->value-data))
      {
        break;
      }
      res = currentRoot->value;

      if(data <= currentRoot->value)
      {
        currentRoot=currentRoot->left;
      }
      else
      {
        currentRoot = currentRoot->right;
      }
    }
    return res;
  }

  void DeleteNode(int value)
  {
    Node* currNode = root;
    Node* preNode = nullptr;

    while (currNode)
    {
      preNode = currNode;

      if(currNode->value == value)
      {
        /// if node doesn't have any children
        if(!currNode->left && !currNode->right)
        {
          if(preNode)
          {
            if(currNode->value <= preNode->value)
              preNode->left = nullptr;
            else
              preNode->right= nullptr;
          }
          delete currNode;
        }
        /// if node has one child
        if( currNode->left && !currNode->right || !currNode->left && currNode->right)
        {
          if(preNode)
          {
            if(currNode->value <= preNode->value)
              if(currNode->left)
               preNode->left = currNode->left;
              else
                preNode->left = currNode->right;
            else
            if(currNode->left)
              preNode->right = currNode->left;
            else
              preNode->right = currNode->right;

            delete currNode;
          }
          /// if node has two children
          if(currNode->left && currNode->right)
          {
            /// find inorder successor
            Node* tmp = currNode->right;
            Node* preTmp = nullptr;
            while (tmp)
            {
              preTmp = tmp;
              tmp = tmp->left;
            }
            currNode->value = tmp->value;
            preTmp->left = nullptr;
            delete tmp;
          }
        }
      }

      if(currNode->value <= value)
      {
        currNode = currNode->left;
      }
      else
      {
        currNode = currNode->right;
      }

    }
  }

  /// the BST doesn't need to be balanced
  int FindClosestPoint1(int data)
  {
    int res = -1;

    Node* currentRoot = root;

    while (currentRoot)
    {
      res = currentRoot->value;

      if(data <= currentRoot->value)
      {
        currentRoot=currentRoot->left;
      }
      else
      {
        currentRoot = currentRoot->right;
      }

      if (currentRoot)
      {
        if (abs(currentRoot->value - data) < abs(res-data))
        {
          res = currentRoot->value;
        }
      }
    }
    return res;
  }

 private:
  Node* root{nullptr};

};

#endif //DYNAMIC_TREE__DYNAMIC_TREE_H_
