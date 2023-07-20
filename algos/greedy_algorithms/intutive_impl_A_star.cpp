
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>


struct Node
{
    std::string path;
    float distance;

    Node(): Node("", 0.f){}
    Node(const std::string& p, float d): path(p), distance(d){}
};

class Graph{

    public:
    void addNodes(const std::vector<char>& vec)
    {
        for (auto node: vec)
        {
            m_nodes.insert(node);
        }
    }

    void addEdge(char s, char d, float distance)
    {
        if (m_neighbors.find(s) == m_neighbors.end())
        {
            m_neighbors[s] = std::vector<char>{d};
        }
        else
        {
            m_neighbors[s].push_back(d);
        }

        if (m_neighbors.find(d) == m_neighbors.end())
        {
            m_neighbors[d] = std::vector<char>{s};
        }
        else
        {
            m_neighbors[d].push_back(s);
        }

        std::string id1(std::string(1, s) + std::string(1, d));
        std::string id2(std::string(1, d) + std::string(1, s));
        m_distances[id1] = distance;
        m_distances[id2] = distance;
    }

    std::unordered_map<char, std::vector<char>>& getNeighbors() {return m_neighbors;}
    std::unordered_map<std::string, float>& getDistances(){return m_distances;} 

    private:
    std::unordered_map<char, std::vector<char>> m_neighbors;
    std::unordered_map<std::string, float> m_distances;
    std::set<char> m_nodes;
};

class Compare
{
    public:
    bool operator()(const Node& node1, const Node& node2)
    {
        return node1.distance > node2.distance;
    }
};

std::string AStar(Graph& graph, char s, char d)
{
    std::priority_queue<Node, std::vector<Node>, Compare> minHeap;
    minHeap.push(Node(std::string(1, s), 0.f));
    std::set<char> visited;
    std::string res("");

    while(!minHeap.empty())
    {
        auto poppedNode = minHeap.top();
        minHeap.pop();
        auto poppedId = poppedNode.path[poppedNode.path.size()-1];
        visited.insert(poppedId);
        if (poppedId == d)
        {
            res = poppedNode.path;
            break;
        }
        if (graph.getNeighbors().find(poppedId) != graph.getNeighbors().end())
        {
            auto& neighbors = graph.getNeighbors()[poppedId];
            for (auto neighbor: neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    std::string disId(std::string(1, poppedId)+std::string(1, neighbor));

                    if (graph.getDistances().find(disId) != graph.getDistances().end())
                    {
                        auto dis = graph.getDistances()[disId];
                        std::string newPathName = poppedNode.path + std::string(1, neighbor);
                        float newPathDis = poppedNode.distance + dis;
                        minHeap.push(Node(newPathName, newPathDis));

                    }
                }
            }
        } 
    }
    return res;   
}



int main()
{
    Graph graph;
    std::vector<char> nodes{'A', 'B', 'C', 'D', 'M', 'S', 'D', 'L', 'F'};
    graph.addNodes(nodes);
    graph.addEdge('A', 'B', 2);
    graph.addEdge('B', 'C', 4);
    graph.addEdge('C', 'D', 6);
    graph.addEdge('A', 'M', 2);
    graph.addEdge('M', 'S', 4);
    graph.addEdge('S', 'D', 5);
    graph.addEdge('A', 'L', 2);
    graph.addEdge('L', 'M', 3);
    graph.addEdge('M', 'F', 5);
    graph.addEdge('F', 'D', 1);
   
   auto res = AStar(graph, 'A', 'D');
   std::cout<<res<<"\n";
}