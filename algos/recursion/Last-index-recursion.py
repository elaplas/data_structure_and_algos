#!/usr/bin/env python
# coding: utf-8

# ## Problem statement
# 
# Given an array `arr` and a target element `target`, find the last index of occurence of `target` in `arr` using recursion. If `target` is not present in `arr`, return `-1`.
# 
# For example:
# 
# 1. For `arr = [1, 2, 5, 5, 1, 2, 5, 4]` and `target = 5`, `output = 6`
# 
# 2. For `arr = [1, 2, 5, 5, 1, 2, 5, 4]` and `target = 7`, `output = -1`

# In[3]:


def last_index(arr, target):
    """
    :param: arr - input array
    :param: target - integer element
    return: int - last index of target in arr
    TODO: complete this method to find the last index of target in arr
    """
    return last_index_recursive(arr, target, len(arr) - 1)
    
def last_index_recursive(arr, target, index):
    
    if index < 0:
        return -1
    
    res = last_index_recursive(arr, target, index-1)
    if arr[index] == target:
        res = index
        
    return res


# <span class="graffiti-highlight graffiti-id_vwcsmcw-id_flmfhqn"><i></i><button>Hide Solution</button></span>

# In[ ]:


# Solution
def last_index(arr, target):
    # we start looking from the last index
    return last_index_arr(arr, target, len(arr) - 1)


def last_index_arr(arr, target, index):
    if index < 0:
        return -1
    
    # check if target is found
    if arr[index] == target:
        return index

    # else make a recursive call to the rest of the array
    return last_index_arr(arr, target, index - 1)


# In[4]:


def test_function(test_case):
    arr = test_case[0]
    target = test_case[1]
    solution = test_case[2]
    output = last_index(arr, target)
    if output == solution:
        print("Pass")
    else:
        print("FAIL: Expected", solution, ", but you've got:", output)


# In[5]:


arr = [1, 2, 5, 5, 4]
target = 5
solution = 3

test_case = [arr, target, solution]
test_function(test_case)


# In[6]:


arr = [1, 2, 5, 5, 4]
target = 7
solution = -1

test_case = [arr, target, solution]
test_function(test_case)


# In[7]:


arr = [91, 19, 3, 8, 9]
target = 91
solution = 0

test_case = [arr, target, solution]
test_function(test_case)


# In[8]:


arr = [1, 1, 1, 1, 1, 1]
target = 1
solution = 5

test_case = [arr, target, solution]
test_function(test_case)


# In[ ]:




