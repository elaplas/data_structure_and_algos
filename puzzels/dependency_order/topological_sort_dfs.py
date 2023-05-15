

"""
 * we have the following dependencies, write a function to return the right order of building
 *
 * A depends on B and C
 * B depends on D
 * C depends on D
 * D depends on nothing
 *
 * the building orders could be D->C->B->A or D->B->C->A
 *
 * elegant solution:
 * make a graph from dependencies and
 * perform topological sorting,
 *
 * why we need topological sorting ?
 * because after topological sorting, it is possible to find
 * the right order (building/dependency order) in a graph configurations with any configurations
 *
"""

# given a DAG (directed acyclic graph), find an order where for each edge uv, v comes before u (reverse order of topological sort)

class Graph:
    def __init__(self):
        self.incomings = {}
        self.outgoings = {}
        self.nodes = set()

    def add_nodes(self, list_nodes):
        self.nodes.update(list_nodes)
    
    def add_edge(self, s, d):

        if s in self.outgoings:
            self.outgoings[s].append(d)
        else:
            self.outgoings[s] = [d]

        if d in self.incomings:
            self.incomings[d].append(s)
        else:
            self.incomings[d] = [s]


def find_dependency_order_dfs(graph):

    start_nodes = set()
    for node in graph.nodes:
        if node not in graph.incomings:
            start_nodes.add(node)

    visited = set()
    result = []
    while len(start_nodes):
        popped_node = start_nodes.pop()
        dfs_helper(graph, visited, popped_node, result)
    
    return result


def dfs_helper(graph, visited, node, result):

    if node in graph.outgoings:
        neighbors = graph.outgoings[node]
        for neighbor in neighbors:
            if neighbor not in visited:
                dfs_helper(graph, visited, neighbor, result)
    
    result.append(node)
    visited.add(node)


# Test 1
graph  = Graph()
graph.add_nodes(['A', 'B', 'C', 'D'])
graph.add_edge('A', 'B')
graph.add_edge('A', 'C')
graph.add_edge('B', 'D')
graph.add_edge('C', 'D')
res = find_dependency_order_dfs(graph)
print(res)


# Test 2
graph  = Graph()
graph.add_nodes(['A', 'B', 'C', 'D', 'E', 'F', 'G'])
graph.add_edge('A', 'B')
graph.add_edge('A', 'C')
graph.add_edge('A', 'D')
graph.add_edge('B', 'E')
graph.add_edge('C', 'E')
graph.add_edge('C', 'F')
graph.add_edge('D', 'F')
graph.add_edge('E', 'G')
res = find_dependency_order_dfs(graph)
print(res)


# Test 3
graph  = Graph()
graph.add_nodes(['A', 'B', 'C', 'D', 'E', 'F', 'G'])
graph.add_edge('G', 'E')
graph.add_edge('E', 'B')
graph.add_edge('E', 'C')
graph.add_edge('B', 'A')
graph.add_edge('C', 'A')
graph.add_edge('F', 'D')
graph.add_edge('D', 'A')
res = find_dependency_order_dfs(graph)
print(res)

        
