#ifndef GRAPH_X__H_
#define GRAPH_X__H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>

template<class TId, class TCost>
class GraphX{

    public:

     using TNeighbor = std::pair<TId, TCost>;

    void add_node(TId nodeId)
    {
        m_nodes.insert(nodeId);
    }

    void add_edge(const TId& s, const TId& d, const TCost& cost)
    {
        m_edges[s].push_back(TNeighbor(d, cost));
        m_edges[d].push_back(TNeighbor(s, cost));
    }

    void DFS(const TId& node)
    {
        std::set<TId> visited;
        DFSRecursive(node, visited);
    }

    void BFS(const TId& node)
    {
        std::queue<TId> que;
        std::set<TId> visited;
        que.push(node);
        visited.insert(node);

        while (que.size())
        {
            auto curNode = que.front();
            std::cout<< "node: " <<curNode<<std::endl;

            if (m_edges.find(curNode) != m_edges.end())
            {
                for (auto& neighbor: m_edges[curNode])
                {
                    if (visited.find(neighbor.first) == visited.end())
                    {
                        visited.insert(neighbor.first);
                        que.push(neighbor.first);
                    }
                }
            }

            que.pop();
        }
    }

    private:

    void DFSRecursive(const TId& node, std::set<TId>& visited)
    {
        std::cout<< "node: " <<node<<"\n";

        visited.insert(node);

        if (m_edges.find(node) == m_edges.end())
        {
            return;
        }

        for (auto& neighbor: m_edges[node])
        {
            if (visited.find(neighbor.first) == visited.end())
            {
                DFSRecursive(neighbor.first, visited);
            }
        }  
    }

    private:

    std::set<TId> m_nodes;
    std::unordered_map<TId, std::vector<TNeighbor>> m_edges;
};

#endif //GRAPH_X__H_
