//
// Created by z639627 on 3/10/21.
//

#ifndef GRAPH__H_
#define GRAPH__H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>

template<class TId, class TCost>
class Graph{

    public:
    struct Node{
        TId id;
        std::vector<Node*> children;
        std::unordered_map<TId, TCost> costs;
    };


    void add_edge(Node* s, Node* d, TCost cost)
    {
        s->children.push_back(d);
        s->costs[d->id] = cost;
        d->children.push_back(s);
        d->costs[s->id] = cost;
    }

    void DFS(Node* node)
    {
        std::set<TId> visited;
        DFSRecursive(node, visited);
    }

    void BFS(Node* node)
    {
        std::queue<Node*> que;
        que.push(node);
        std::set<TId> visited;
        visited.insert(node->id);


        while (que.size())
        {
            auto curNode = que.front();
            std::cout<< "node: " <<curNode->id<<"\n";

            for (auto neighbor: curNode->children)
            {
                if (visited.find(neighbor->id) == visited.end())
                {
                    visited.insert(neighbor->id);
                    que.push(neighbor);
                }
            }

            que.pop();
        }
    }

    private:

    void DFSRecursive(Node* node, std::set<TId>& visited)
    {
        std::cout<< "node: " <<node->id<<"\n";
        visited.insert(node->id);
        if (!node->children.size())
        {
            return;
        }

        for (auto neighbor: node->children)
        {
            if (visited.find(neighbor->id) == visited.end()) 
            {
                DFSRecursive(neighbor, visited);
            }
        }
    }
};


#endif //GRAPH__H_
