#include <iostream>
#include "Graph.h"


int main() {


  Graph graph;
  graph.add_edge(5, 0);
  graph.add_edge(5, 2);
  graph.add_edge(2, 3);
  graph.add_edge(3, 1);
  graph.add_edge(4, 1);
  graph.add_node(0);
  graph.add_node(1);

  graph.topological_sort();
  return 0;
}
