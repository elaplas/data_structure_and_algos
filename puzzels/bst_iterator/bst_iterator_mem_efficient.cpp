
#include <iostream>
#include <stack>
#include <vector>

using namespace std;



/***
 * Implement an iterator over a binary search tree (BST).
 *  Your iterator will be initialized with the root node of a BST.
 *  The first call to iterator will return the smallest number in BST. 
 *  Calling iterator again will return the next smallest number in the BST, and so on.
 * 
 * time complexity: O(1)
 * space complexity: O(h) where h is height of tree
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

        using value_type = int;
        using data_type = Tree*;

        Iterator(data_type& tree): m_tree(tree){}
        Iterator(data_type&& tree): m_tree(tree){}

        Iterator& operator++()
        {
            if (m_tree->hasNext())
            {
                m_tree->next();
            }
            else
            {
                m_tree->push(static_cast<Node*>(nullptr));
            }
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        value_type& operator*()
        {
            if (m_tree->hasNext())
            {
                return m_tree->top()->value;
            }
        }

        bool operator==(const Iterator& other)
        {
            return m_tree->top() == other.m_tree->top();
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this == other);
        }

        private:
        data_type m_tree;

    };

    Tree(Node* root)
    {
        auto curNode = root;
        while(curNode) 
        {
            m_data.push(curNode);
            curNode = curNode->left;
        }
    }


    Iterator begin()
    {
        return Iterator(this);
    }

    
    Iterator end()
    {
        Tree tree(nullptr);
        tree.push(static_cast<Node*>(nullptr));
        return Iterator(&tree);
    }

    bool hasNext()
    {
        return !m_data.empty();
    }

    void push(Node* node)
    {
        m_data.push(node);
    }

    Node* top()
    {
        return m_data.top();
    }

    private:

    Node* next()
    {
        Node* res = nullptr;
        Node* curNode = nullptr;
        if (m_data.size())
        {
            curNode = res = m_data.top();
            m_data.pop();
            if (curNode->right)
            {
                curNode = curNode->right;
                m_data.push(curNode);
                curNode = curNode->left;

                while(curNode){
                    m_data.push(curNode);
                    curNode = curNode->left;
                }
            }
        }

        return res;
    }

    private:

    stack<Node*> m_data;

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