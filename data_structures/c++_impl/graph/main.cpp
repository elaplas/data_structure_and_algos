#include <iostream>
#include "graph.h"
#include "graph_x.h"

int main() {

  std::cout<<"...........Graph.........."<<"\n";
  Graph<char, int>::Node nodeA{'A', {}, {}};
  Graph<char, int>::Node nodeB{'B', {}, {}};
  Graph<char, int>::Node nodeC{'C', {}, {}};
  Graph<char, int>::Node nodeD{'D', {}, {}};
  Graph<char, int>::Node nodeE{'E', {}, {}};
  Graph<char, int>::Node nodeF{'F', {}, {}};
  Graph<char, int>::Node nodeG{'G', {}, {}};
  Graph<char, int> graph;
  graph.add_edge(&nodeA, &nodeB, 1);
  graph.add_edge(&nodeA, &nodeC, 1);
  graph.add_edge(&nodeA, &nodeD, 1);
  graph.add_edge(&nodeB, &nodeE, 1);
  graph.add_edge(&nodeC, &nodeE, 1);
  graph.add_edge(&nodeC, &nodeF, 1);
  graph.add_edge(&nodeD, &nodeF, 1);
  graph.add_edge(&nodeE, &nodeG, 1);
  std::cout<<"...........DFS.........."<<"\n";
  graph.DFS(&nodeA);
  std::cout<<"...........BFS.........."<<"\n";
  graph.BFS(&nodeA);

  std::cout<<"...........GraphX.........."<<"\n";

  GraphX<char, int> graphX;
  graphX.add_edge('A', 'B', 1);
  graphX.add_edge('A', 'C', 1);
  graphX.add_edge('A', 'D', 1);
  graphX.add_edge('B', 'E', 1);
  graphX.add_edge('C', 'E', 1);
  graphX.add_edge('C', 'F', 1);
  graphX.add_edge('D', 'F', 1);
  graphX.add_edge('E', 'G', 1);
  std::cout<<"...........DFS.........."<<"\n";
  graphX.DFS('A');
  std::cout<<"...........BFS.........."<<"\n";
  graphX.BFS('A');


}
