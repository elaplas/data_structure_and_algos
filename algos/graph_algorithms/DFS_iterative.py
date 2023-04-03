#!/usr/bin/env python
# coding: utf-8

# # Graph Depth First Search
# In this exercise, you'll see how to do a depth first search on a graph. To start, let's create a graph class in Python.

# In[1]:


class GraphNode(object):
    def __init__(self, val):
        self.value = val
        self.children = []
        
    def add_child(self,new_node):
        self.children.append(new_node)
    
    def remove_child(self,del_node):
        if del_node in self.children:
            self.children.remove(del_node)

class Graph(object):
    def __init__(self,node_list):
        self.nodes = node_list
        
    def add_edge(self,node1,node2):
        if(node1 in self.nodes and node2 in self.nodes):
            node1.add_child(node2)
            node2.add_child(node1)
            
    def remove_edge(self,node1,node2):
        if(node1 in self.nodes and node2 in self.nodes):
            node1.remove_child(node2)
            node2.remove_child(node1)


# Now let's create the graph.

# In[2]:


nodeG = GraphNode('G')
nodeR = GraphNode('R')
nodeA = GraphNode('A')
nodeP = GraphNode('P')
nodeH = GraphNode('H')
nodeS = GraphNode('S')

graph1 = Graph([nodeS,nodeH,nodeG,nodeP,nodeR,nodeA] ) 
graph1.add_edge(nodeG,nodeR)
graph1.add_edge(nodeA,nodeR)
graph1.add_edge(nodeA,nodeG)
graph1.add_edge(nodeR,nodeP)
graph1.add_edge(nodeH,nodeG)
graph1.add_edge(nodeH,nodeP)
graph1.add_edge(nodeS,nodeR)


# ## Implement DFS
# Using what you know about DFS for trees, apply this to graphs. Implement the `dfs_search` to return the `GraphNode` with the value `search_value` starting at the `root_node`.

# In[11]:



class Stack:
    def __init__(self):
        self.data = []
    
    def push(self, element):
        self.data.append(element)
        
    def pop(self):
        if not self.size():
            return None
        last_element = self.data[-1]
        self.data.pop()
        return last_element
        
    def size(self):
        return len(self.data)


def dfs_search(root_node, search_value):
    
    cur_node = root_node
    node_stack = Stack()
    visited = set()
    node_stack.push(root_node)
    visited.add(root_node)
    
    while node_stack.size():
        
        # If search value found, return cuurent node
        if cur_node.value == search_value:
            return cur_node
        
        # Continue traversing the graph to find an unvisited node
        unvisited_child_found = False
        for child in cur_node.children:
            if child not in visited:
                unvisited_child_found = True
                cur_node = child
                node_stack.push(child)
                visited.add(child)
                break
                
        # If any unvisited notes not found using current node, 
        # try to find an unviisted node using
        # the last elment in the node stack     
        if not unvisited_child_found:
            cur_node = node_stack.pop()
            
                
    
    
    


# <span class="graffiti-highlight graffiti-id_flg9zjy-id_4sn6eaw"><i></i><button>Hide Solution</button></span>

# In[ ]:


# Solution                
def dfs_search(root_node, search_value):
    visited = set()                         # Sets are faster for lookups
    stack = [root_node]                     # Start with a given root node
    
    while len(stack) > 0:                   # Repeat until the stack is empty
            
        current_node = stack.pop()          # Pop out a node added recently 
        visited.add(current_node)           # Mark it as visited

        if current_node.value == search_value:
            return current_node

        # Check all the neighbours
        for child in current_node.children:

            # If a node hasn't been visited before, and not available in the stack already.
            if (child not in visited) and (child not in stack):         
                stack.append(child)
                


# ### Tests

# In[17]:


assert nodeA == dfs_search(nodeS, 'A')
print("expected result: A, ", f"result: {nodeA.value}")
assert nodeS == dfs_search(nodeP, 'S')
print("expected result: S, ", f"result: {nodeS.value}")
assert nodeR == dfs_search(nodeH, 'R')
print("expected result: R, ", f"result: {nodeR.value}")


# In[ ]:




