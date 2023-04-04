#!/usr/bin/env python
# coding: utf-8

# ### Problem Statement
# 
# 
# Given an integer array, find and return all the subsets of the array.
# The order of subsets in the output array is not important. However the order of elements in a particular subset should remain the same as in the input array.
# 
# **Note**: 
# - An empty set will be represented by an empty list.
# - If there are repeat integers, each occurrence must be treated as a separate entity.
# 
# **Example 1**
# 
# ```
# arr = [9, 9]
# 
# output = [[],
#           [9],
#           [9],
#           [9, 9]]
# ```
# 
# **Example 2**
# 
# ```
# arr = [9, 12, 15]
# 
# output =  [[],
#            [15],
#            [12],
#            [12, 15],
#            [9],
#            [9, 15],
#            [9, 12],
#            [9, 12, 15]]
# ```

# In[7]:


def subsets(arr):
    """
    :param: arr - input integer array
    Return - list of lists (two dimensional array) where each list represents a subset
    TODO: complete this method to return subsets of an array
    """
    
    if not len(arr):
        return [[]]
    
    first_el = arr[0]
    sub_compound_list = subsets(arr[1:])
    for i in range (len(sub_compound_list)):
        sub_compound_list.append([first_el] + sub_compound_list[i])
    
    return sub_compound_list
    
    
    


# <span class="graffiti-highlight graffiti-id_u30cq9y-id_2p8ft48"><i></i><button>Hide Solution</button></span>

# In[ ]:


# Solution
def subsets(arr):
    return return_subsets(arr, 0)

def return_subsets(arr, index):
    if index >= len(arr):
        return [[]]

    small_output = return_subsets(arr, index + 1)

    output = list()
    # append existing subsets
    for element in small_output:
        output.append(element)

    # add current elements to existing subsets and add them to the output
    for element in small_output:
        current = list()
        current.append(arr[index])
        current.extend(element)
        output.append(current)
    return output


# In[8]:


def test_function(test_case):
    arr = test_case[0]
    solution = test_case[1]
    
    output = subsets(arr)
        
    output.sort()
    solution.sort()
    
    print(output)
    
    if output == solution:
        print("Pass")
    else:
        print("Fail")    


# In[9]:


arr = [9]
solution = [[], [9]]

test_case = [arr, solution]
test_function(test_case)


# In[10]:


arr = [5, 7]
solution = [[], [7], [5], [5, 7]]
test_case = [arr, solution]
test_function(test_case)


# In[11]:


arr = [9, 12, 15]
solution = [[], [15], [12], [12, 15], [9], [9, 15], [9, 12], [9, 12, 15]]

test_case = [arr, solution]
test_function(test_case)


# In[12]:


arr = [9, 8, 9, 8]
solution = [[],
[8],
[9],
[9, 8],
[8],
[8, 8],
[8, 9],
[8, 9, 8],
[9],
[9, 8],
[9, 9],
[9, 9, 8],
[9, 8],
[9, 8, 8],
[9, 8, 9],
[9, 8, 9, 8]]

test_case = [arr, solution]
test_function(test_case)


# In[ ]:




