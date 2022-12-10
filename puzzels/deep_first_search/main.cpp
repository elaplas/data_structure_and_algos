#include <iostream>
#include "graph.h"



int main() {

  Graph graph;

  graph.add_edge(0,1);
  graph.add_edge(0,9);
  graph.add_edge(1,2);
  graph.add_edge(2,0);
  graph.add_edge(2,3);
  graph.add_edge(9,3);

  graph.DFS(2);

  return 0;
}
