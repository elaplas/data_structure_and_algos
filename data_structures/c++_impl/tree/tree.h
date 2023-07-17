
#pragma
#include <queue>
#include <iostream>


template<class T>
class Tree{

    public:
    struct Node{
        Node* left;
        Node* right;
        T value;

        Node(const T& val):value(val), left(nullptr), right(nullptr)
        {}
    };

    Tree():m_root(nullptr){}

    void add(const T& val)
    {
        if (!m_root)
        {
            m_root = new Node(val);
        }
        else
        {
            auto curNode = m_root;
            while(curNode)
            {
                if (val < curNode->value)
                {
                    if (curNode->left)
                    {
                        curNode=curNode->left;
                    }
                    else
                    {
                        curNode->left=new Node(val);
                        break;
                    }
                }
                else
                {
                    if (curNode->right)
                    {
                        curNode = curNode->right;
                    }
                    else
                    {
                        curNode->right = new Node(val);
                        break;
                    }
                }
            }    
        }
    }

    int depth()
    {
       return depthHelper(m_root, 0);
    }

    int diameter()
    {
        auto leftDepth = depthHelper(m_root->left, 1);
        auto rightDepth = depthHelper(m_root->right, 1);
        return leftDepth + rightDepth;
    }

    int depthHelper(Node* node, int numEdge)
    {
        if (!node)
        {
            return numEdge;
        }

        auto numEdgeLeft = numEdge;
        auto numEdgeRight = numEdge;
        if (node->left)
        {
            numEdgeLeft = depthHelper(node->left, numEdge+1);
        }

        if (node->right)
        {
            numEdgeRight = depthHelper(node->right, numEdge+1);
        }

        return std::max(numEdgeLeft, numEdgeRight);
    }

    void DFS()
    {
        DFSHelper(m_root);
    }

    void BFS()
    {
        BFSHelper(m_root);
    }

    void DFSHelper(Node* node)
    {
        if (!node)
        {
            return;
        }

        if (node->left)
        {
            DFSHelper(node->left);
        }

        if (node->right)
        {
            DFSHelper(node->right);
        }

        std::cout<<node->value<<"\n";
    }

    void BFSHelper(Node* node)
    {
        std::queue<Node*> que;
        que.push(node);

        while(!que.empty())
        {
            auto poppedNode = que.front(); 
            que.pop();
            if (poppedNode->left)
            {
                que.push(poppedNode->left);
            }

            if (poppedNode->right)
            {
                que.push(poppedNode->right);
            }

            std::cout<<poppedNode->value<<"\n";
        }
    }

    void preOreder()
    {
        preOrderHelper(m_root);
    }

    void inOreder()
    {
        inOrderHelper(m_root);
    }

    void postOreder()
    {
        postOrderHelper(m_root);
    }

    void preOrderHelper(Node* node)
    {
        if (!node)
        {
            return;
        }

        std::cout<<node->value<<"\n";

        if (node->left)
        {
            preOrderHelper(node->left);
        }

        if (node->right)
        {
            preOrderHelper(node->right);
        }
    }

    void inOrderHelper(Node* node)
    {
        if (!node)
        {
            return;
        }

        if (node->left)
        {
            inOrderHelper(node->left);
        }

        std::cout<<node->value<<"\n";

        if (node->right)
        {
            inOrderHelper(node->right);
        }
    }

    void postOrderHelper(Node* node)
    {
        if (!node)
        {
            return;
        }

        if (node->left)
        {
            postOrderHelper(node->left);
        }

        if (node->right)
        {
            postOrderHelper(node->right);
        }

        std::cout<<node->value<<"\n";
    }

    private:
    Node* m_root;

};