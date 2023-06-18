"""
topological sorting: given a directed acyclic graph (DAG) for each edge uv 
from vertex u to vertex v, u comes before v

solution: BFS

inverse of topological sorting: given a directed acyclic graph (DAG) for each edge uv 
from vertex u to vertex v, v comes before u

solution: DFS

"""


class Graph:
    def __init__(self):
        self.nodes = set()
        self.neighbors = {}
        self.incomings = {}
    
    def add_nodes(self, node_list):
        self.nodes.update(node_list)
    
    def add_edge(self, s, d):
        
        if s in self.neighbors:
            self.neighbors[s].append(d)
        else:
            self.neighbors[s] = [d]


def topological_sort(G):

    que = []
    start_node = ""

    # Find start node: it is a node that doesn't own any neighbors 
    for node in G.nodes:
        has_no_neighbor = True

        for node_i in G.neighbors:
            neighbors = G.neighbors[node_i]
            for neighbor in neighbors:
                if neighbor == node:
                    has_no_neighbor = False
                    break
        
        if has_no_neighbor:
            start_node = node
            break
    
    que.append(start_node)
    visited = set()
    res = []

    while len(que):

        popped_node = que.pop(0)
        if popped_node not in visited:
            res.append(popped_node)
        visited.add(popped_node)

        if popped_node in G.neighbors:
            neighbors = G.neighbors[popped_node]
            for neighbor in neighbors:
                que.append(neighbor)
    
    return res


def inverse_topological_sort(G):

    # Find start node: it is a node that doesn't own any neighbors 
    for node in G.nodes:
        has_no_neighbor = True  
        for node_i in G.neighbors:
            neighbors = G.neighbors[node_i]
            for neighbor in neighbors:
                if neighbor == node:
                    has_no_neighbor = False
                    break
                
        if has_no_neighbor:
            start_node = node
            break

    res = []
    visited = set()
    DFS(G, visited, start_node, res)
    return res


def DFS(G, visited, node, res):

    if node in G.neighbors:
        neighbors = G.neighbors[node]
        for neighbor in neighbors:
            if neighbor not in visited:
                DFS(G, visited, neighbor, res)
    
    if node not in visited:
        res.append(node)
        visited.add(node)

############## test ################

graph = Graph()
graph.add_nodes(["A", "B", "C", "D", "E", "F", "G"])
graph.add_edge("A", "B")
graph.add_edge("A", "C")
graph.add_edge("A", "D")
graph.add_edge("B", "E")
graph.add_edge("C", "E")
graph.add_edge("C", "F")
graph.add_edge("D", "F")
graph.add_edge("E", "G")
graph.add_edge("F", "G")

res = topological_sort(graph)
print(res)

res = inverse_topological_sort(graph)
print(res)

