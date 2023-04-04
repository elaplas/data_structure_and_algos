#!/usr/bin/env python
# coding: utf-8

# # Reversing a linked list exercise
# 
# Given a singly linked list, return another linked list that is the reverse of the first.

# In[1]:


# Helper Code

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        
    def append(self, value):
        if self.head is None:
            self.head = Node(value)
            return
        
        node = self.head
        while node.next:
            node = node.next

        node.next = Node(value)
        
    def __iter__(self):
        node = self.head
        while node:
            yield node.value
            node = node.next
            
    def __repr__(self):
        return str([v for v in self])


# ### Write the function definition here

# In[6]:


def reverse(linked_list):
    """
    Reverse the inputted linked list

    Args:
       linked_list(obj): Linked List to be reversed
    Returns:
       obj: Reveresed Linked List
    """
    
    # TODO: Write your function to reverse linked lists here
    node_list = [node for node in linked_list]
    new_liked_list = LinkedList()
    for i in range(len(node_list)):
        new_liked_list.append(node_list[len(node_list)-1-i])
    return new_liked_list


# ### Let's test your function

# In[9]:


llist = LinkedList()
for value in [4,2,5,1,-3,0]:
    llist.append(value)

flipped = reverse(llist)
is_correct = list(flipped) == list([0,-3,1,5,2,4]) and list(llist) == list(reverse(flipped))
print("Pass" if is_correct else "Fail")


# <span class="graffiti-highlight graffiti-id_0gw081c-id_dmb7r0h"><i></i><button>Hide Solution</button></span>

# In[10]:


# Solution

# Time complexity O(N)
def reverse(linked_list):
    """
    Reverse the inputted linked list

    Args:
       linked_list(obj): Linked List to be reversed
    Returns:
       obj: Reveresed Linked List
    """
    new_list = LinkedList()
    
    prev_node = None

    """
    A simple idea - Pick a node from the original linked list traversing form the beginning, and 
    prepend it to the new linked list. 
    We have to use a loop to iterate over the nodes of original linked list
    """
    # In this "for" loop, the "value" is just a variable whose value will be updated in each iteration
    for value in linked_list:
        # create a new node
        new_node = Node(value)
        
        # Make the new_node.next point to the 
        # node created in previous iteration
        new_node.next = prev_node 
        
        # This is the last statement of the loop
        # Mark the current new node as the "prev_node" for next iteration
        prev_node = new_node
    
    # Update the new_list.head to point to the final node that came out of the loop
    new_list.head = prev_node
    
    return new_list


# In[ ]:




