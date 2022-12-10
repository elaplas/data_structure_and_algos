#ifndef DEEP_FIRST_SEARCH_GRAPH_H_
#define DEEP_FIRST_SEARCH_GRAPH_H_

#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{

 public:
  void add_edge(int source, int des)
  {
    data_[source].push_back(des);
  }

  void DFS(int v)
  {
    visited_[v] = true;

    cout<<v<<", ";

    auto& adjacent_vertices = data_[v];
    for (auto& w: adjacent_vertices)
    {
      if(!visited_[w])
      {
        DFS(w);
      }
    }
  }

 private:
  unordered_map<int, vector<int>> data_;
  unordered_map<int, bool> visited_;


};



#endif//DEEP_FIRST_SEARCH_GRAPH_H_
