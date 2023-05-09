class Node:
    def __init__(self, val = None, c=None):
        self.value = val
        self.cost = c


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = {}
    
    def add_nodes(self, vals):
        self.nodes.update(vals)

    def add_edge(self, s, d, cost):

        if s not in self.edges:
            self.edges[s] = [Node(d, cost)]
        else:
            self.edges[s].append(Node(d, cost))

        if d not in self.edges:
            self.edges[d] = [Node(s, cost)]
        else:
            self.edges[d].append(Node(s, cost))


def dijkstras(graph: Graph, source: str):
    
    result = dict.fromkeys(graph.nodes, float('inf'))
    unvisited = set(graph.nodes)
    result[source] = 0
    path = dict.fromkeys(graph.nodes, 'A')

    while len(unvisited):

        min_node = None

        for node in result:

            if node in unvisited:
                if not min_node:
                    min_node = node
                else:
                    if result[node] < result[min_node]:
                        min_node = node

        neighbors = graph.edges[min_node]
        for neighbor in neighbors:
            cur_cost = result[min_node] + neighbor.cost
            if cur_cost < result[neighbor.value]:
                result[neighbor.value] = cur_cost
                path[neighbor.value] = min_node

        unvisited.remove(min_node)

    return result, path

graph = Graph()
graph.add_nodes(['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'])
graph.add_edge('A', 'B', 2)
graph.add_edge('A', 'C', 4)
graph.add_edge('A', 'D', 1)
graph.add_edge('B', 'E', 2)
graph.add_edge('C', 'G', 1)
graph.add_edge('C', 'F', 1)
graph.add_edge('D', 'F', 1)
graph.add_edge('E', 'G', 2)
graph.add_edge('G', 'H', 3)
graph.add_edge('H', 'F', 2)

res = dijkstras(graph, 'A')
print(res[0])
print(res[1])
