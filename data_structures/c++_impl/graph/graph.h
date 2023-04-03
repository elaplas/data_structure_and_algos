//
// Created by z639627 on 3/10/21.
//

#ifndef GRAPH__GRAPH_H_
#define GRAPH__GRAPH_H_

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

struct Node
{
  int ID;
  std::vector<int> adj;
  Node(int id):ID(id){}
};


class Graph{

  void AddNode(int id)
  {
    nodes[id]= Node(id);
  }
  void AddEdge(int idSource, int idDestination)
  {
    nodes.at(idSource).adj.push_back(idDestination);
  }

  /// Breath First Search to see whether two nodes are connected
  bool BFS(int idSource, int idDestination)
  {
    /// to check nodes in FIFO manner
    std::queue<Node> nodesToBeChecked;
    /// to avoid infinite loops
    std::vector<int> visited;
    /// first node to check is source node
    nodesToBeChecked.push(nodes.at(idSource));

    while (!nodesToBeChecked.empty())
    {
      const Node& node = nodesToBeChecked.front();
      if(node.ID == idDestination)
      {
        return true;
      }
      for (size_t i=0; i < node.adj.size(); ++i)
      {
        if(std::find(visited.begin(), visited.end(), node.adj[i] ) == visited.end())
        {
          nodesToBeChecked.push(nodes.at(node.adj[i]));
        }
      }
      visited.push_back(node.ID);
      nodesToBeChecked.pop();
    }
  }

 private:
  std::unordered_map<int, Node> nodes;
};

#endif //GRAPH__GRAPH_H_
