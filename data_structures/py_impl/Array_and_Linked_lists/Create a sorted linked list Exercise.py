#!/usr/bin/env python
# coding: utf-8

# ## Create a sorted linked list
# 
# Given a stream of random integers, create a linked list that is always sorted from ascending order (lowest to highest). What's the computational complexity of adding an element in this way?

# In[3]:


# Use this class as the nodes in your linked list
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
    
    def __repr__(self):
        return str(self.value)


# In[10]:


class SortedLinkedList:
    def __init__(self):
        self.head = None
        
    def append(self, value):
        """
        Append a value to the Linked List in ascending sorted order

        Args:
           value(int): Value to add to Linked List
        """
        
        # TODO: Write your sorted append function here
        if self.head is None:
            self.head = Node(value)
            return
        
        if value < self.head.value:
            pre_head = self.head
            self.head = Node(value)
            self.head.next = pre_head
            return
        
        cur_node = self.head
        pre_node = None
        while cur_node:
            if value < cur_node.value:
                new_node = Node(value)
                pre_node.next = new_node
                new_node.next = cur_node
                return
            
            pre_node = cur_node
            cur_node = cur_node.next
            
        pre_node.next = Node(value)
        


# In[11]:


# Test cases
linked_list = SortedLinkedList()
linked_list.append(3)
print ("Pass" if (linked_list.head.value == 3) else "Fail")

linked_list.append(2)
print ("Pass" if (linked_list.head.value == 2) else "Fail")

linked_list.append(4)
node = linked_list.head.next.next
print ("Pass" if (node.value == 4) else "Fail")


# <span class="graffiti-highlight graffiti-id_1lh8zt3-id_jzo0637"><i></i><button>Hide Solution</button></span>

# In[ ]:


# Solution

class SortedLinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, value):
        """
        Append a value to the Linked List in ascending sorted order

        Args:
           value(int): Value to add to Linked List
        """
        if self.head is None:
            self.head = Node(value)
            return
        
        if value < self.head.value:
            node = Node(value)
            node.next = self.head
            self.head = node
            return
        
        node = self.head
        while node.next is not None and value >= node.next.value:
            node = node.next
            
        new_node = Node(value)
        new_node.next = node.next
        node.next = new_node
        
        return None

# Test cases
linked_list = SortedLinkedList()
linked_list.append(3)
print ("Pass" if (linked_list.head.value == 3) else "Fail")

linked_list.append(2)
print ("Pass" if (linked_list.head.value == 2) else "Fail")

linked_list.append(4)
node = linked_list.head.next.next
print ("Pass" if (node.value == 4) else "Fail")


# Computational complexity is $O(N)$ where $N$ is the current length of the linked list.

# ### Additional question: Sort an array with this linked list
# 
# Given an array of integers, use this linked list to sort them and return a sorted array. What's the computational complexity of this sorting algorithm? How does it compare to other sorting algorithms?

# In[16]:


def sort(array):
    """
    Given an array of integers, use SortedLinkedList to sort them and return a sorted array.

    Args:
       array(array): Array of integers to be sorted
    Returns:
       array: Return sorted array
    """
    
    # TODO: Write your sorting function here
    sorted_list = SortedLinkedList()
    for el in array:
        sorted_list.append(el)
        
    node = sorted_list.head
    res = []
    while node:
        res.append(node.value)
        node = node.next
        
    return res


# In[15]:


# Test case
print ("Pass" if (sort([4, 8, 2, 1, -3, 1, 5]) == [-3, 1, 1, 2, 4, 5, 8]) else "Fail")


# <span class="graffiti-highlight graffiti-id_1vhopm0-id_p1rrwsl"><i></i><button>Show Solution</button></span>

# Computational complexity is $O(N^2)$ where N is the length of the integer array. One insert is $O(M)$ where $M$ is the length of the existing linked list. As the list grows, the time complexity of inserting grows. It's something like $1 + 2 + 3 + 4 + \cdots + N$.
# 
# $$
# 1 + 2 + 3 + 4 + \cdots + N = \sum_n^N n = \frac{N(N+1)}{2}
# $$
# 
# Then our time complexity for sorting itself is $O(N^2)$.  Converting from the linked list to an array is $O(N)$. Combined this is $O(N^2 + N) = O(N^2)$. Sorting algorithms such as quicksort and mergesort (which we'll look at later) are $N \log N$, so this algorithm is slower.

# In[ ]:




