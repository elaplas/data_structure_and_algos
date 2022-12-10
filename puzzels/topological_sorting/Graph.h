#ifndef TOPOLOGICAL_SORTING_GRAPH_H_
#define TOPOLOGICAL_SORTING_GRAPH_H_

#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;


/**
 *
 * Topological searching can be used to sort dependencies so that the packages with
 * less or no dependencies can be built first and others that depend on them after them.
 * It is also used in scheduling
 *
 * Topological sorting: nodes with less in-order edges (coming edges) appear first
 *
 */


class Graph
{
 public:

  void add_edge(int source, int des)
  {
    data_[source].push_back(des);
  }

  void add_node(int v)
  {
    data_[v] = vector<int>();
  }

  void topological_sort(int v)
  {
    visited_[v] = true;

    auto adjacent_vertices = data_[v];
    for (auto& w: adjacent_vertices)
    {
      if (!visited_[w])
      {
        topological_sort(w);
      }
    }

    stack_.push(v);
  }

  void topological_sort()
  {
    for (auto& v: data_)
    {
      if (!visited_[v.first])
      {
        topological_sort(v.first);
      }
    }

    while(!stack_.empty())
    {
      cout<<stack_.top()<<" ,";
      stack_.pop();
    }
  }

 private:
  unordered_map<int, vector<int>> data_;
  unordered_map<int, bool> visited_;
  stack<int> stack_;

};

#endif//TOPOLOGICAL_SORTING_GRAPH_H_
