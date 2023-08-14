#include <iostream>
#include "graph.h"

int main() {

 Graph graph;
    std::vector<char> nodes{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'S', 'M', 'N', 'L'};
    graph.addNodes(nodes);
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('A', 'D');
    graph.addEdge('B', 'E');
    graph.addEdge('C', 'E');
    graph.addEdge('C', 'F');
    graph.addEdge('E', 'G');

    graph.addEdge('S', 'N');
    graph.addEdge('S', 'M');
    graph.addEdge('N', 'L');
    graph.addEdge('M', 'L');
    
    std::cout<<"---------DFS (which is topological sort in acyclic directed graph)----------"<<"\n";
    graph.DFS('A');

    std::cout<<"---------BFS ----------"<<"\n";
    graph.BFS('A');

    /**
     * An acyclic directed graph and DFS can be used to find the building order if the neighboring nodes of a node represent
     * the build dependencies of that node 
     * 
     */
    std::cout<<"---------dependency build orders----------"<<"\n";
    for (auto node1: nodes)
    {
        bool hasNoNeighbor = true;
        for (auto node2: nodes)
        {
            if (node1 != node2)
            {
                if (graph.m_neighbors.find(node2) != graph.m_neighbors.end())
                {
                    auto neighbors = graph.m_neighbors[node2];
                    for (auto neighbor: neighbors)
                    {
                        if (neighbor == node1)
                        {
                            hasNoNeighbor = false;
                        }
                    }
                }
            }
        }
        if (hasNoNeighbor)
        {
            std::cout<<"---------start----------"<<"\n";
            graph.DFS(node1);
            std::cout<<"---------end----------"<<"\n";
        }
    }
}
