#!/usr/bin/env python
# coding: utf-8

# We saw a *similar* problem earlier in **Data Structures** course, **Maps and Hashing** lesson. There, we used an additional space to create a dictionary in order to solve the problem. 
# 
# 
# ## Problem Statement
# 
# Given an input array and a target value (integer), find two values in the array whose sum is equal to the target value. Solve the problem **without using extra space**. You can assume the array has unique values and will never have more than one solution.

# In[25]:


def pair_sum(arr, target):
    """
    :param: arr - input array
    :param: target - target value
    TODO: complete this method to find two numbers such that their sum is equal to the target
    Return the two numbers in the form of a sorted list
    """
    sorted_arr = sorted(arr)
    smallest_i = 0
    biggest_i = len(arr)-1
    sol = [None,None]
    
    while smallest_i < len(arr) and biggest_i >= 0:
        if sorted_arr[smallest_i] + sorted_arr[biggest_i] > target:
            biggest_i -= 1
        elif sorted_arr[smallest_i] + sorted_arr[biggest_i] < target:
            smallest_i +=1 
        else:
            return [sorted_arr[smallest_i], sorted_arr[biggest_i]]
    return sol
            
    


# <span class="graffiti-highlight graffiti-id_z5auf94-id_mxw6vbb"><i></i><button>Show Solution</button></span>

# In[19]:


def test_function(test_case):
    input_list = test_case[0]
    target =test_case[1]
    solution = test_case[2]
    output = pair_sum(input_list, target)
    print(output)
    if output == solution:
        print("Pass")
    else:
        print("False")


# In[20]:


input_list = [2, 7, 11, 15]
target = 9
solution = [2, 7]
test_case = [input_list, target, solution]
test_function(test_case)


# In[21]:


input_list = [0, 8, 5, 7, 9]
target = 9
solution = [0, 9]
test_case = [input_list, target, solution]
test_function(test_case)


# In[22]:


input_list = [110, 9, 89]
target = 9
solution = [None, None]
test_case = [input_list, target, solution]
test_function(test_case)


# In[ ]:




