#!/usr/bin/env python
# coding: utf-8

# # Connect Islands using Prim’s Algorithm
# ### A. Problem Statements
# 
# In an ocean, there are `n` islands some of which are connected via bridges. Travelling over a bridge has some cost attaced with it. Find bridges in such a way that all islands are connected with minimum cost of travelling. 
# 
# You can assume that there is at least one possible way in which all islands are connected with each other. 
# 
# You will be provided with two input parameters:
#     
# 1. `num_islands` = number of islands
#     
# 2. `bridge_config` = list of lists. 
#     Each inner list will have 3 elements:
#         a. island A
#         b. island B
#         c. cost of bridge connecting both islands
#                        
#     Each island is represented using a number
#      
# **Example:**                       
# * `num_islands = 4`
# * `bridge_config = [[1, 2, 1], [2, 3, 4], [1, 4, 3], [4, 3, 2], [1, 3, 10]]`
#        
# Input parameters explanation:
#     1. Number of islands = 4
#     2. Island 1 and 2 are connected via a bridge with cost = 1
#        Island 2 and 3 are connected via a bridge with cost = 4
#        Island 1 and 4 are connected via a bridge with cost = 3
#        Island 4 and 3 are connected via a bridge with cost = 2
#        Island 1 and 3 are connected via a bridge with cost = 10
#        
# In this example if we are connecting bridges like this...
# * between 1 and 2 with cost = 1
# * between 1 and 4 with cost = 3
# * between 4 and 3 with cost = 2  
# 
# ...then we connect all 4 islands with `cost = 6` which is the minimum traveling cost.
# 

# ### B. Hint: Use a Priority Queue or Min-Heap
# 
# In addition to using a graph, you may want to use a custom priority queue for solving this problem. If you do not want to create a custom priority queue, you can use Python's inbuilt `heapq` implementation.
# 
# Using the `heapq` module, you can convert an existing list of items into a min-heap. The following two functionalities can be very handy for this problem:
# 
# 1. `heappush(heap, item)` — add `item` to the `heap`
# 2. `heappop(heap)` — remove the smallest item from the `heap`
# 
# Let's look at the above methods in action. We start by creating a list of integers.

# ### `heappush`

# In[1]:


import heapq

# initialize an empty list 
minHeap = list()

# insert 5 into heap
heapq.heappush(minHeap, 6)

# insert 6 into heap
heapq.heappush(minHeap, 6)

# insert 2 into heap
heapq.heappush(minHeap, 2)

# insert 1 into heap
heapq.heappush(minHeap, 1)

# insert 9 into heap
heapq.heappush(minHeap, 9)

print("After pushing, heap looks like: {}".format(minHeap))


# ### `heappop`

# In[2]:


# pop and return smallest element from the heap
smallest = heapq.heappop(minHeap)   

print("Smallest element in the original list was: {}".format(smallest))

print("After popping, heap looks like: {}".format(minHeap))


# ### `heappush` and `heappop` for items with multiple entries
# 
# Note: If you insert a tuple inside the heap, the element at 0th index of the tuple is used for comparision
# 

# In[3]:


minHeap = list()

heapq.heappush(minHeap, (0, 1))

heapq.heappush(minHeap, (-1, 5))

heapq.heappush(minHeap, (2, 0))

heapq.heappush(minHeap, (5, -1))

print("After pushing, now heap looks like: {}".format(minHeap))


# In[4]:


# pop and return smallest element from the heap
smallest = heapq.heappop(minHeap)   

print("Smallest element in the original list was: {}".format(smallest))

print("After popping, heap looks like: {}".format(minHeap))


# Now that you know about `heapq`, you can use it to solve the given problem. You are also free to create your own implementatin of Priority Queues.
# 
# ### C. The Idea, based on Prim’s Algorithm:
# Our objective is to find the minimum `total_cost` to visit all the islands. We will start with any one island, and follow a Greedy approach. <br>
# **Step 1 -  Create a Graph**
# 1. Create a graph with given number of islands, and the cost between each pair of islands. A graph can be represented as a adjacency_matrix, which is a list of lists. For example, given:<br>
# ```
# num_islands = 4
# bridge_config = [[1, 2, 1], [2, 3, 4], [1, 4, 3], [4, 3, 2], [1, 3, 10]]
# ```
# <br> The graph would look like:
# ```
# graph =  [[], [(2, 1), (4, 3), (3, 10)], [(1, 1), (3, 4)], [(2, 4), (4, 2), (1, 10)], [(1, 3), (3, 2)]]
# ```
# where, a sublist at $i^{th}$ index represents the adjacency_list of $i^{th}$ island. A tuple within a sublist is `(neighbor, edge_cost)`. <br>
# 
# **Step 2 - Traverse the graph in a Greedy way.** <br>  
# 1. Create a blank `minHeap`, and push any one island (vertex) into it.  
# 1. While there are elements remaining in the `minHeap`, do the following:
#  - Pop out an island having smallest edge_cost, and reduce the heap size. You can use `heapq.heappop()` for this purpose. 
#  - If the current island has not been visited before, add the `edge_cost` to the `total_cost`. You can use a list of booleans to keep track of the visited islands.  
#  - Find out all the neighbours of the current island from the given `graph`. Push each neighbour of the current island into the `minHeap`. You can use `heapq.heappush()` for this purpose. 
#  - Mark current island as visited
#  tuple in the adjacency_list of the 
# 
# 1. When we have popped out all the elements from the `minHeap`, we will have the minimum `total_cost` to visit all the islands.
# 
# ### D. Exercise - Write the function definition here 
# Write code in the following function to find and return the minimum cost required to travel all islands via bridges.

# In[48]:


def make_graph(num_islands, bridge_config):
    
    matrix_adj = [[] for i in range(num_islands+1)]
    
    for el in bridge_config:
        matrix_adj[el[0]].append((el[1], el[2]))
        matrix_adj[el[1]].append((el[0], el[2]))
        
        
    return matrix_adj
    
    


def get_minimum_cost_of_connecting(num_islands, bridge_config):
    """
    :param: num_islands - number of islands
    :param: bridge_config - bridge configuration as explained in the problem statement
    return: cost (int) minimum cost of connecting all islands
    TODO complete this method to returh minimum cost of connecting all islands
    """
    visited = [False for i in range(num_islands+1)]
    matrix_adj = make_graph(num_islands, bridge_config)
    min_heap = []
    for el in matrix_adj[1]:
        heapq.heappush(min_heap, (el[1], el[0]))
    visited[1] = True
    
    min_cost = 0
    while len(min_heap):
        cur_node = heapq.heappop(min_heap)
        if not visited[cur_node[1]]:
            visited[cur_node[1]] = True
            min_cost += cur_node[0]
            for el in matrix_adj[cur_node[1]]:
                if not visited[el[0]]:
                    heapq.heappush(min_heap, (el[1], el[0]))
                    
    return min_cost
            
        
    


# <span class="graffiti-highlight graffiti-id_07rfocu-id_sgw589w"><i></i><button>Show Solution</button></span>

# In[44]:


def test_function(test_case):
    num_islands = test_case[0]
    bridge_config = test_case[1]
    solution = test_case[2]
    output = get_minimum_cost_of_connecting(num_islands, bridge_config)
    
    print(output)
    
    if output == solution:
        print("Pass")
    else:
        print("Fail")


# In[45]:


num_islands = 4
bridge_config = [[1, 2, 1], [2, 3, 4], [1, 4, 3], [4, 3, 2], [1, 3, 10]]
solution = 6

test_case = [num_islands, bridge_config, solution]
test_function(test_case)


# In[46]:


num_islands = 5
bridge_config = [[1, 2, 5], [1, 3, 8], [2, 3, 9]]
solution = 13

test_case = [num_islands, bridge_config, solution]
test_function(test_case)


# In[47]:


num_islands = 5
bridge_config = [[1, 2, 3], [1, 5, 9], [2, 3, 10], [4, 3, 9]]
solution = 31

test_case = [num_islands, bridge_config, solution]
test_function(test_case)


# In[ ]:




