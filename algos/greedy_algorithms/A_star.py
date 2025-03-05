
import heapq


class Node:
    def __init__(self, neighbors, dis):
        self.neighbors = neighbors
        self.dis = dis
        
class HeapNode:
    def __init__(self, id, cost):
        self.id = id
        self.cost = cost
    
    def __lt__(self, node):
        return self.cost < node.cost
    
    def __bt__(self, node):
        return self.cost > node.cost
    
    def __repr__(self):
        return f"{self.cost}"


def A_star(graph, s, d):
    
    min_heap = []
    heapq.heappush(min_heap, HeapNode(s, 0.0))
    visited = set()
    
    while len(min_heap):
        
        cur_path = heapq.heappop(min_heap)
        cur_node = cur_path.id[-1]
        visited.add(cur_node)
        
        if cur_node == d:
            return cur_path.id, cur_path.cost
        
        for neighbor in graph[cur_node].neighbors:
            if neighbor not in visited:
                new_path = cur_path.id + neighbor
                new_cost = cur_path.cost + graph[cur_node].dis[neighbor]
                heapq.heappush(min_heap, HeapNode(new_path, new_cost))
        
        
    
    
graph = {}
graph['A'] = Node(['D', 'B', 'C'], {'D':2 , 'B':5 , 'C':4})
graph['D'] = Node(['A', 'C'], {'A':2 , 'C':1})
graph['B'] = Node(['A', 'C', 'F'], {'A':5 , 'C':2 , 'F':2})    
graph['C'] = Node(['A', 'B', 'D', 'E', 'F'], {'A':4 , 'B':2 , 'D':1, 'E':1 , 'F':3})
graph['F'] = Node(['E', 'B', 'C'], {'E':2 , 'B':2 , 'C':3})
graph['E'] = Node(['F', 'C'], {'F':2 , 'C':1})

res = A_star(graph, 'A', 'F')
print(res)