#!/usr/bin/env python
# coding: utf-8

# # Heapsort
# 
# A heapsort is an in-place sorting algorithm that treats an array like a binary tree and moves the largest values to the end of the heap until the full array is sorted.  
# 
# The main steps in a heapsort are:
# 1. Convert the array into a maxheap (a complete binary tree with decreasing values) 
# 2. Swap the top element with the last element in the array (putting it in it's correct final position)
# 3. Repeat with `arr[:len(arr)-1]` (all but the sorted elements)
# 
# ## Visualization of a heapsort
# ![animation of a heap sort](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)
# 
# ["Heapsort example"](https://commons.wikimedia.org/wiki/File:Heapsort-example.gif) by Swfung8. Used under [CC BY-SA 3.0](https://creativecommons.org/licenses/by-sa/3.0/deed.en).
# 
# ## Problem statement
# 
# In the cell below, see if you can code a `heapsort` function that takes an array (or Python list) and performs a heapsort on it. You will have to complete the heapify

# In[10]:


def heapsort(arr):

    # Build maxHeap
    heapify_up(arr)
    print("heapify up:", arr)
    
    # Remove biggest elments, swap them with the elment at the end of arr and heapify down
    for i in range(len(arr)):
        cur_length = len(arr)-i
        cur_biggest = arr[0]
        arr[0] = arr[cur_length-1]
        arr[cur_length-1] = cur_biggest
        heapify_down(arr, cur_length-1)
        print("heapify up:", arr)
    
def heapify_up(arr):
    """
    :param: arr - array to heapify
    n -- number of elements in the array
    i -- index of the current node
    TODO: Converts an array (in place) into a maxheap, a complete binary tree with the largest values at the top
    """
    for i in range(len(arr)):
     
        node = i
        parent_node = node // 2
                
        while node >= 0 and parent_node >= 0:
            
            if arr[parent_node] < arr[node]:
                tmp = arr[parent_node]
                arr[parent_node] = arr[node]
                arr[node ] = tmp
                
                node = parent_node
                parent_node = node // 2
            else:
                break
                
def heapify_down(arr, length):
    node = 0
    left_node = 1
    right_node = 2
    swap_node = left_node
    
    if right_node < length and arr[right_node] > arr[left_node]:
        swap_node = right_node
        
    while node < length and swap_node < length:
        if arr[swap_node] > arr[node]:
            tmp = arr[node]
            arr[node] = arr[swap_node]
            arr[swap_node] = tmp
            
            node = swap_node
            left_node = node*2 + 1
            right_node = node*2 + 2
            swap_node = left_node
            
            if right_node < length and arr[right_node] > arr[left_node]:
                swap_node = right_node
        else:
            break
            
            
                   


# <span class="graffiti-highlight graffiti-id_1h50lwk-id_kuae7he"><i></i><button>Show Solution</button></span>

# In[11]:


def test_function(test_case):
    heapsort(test_case[0])
    if test_case[0] == test_case[1]:
        print("Pass")
    else:
        print("False")


# In[12]:


arr = [3, 7, 4, 6, 1, 0, 9, 8, 9, 4, 3, 5]
solution = [0, 1, 3, 3, 4, 4, 5, 6, 7, 8, 9, 9]

test_case = [arr, solution]

test_function(test_case)


# In[13]:


arr = [5, 5, 5, 3, 3, 3, 4, 4, 4, 4]
solution = [3, 3, 3, 4, 4, 4, 4, 5, 5, 5]
test_case = [arr, solution]
test_function(test_case)


# In[14]:


arr = [99]
solution = [99]
test_case = [arr, solution]
test_function(test_case)


# In[15]:


arr = [0, 1, 2, 5, 12, 21, 0]
solution = [0, 0, 1, 2, 5, 12, 21]
test_case = [arr, solution]
test_function(test_case)


# In[ ]:




