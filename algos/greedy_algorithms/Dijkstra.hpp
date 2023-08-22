
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class Graph{

    public:

    void add_nodes(const vector<char>& nodes)
    {
        for (auto node: nodes)
        {
            m_nodes.insert(node);
        }
    }

    void add_edge(char s, char d, int dis)
    {
        if (m_neighbors.find(s) == m_neighbors.end())
        {
            m_neighbors[s] = vector<char>() = {d};
        }
        else
        {
            m_neighbors[s].push_back(d);
        }

        if (m_neighbors.find(d) == m_neighbors.end())
        {
            m_neighbors[d] = vector<char>() = {s};
        }
        else
        {
            m_neighbors[d].push_back(s);
        }

        string strS(1, s);
        string strD(1, d);
        m_distances[strS+strD] = dis;
        m_distances[strD+strS] = dis;
    }



    set<char> m_nodes;
    unordered_map<char, vector<char>> m_neighbors;
    unordered_map<string, int> m_distances;
};


unordered_map<char, int> DikstraAlgo(Graph& graph, char s)
{
    unordered_map<char, int> result;
    for (auto node: graph.m_nodes)
    {
        result[node] = 10000;
    }
    set<char> unvisited(graph.m_nodes);
    result[s] = 0;

    while (!unvisited.empty())
    {
        char curNode = *unvisited.begin();
        int curMin = result[curNode];

        for (auto el: result)
        {
            if (el.second < curMin && unvisited.find(el.first) != unvisited.end())
            {
                curMin = el.second;
                curNode = el.first;
            }
        }

        auto& neighbors = graph.m_neighbors[curNode];
        for (auto neighbor: neighbors)
        {
            string str1(1, neighbor);
            string str2(1, curNode);
            auto curDis = graph.m_distances[str2+str1] + result[curNode];
            if (curDis < result[neighbor] )
            {
                result[neighbor] = curDis;
            }
        }

        unvisited.erase(curNode);
    }

    return result;
}




int main()
{
    Graph graph;
    graph.add_nodes(vector<char>() = {'A', 'B', 'C', 'D', 'E', 'F', 'G'});
    graph.add_edge('A', 'C', 2);
    graph.add_edge('A', 'D', 1);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('C', 'F', 4);
    graph.add_edge('D', 'G', 1);
    graph.add_edge('B', 'G', 2);
    graph.add_edge('G', 'F', 2);
    graph.add_edge('F', 'E', 1);

    auto res = DikstraAlgo(graph, 'A');
    for (auto el: res)
    {
        cout<<el.first<<" : "<<el.second<<"\n";
    }
    
    return 0;
}