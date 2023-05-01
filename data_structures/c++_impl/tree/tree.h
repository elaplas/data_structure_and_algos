//
// Created by z639627 on 3/9/21.
//

#ifndef TREE_H_
#define TREE_H_

#include <queue>
#include <iostream>

  template<class T>
class Tree
{
    public:
    struct Node{
        T value;
        Node* left;
        Node* right;
    };

    Tree():m_root(nullptr){}

    void add(const T& value)
    {
        if (!m_root)
        {
            m_root = new Node{value, nullptr, nullptr};
        }
        else
        {
            auto curNode = m_root;
            Node* preNode = nullptr;

            while (curNode)
            {
                preNode = curNode;
                if (value < curNode->value )
                {
                    curNode = curNode->left;
                }
                else
                {
                    curNode = curNode->right;
                }
            }

            if (value < preNode->value)
            {
                preNode->left = new Node{value, nullptr, nullptr};
            }
            else
            {
                preNode->right = new Node{value, nullptr, nullptr};
            }
        }
    }

    void erase(int value)
  {
    Node* currNode = m_root;
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
    }
  }

    void DFS()
    {
        DFSRecursive(m_root);
    }

    void BFS()
    {
        std::queue<Node*> que;
        que.push(m_root);

        while(que.size())
        {
            auto front = que.front();
            std::cout<<front->value<<"\n";
            if (front->left)
            {
                que.push(front->left);
            }
            if (front->right)
            {
                que.push(front->right);
            }
            que.pop();
        }
    }

    /**
    * @brief number of edges on the longest path from the root to any leaf
    * 
    * @return int 
    */
    int height()
    {
        return heightRecursive(m_root, 0);
    }

    /**
    * @brief number of edges on the longest path b/w any two leaves
    *        idea: find the height of left part of tree and the right part and return their sum
    * 
    * @return int 
    */
    int diameter()
    {
        return diameterRecursive(m_root, 0);
    }

    private:
    void DFSRecursive(Node* node)
    {
        if (!node)
        return;

        std::cout<<node->value<<"\n";

        DFSRecursive(node->left);
        DFSRecursive(node->right);
    }

    int heightRecursive(Node* node, int curHeight)
    {
        if (!node)
        {
            return curHeight-1;
        }

        auto leftHeight = heightRecursive(node->left, curHeight+1);
        auto rightHeight = heightRecursive(node->right, curHeight+1);

        return std::max(leftHeight, rightHeight);
    }

    int diameterRecursive(Node* node, int curHeight)
    {
        if (!node)
        {
            return curHeight-1;
        }

        auto leftHeight = diameterRecursive(node->left, curHeight+1);
        auto rightHeight = heightRecursive(node->right, curHeight+1);

        if (node == m_root)
        {
            return leftHeight + rightHeight;
        }

        return std::max(leftHeight, rightHeight);
    }

    private:
    Node* m_root;
};
 
#endif //TREE_H_

