#!/usr/bin/env python
# coding: utf-8

# # Reversed Queue
# Write a function that takes a queue as an input and returns a reversed version of it. 

# In[4]:


class LinkedListNode:

    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:

    def __init__(self):
        self.num_elements = 0
        self.head = None

    def push(self, data):
        new_node = LinkedListNode(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.num_elements += 1

    def pop(self):
        if self.is_empty():
            return None
        temp = self.head.data
        self.head = self.head.next
        self.num_elements -= 1
        return temp

    def top(self):
        if self.head is None:
            return None
        return self.head.data

    def size(self):
        return self.num_elements

    def is_empty(self):
        return self.num_elements == 0


        
class Queue:

    def __init__(self):
        self.head = None
        self.tail = None
        self.num_elements = 0

    def enqueue(self, data):
        new_node = LinkedListNode(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.num_elements += 1

    def dequeue(self):
        if self.is_empty():
            return None
        temp = self.head.data
        self.head = self.head.next
        self.num_elements -= 1
        return temp

    def front(self):
        if self.head is None:
            return None
        return self.head.data

    def size(self):
        return self.num_elements

    def is_empty(self):
        return self.num_elements == 0


# In[24]:


def reverse_queue(queue):
    """
    Reverese the input queue

    Args:
       queue(queue),str2(string): Queue to be reversed
    Returns:
       queue: Reveresed queue
    """
    
    # TODO: Write reversed queue function
    
    st = Stack()
    while queue.size():
        st.push(queue.dequeue())
        
    while st.size():
        queue.enqueue(st.pop())
    return queue


def reverse_queue(queue):
    node = queue.head
    node_next = node.next
    node.next = None
    
    while node_next:
        tmp = node_next.next
        node_next.next = node
        node = node_next
        node_next = tmp
        
    tmp = queue.head
    queue.head = queue.tail
    queue.tail = tmp
        
    return queue


# In[21]:


def test_function(test_case):
    queue = Queue()
    for num in test_case:
        queue.enqueue(num)
    
    reverse_queue(queue)
    index = len(test_case) - 1
    while not queue.is_empty():
        removed = queue.dequeue()
        if removed != test_case[index]:
            print("Fail")
            return
        else:
            index -= 1
    print("Pass")
    


# In[22]:


test_case_1 = [1, 2, 3, 4]
test_function(test_case_1)


# In[23]:


test_case_2 = [1]
test_function(test_case_2)


# <span class="graffiti-highlight graffiti-id_8lnr8ur-id_7ltw82e"><i></i><button>Hide Solution</button></span>

# In[ ]:


def reverse_queue(queue):
    stack = Stack()
    while not queue.is_empty():
        stack.push(queue.dequeue())

    while not stack.is_empty():
        queue.enqueue(stack.pop())

