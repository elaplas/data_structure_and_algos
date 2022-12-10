#ifndef KTH_SMALLEST_NODE_IN_BST__BST_H_
#define KTH_SMALLEST_NODE_IN_BST__BST_H_

#include <stack>
#include <vector>
#include <map>


using namespace std;

struct Node{
    Node* left;
    Node* right;
    bool isLeftVisited;
    bool isRightVisited;
    int value;
    Node(int v): value(v), left(nullptr), right(nullptr),
                  isLeftVisited(false), isRightVisited(false)
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


 void traverse(Node* root, int& res)
 {
   if (!root)
     return;

   if (root->left)
    traverse(root->left, res);

    --k_;

   if(k_ == 0)
   {
     res = root->value;
     return;
   }

   if (root->right)
     traverse(root->right, res);
 }

 int getKthSmallestNodeUsingRecursion(int k)
 {
   k_ = k;
   int res;
   traverse(root, res);
   return res;
 }

 int getKthSmallestNodeUsingStack(int k)
 {
   stack<Node*> myStack;
   myStack.push(root);

   while(!myStack.empty())
   {
     auto& currNode = myStack.top();
     if(currNode->left && !currNode->isLeftVisited)
     {
       myStack.push(currNode->left);
       currNode->isLeftVisited = true;
       continue;
     }
     else
     {
       currNode->isLeftVisited = true;
     }

     if(currNode->isLeftVisited && !currNode->isRightVisited)
      --k;

     if (k == 0)
       return currNode->value;

     if(currNode->right && !currNode->isRightVisited)
     {
       myStack.push(currNode->right);
       currNode->isRightVisited = true;
     }
     else
     {
       currNode->isRightVisited = true;
     }

     if(myStack.top()->isLeftVisited && myStack.top()->isRightVisited)
       myStack.pop();
   }
 }


 private:
  Node* root{nullptr};
  int k_;

};



#endif//KTH_SMALLEST_NODE_IN_BST__BST_H_
