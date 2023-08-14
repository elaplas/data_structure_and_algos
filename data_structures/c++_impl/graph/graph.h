#ifndef GRAPH__H_
#define GRAPH__H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>

class Graph
{

    public:

    void addNodes(const std::vector<char>& nodes)
    {
        for (auto nd: nodes)
        {
            m_nodes.insert(nd);
        }
    }

    void addEdge(char s, char d)
    {
        if (m_neighbors.find(s) != m_neighbors.end())
        {
            m_neighbors[s].push_back(d);
        }
        else
        {
            m_neighbors[s] = std::vector<char>{d};
        }
    }

    void DFS(char s)
    {
        std::set<char> visited;
        DFSHelper(s, visited);
    }

    void DFSHelper(char node, std::set<char>& visited)
    {
        visited.insert(node);
        if (m_neighbors.find(node) != m_neighbors.end())
        {
            auto neighbors = m_neighbors[node];
            for (auto neighbor: neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    DFSHelper(neighbor, visited);
                }
            }
        }
        std::cout<<node<<"\n";
    }

    void BFS(char s)
    {
        std::set<char> visited;
        BFSHelper(s, visited);
    }

    void BFSHelper(char node, std::set<char>& visited)
    {
        std::queue<char> que;
        que.push(node);

        while(!que.empty())
        {
            auto poppedNode = que.front();
            que.pop();
            std::cout<<poppedNode<<"\n";
            if (m_neighbors.find(poppedNode) != m_neighbors.end())
            {
                auto neighbors = m_neighbors[poppedNode];
                for (auto neighbor: neighbors)
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        que.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
    }

    std::unordered_map<char, std::vector<char>> m_neighbors;
    std::set<char> m_nodes;
};


#endif //GRAPH__H_
