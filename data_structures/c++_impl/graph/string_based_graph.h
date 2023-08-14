#pragma

#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

/***
 * the relations among people or any other objects, which could be seen as a map data structure can 
 * be represented using a list of strings where each string contains the neighbors/edges/relations to 
 * other nodes. The nodes are represented by the indices. 
 * 
 * 
*/

class Graph{
public:

    void DFS(int node, set<int>& visited, vector<int>& path)
    {
        DFSHelper(node, visited, path);
    }

    void DFSHelper(int node, set<int>& visited, vector<int>& path)
    {
        if (visited.find(node) != visited.end())
        {
            return;
        }

        visited.insert(node);

        vector<int> neighbors;
        auto& row =  m_neighbors[node];
        for (int i =0; i < row.size(); ++i)
        {
            if (row[i] == '1')
            {
                neighbors.push_back(i);
            }
        }

        for (auto neighbor: neighbors)
        {
            DFSHelper(neighbor, visited, path);
        }

        path.push_back(node);
    }


set<int> m_nodes;
vector<string> m_neighbors;

};

int main()
{
    /**
     * Find the number of groups, the people that are related to each other, in the following list of string 
     * where each string represents the relations of a person to other persons. The position of the string in 
     * the vector and strings is representing the person id. 1s are the edges/relations to one another and 
     * zeros mean that there are no relation. 
     */
    vector<string> relations = { 
        "0110000",
        "1011000",
        "1101000",
        "0110000",
        "0000010",
        "0000101",
        "0000010"
    };

    Graph graph;
    graph.m_neighbors = relations;
    graph.m_nodes = {0,1,2,3,4,5,6};

    vector<vector<int>> groups;
    set<int> visited;

    for( auto node: graph.m_nodes)
    {  
        if (visited.find(node) == visited.end())
        {
            vector<int> newGroup;
            graph.DFS(node, visited, newGroup);
            groups.push_back(newGroup);
        }
    }

    cout<<"num of groups: "<<groups.size()<<"\n";

    for (auto group: groups)
    {
        cout<<"group: "<<"\n";
        for (auto el: group)
        {
            cout<<el<<", ";
        }
        cout<<"\n";
    }
   
    return 0;
}