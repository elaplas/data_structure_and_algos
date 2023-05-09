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


def paths_with_cost(graph, source, destination):
    """Returns all possible paths from source to destinations with the respective costs
    """

    result=[]
    paths = []
    paths.append((source, 0))

    while len(paths):

        popped_node = paths.pop(0)

        if popped_node[0][-1] == destination:
            result.append(popped_node)
        else:
            if popped_node[0][-1] in graph.edges:
                neighbors = graph.edges[popped_node[0][-1]]
                for neighbor in neighbors:
                    if neighbor.value not in popped_node[0]:
                        new_path = popped_node[0] + neighbor.value
                        new_cost = popped_node[1] + neighbor.cost
                        paths.append((new_path, new_cost))

    return result


res = paths_with_cost(graph, 'F', 'A')
print(res)
