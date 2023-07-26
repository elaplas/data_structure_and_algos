
#include <iostream>
#include <queue>
#include <vector>

using namespace std;



/***
 * Implement an iterator over a binary search tree (BST).
 *  Your iterator will be initialized with the root node of a BST.
 *  The first call to iterator will return the smallest number in BST. 
 *  Calling iterator again will return the next smallest number in the BST, and so on.
 * 
 * time complexity: O(1)
 * space complexity: O(n) where n is the number of nodes
 * 
 * 
*/


class Tree
{
    public:

    struct Node{

    int value;
    Node* left;
    Node* right;

    Node(int val):value(val), left(nullptr), right(nullptr){}
    };

    class Iterator
    {
        public:

        using iterator_type = int;
        using data_type = queue<Node*>*;

        Iterator(data_type& que): m_data(que){}
        Iterator(data_type&& que): m_data(que){}

        Iterator& operator++()
        {
            if (!m_data->empty())
            {
                m_data->pop();
            }
            else
            {
                m_data->push(nullptr);
            }
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator_type& operator*()
        {
            if (!m_data->empty())
            {
                return m_data->front()->value;
            }
        }

        bool operator==(const Iterator& other)
        {
            return m_data->front() == other.m_data->front();
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this == other);
        }

        private:
        data_type m_data;

    };

    Tree(Node* root)
    {
        DFS(root, m_data);
    }


    Iterator begin()
    {
        return Iterator(&m_data);
    }

    
    Iterator end()
    {
        queue<Node*> que;
        que.push(static_cast<Node*>(nullptr));
        return Iterator(&que);
    }

    private:

    void DFS(Node* node, queue<Node*>& que)
    {
        if (!node)
        {
            return;
        }

        if (node->left)
        {
            DFS(node->left, que);
        }

        que.push(node);

        if (node->right)
        {
            DFS(node->right, que);
        }
    }

    private:

    queue<Node*> m_data;

};


int main()
{
    Tree::Node* root = new Tree::Node(8);
    root->left = new Tree::Node(6);
    root->right = new Tree::Node(10);
    root->left->left = new Tree::Node(4);
    root->left->right = new Tree::Node(7);
    root->right->left = new Tree::Node(9);
    root->right->right = new Tree::Node(12);
    Tree tree(root);

    for (auto node: tree)
    {
        cout<<node<<"\n";
    }
  
}