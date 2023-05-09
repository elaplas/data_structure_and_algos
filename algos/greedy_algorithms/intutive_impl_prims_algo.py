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


class MinHeap:
    def __init__(self):
        self.data = [None for _ in range(100)]
        self.next = 0

    def push(self, node):
        self.data[self.next] = node
        self.heapify_up()
        self.next +=1
        

    def pop(self):
        if not self.next :
            return None
        tmp = self.data[0]
        self.data[0] = self.data[self.next-1]
        self.data[self.next-1] = None
        self.heapify_down()
        self.next -= 1
        return tmp

    def heapify_up(self):
        cur_child = self.next
        while cur_child:
            cur_parent = (cur_child -1)//2
            if self.data[cur_child].cost < self.data[cur_parent].cost:
                tmp = self.data[cur_parent]
                self.data[cur_parent] = self.data[cur_child]
                self.data[cur_child] = tmp
                cur_child = cur_parent
            else:
                break

    def heapify_down(self):
        cur_parent = 0
        while cur_parent*2+2 < self.next-1:
            left_child = (cur_parent*2)+1
            right_child = (cur_parent*2)+2
            cur_child = left_child
            if self.data[right_child].cost < self.data[left_child].cost:
                cur_child = right_child
            if self.data[cur_child].cost < self.data[cur_parent].cost:
                tmp = self.data[cur_parent]
                self.data[cur_parent] = self.data[cur_child]
                self.data[cur_child] = tmp
                cur_parent = cur_child
            else:
                break

    def size(self):
        return self.next
        
    

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


def prims_algo(graph):
    """Returns a path with the smallest possible cost that connects all node
    """
    min_heap = MinHeap()
    min_heap.push(Node('A', 0))
    visited = set()
    result = ["", 0]

    while min_heap.size():

        popped_node = min_heap.pop()

        if popped_node.value not in visited:
            result[0] += popped_node.value
            result[1] += popped_node.cost

        visited.add(popped_node.value)

        if popped_node.value in graph.edges:
            neighbors = graph.edges[popped_node.value]
            for neighbor in neighbors:
                if neighbor.value not in visited:
                    min_heap.push(neighbor)

    return result


res = prims_algo(graph)
print(res)
