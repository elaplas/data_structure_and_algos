#!/usr/bin/env python
# coding: utf-8

# ## Traverse a tree (breadth first search)
# 
# We'll now practice implementing breadth first search (BFS).  You'll see breadth first search again when we learn about graph data structures, so BFS is very useful to know.

# ## Creating a sample tree
# 
# We'll create a tree that looks like the following:

# ![tree image](images/tree_01.png "Tree")

# In[8]:


# this code makes the tree that we'll traverse

class Node(object):
        
    def __init__(self,value = None):
        self.value = value
        self.left = None
        self.right = None
    
    # set value of the node
    def set_value(self,value):
        self.value = value
    
    # get value of the node
    def get_value(self):
        return self.value
    
    # set a node for the left child
    def set_left_child(self,left):
        self.left = left
    
    # set a node for the right child
    def set_right_child(self, right):
        self.right = right
        
    # get the node of left child
    def get_left_child(self):
        return self.left
    
    # get the node of right child
    def get_right_child(self):
        return self.right

    # check if node has left child -> return boolean
    def has_left_child(self):
        return self.left != None
    
    # check if node has right child -> return boolean
    def has_right_child(self):
        return self.right != None
    
    # define __repr_ to decide what a print statement displays for a Node object
    def __repr__(self):
        return f"Node({self.get_value()})"
    
    def __str__(self):
        return f"Node({self.get_value()})"
    
    
class Tree():
    def __init__(self, value=None):
        self.root = Node(value)
        
    def get_root(self):
        return self.root

tree = Tree("apple")
tree.get_root().set_left_child(Node("banana"))
tree.get_root().set_right_child(Node("cherry"))
tree.get_root().get_left_child().set_left_child(Node("dates"))


# ## Breadth first search
# Breadth first traversal of the tree would visit the nodes in this order:  
# 
# ![tree image](images/tree_01.png "Tree")
# 
# apple, banana, cherry, dates

# #### Think through the algorithm
# 
# We are walking down the tree one level at a time. So we start with apple at the root, and next are banana and cherry, and next is dates.
# 
# 
# 1) start at the root node  
# 2) visit the root node's left child (banana), then right child (cherry)  
# 3) visit the left and right children of (banana) and (cherry).
# 
# ## Queue
# 
# Notice that we're waiting until we visit "cherry" before visiting "dates".  It's like they're waiting in line.  We can use a queue to keep track of the order. 
# 
# Python's `collections` module has a specialized `deque` datatype (ref: [deque datatype documentation](https://docs.python.org/3/library/collections.html#collections.deque)). We can append a new element to the right of the list with `append` method and to the left of the list with `appendleft`. To remove and return the right element of the list, we can use `pop` method.

# ## Define a queue class

# In[9]:


# import deque datatype from collections module
from collections import deque
# instantiate a deque object
q = deque()
# add 2 elements to the left of the deque
q.appendleft("apple")
q.appendleft("banana")
print(q)


# In[3]:


# remove and return the most right element of the list
q.pop()


# In[4]:


print(q)


# In[5]:


len(q)


# In[10]:


from collections import deque
class Queue():
    def __init__(self):
        self.q = deque()
        
    def enq(self,value):
        self.q.appendleft(value)
        
    def deq(self):
        if len(self.q) > 0:
            return self.q.pop()
        else:
            return None
    
    def __len__(self):
        return len(self.q)
    
    def __repr__(self):
        if len(self.q) > 0:
            s = "<enqueue here>\n_________________\n" 
            s += "\n_________________\n".join([str(item) for item in self.q])
            s += "\n_________________\n<dequeue here>"
            return s
        else:
            return "<queue is empty>"


# In[11]:


q = Queue()
q.enq("apple")
q.enq("banana")
q.enq("cherry")
print(q)


# In[12]:


print(q.deq())


# In[13]:


print(q)


# ## Walk through the steps with code
# 
# We're going to translate what we're doing by hand into code, one step at a time.  This will help us check if our code is doing what we expect it to do.
# 
# ![tree image](images/tree_01.png "Tree")

# In[ ]:


visit_order = list()
q = Queue()

# start at the root node and add it to the queue
node = tree.get_root()
q.enq(node)
print(q)


# In[ ]:


# dequeue the next node in the queue. 
# "visit" that node
# also add its children to the queue

node = q.deq()
visit_order.append(node)
if node.has_left_child():
    q.enq(node.get_left_child())
if node.has_right_child():
    q.enq(node.get_right_child())
    
print(f"visit order: {visit_order}")
print(q)


# In[ ]:


# dequeue the next node (banana)
# visit it, and add its children (dates) to the queue 

node = q.deq()
visit_order.append(node)
if node.has_left_child():
    q.enq(node.get_left_child())
if node.has_right_child():
    q.enq(node.get_right_child())
    
print(f"visit order: {visit_order}")
print(q)


# In[ ]:


# dequeue the next node (cherry)
# visit it, and add its children (there are None) to the queue 

node = q.deq()
visit_order.append(node)
if node.has_left_child():
    q.enq(node.get_left_child())
if node.has_right_child():
    q.enq(node.get_right_child())
    
print(f"visit order: {visit_order}")
print(q)


# In[ ]:


# dequeue the next node (dates)
# visit it, and add its children (there are None) to the queue 

node = q.deq()
visit_order.append(node)
if node.has_left_child():
    q.enq(node.get_left_child())
if node.has_right_child():
    q.enq(node.get_right_child())
    
print(f"visit order: {visit_order}")
print(q)


# ## Task: write the breadth first search algorithm

# In[16]:


# BFS algorithm
def bfs(tree):
    
    node = tree.get_root()
    que = Queue()
    que.enq(node)
    
    while len(que):
        pre_size = len(que)
        for i in range(pre_size):
            node = que.deq()
            print(node.get_value())
            if node.has_left_child():
                que.enq(node.get_left_child())
            if node.has_right_child():
                que.enq(node.get_right_child())


# In[17]:


# check solution: should be: apple, banana, cherry, dates
bfs(tree)


# ## Bonus Task: write a print function
# 
# Define the print function for the Tree class.  Nodes on the same level are printed on the same line. 
# 
# For example, the tree we've been using would print out like this:
# ```
# Node(apple)
# Node(banana) | Node(cherry)
# Node(dates) | <empty> | <empty> | <empty>
# <empty> | <empty>
# ```
# We'll have `<empty>` be placeholders so that we can keep track of which node is a child or parent of the other nodes.
# 
# **hint**: use a variable to keep track of which level each node is on.  For instance, the root node is on level 0, and its child nodes are on level 1.

# In[48]:


# starter code

class Tree():
    def __init__(self, value=None):
        self.root = Node(value)
        
    def get_root(self):
        return self.root
    
    """
    define the print function
    """
    def __repr__(self):
        node = self.get_root()
        que = Queue()
        que.enq(node)
        s =""
        while len(que):
            pre_size = len(que)
            for i in range(pre_size):
                node = que.deq()
                if i == pre_size-1:
                    s +=  node.get_value()
                else:
                    s += ( node.get_value() + "|")
                if node.has_left_child():
                    que.enq(node.get_left_child())
                else:
                    if node.get_value() != "empty":
                        que.enq(Node("empty"))
                if node.has_right_child():
                    que.enq(node.get_right_child())
                else:
                    if node.get_value() != "empty":
                        que.enq(Node("empty"))
            s += "\n"
        return s


# In[49]:


# check solution
tree = Tree("apple")
tree.get_root().set_left_child(Node("banana"))
tree.get_root().set_right_child(Node("cherry"))
tree.get_root().get_left_child().set_left_child(Node("dates"))
print(tree)


# ## Solution notebook
# The solution notebook is [here](03_traverse_a_tree_bfs_solution.ipynb)

# In[ ]:




