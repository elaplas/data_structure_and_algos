
#include <iostream>

using namespace std;



/**
 * Given a binary tree A, flatten it to a linked list in-place. The left child of all nodes should be NULL. 
 * 
 * Input:
 *
 *        1
 *       / \
 *      2   5
 *     / \   \
 *    3   4   6
 *
 * Output:
 *
 *              1
 *               \
 *                2
 *                 \
 *                  3
 *                   \
 *                    4
 *                     \
 *                      5
 *                       \
 *                        6
 *              
 *
 * 
 */



struct Node{

    int value;
    Node* left;
    Node* right;

    Node(int val):value(val), left(nullptr), right(nullptr){}
};


void DFS(Node* node)
{
    if (!node)
    {
        return;
    }

    if (node->left)
    {
        DFS(node->left);
    }

    if (node->right)
    {
        DFS(node->right);
    }

    auto tmp = node->right;
    node->right = node->left;
    auto curNode = node->left;
    node->left = nullptr;
    if (curNode)
    {
        while (curNode->right)
        {
            curNode = curNode->right;
        }
        curNode->right = tmp;
    }
}

Node* flattenInPlace(Node* root)
{
    DFS(root);
    return root;
}   



int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    auto flattenTree = flattenInPlace(root);

    auto curNode = flattenTree;
    while (curNode)
    {
        cout<< curNode->value<<"\n";
        curNode = curNode->right;
    }

}