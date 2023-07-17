#include <iostream>
#include "graph.h"

int main() {

 Graph graph;
    std::vector<char> nodes{'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    graph.addNodes(nodes);
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('A', 'D');
    graph.addEdge('B', 'E');
    graph.addEdge('C', 'E');
    graph.addEdge('C', 'F');
    graph.addEdge('E', 'G');
    
    std::cout<<"---------DFS (which is topological sort in acyclic directed graph)----------"<<"\n";
    graph.DFS('A');

    std::cout<<"---------BFS ----------"<<"\n";
    graph.BFS('A');
}
