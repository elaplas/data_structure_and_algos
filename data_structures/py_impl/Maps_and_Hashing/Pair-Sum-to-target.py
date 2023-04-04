#!/usr/bin/env python
# coding: utf-8

# ### Problem statement
# 
# Given an `input_list` and a `target`, return the pair of indices in the list that holds the values which sum to the `target`. For example, 
# 
# `input_list = [1, 5, 9, 7]` and `target = 8`, the answer would be `[0, 3]` 
# 
# **Note**<br>
# 1. The best solution takes O(n) time. *This means that you cannot traverse the given list more than once.* **Hint - Think of an additional data structure that you should use here.** 
# 2. You can assume that the list does not have any duplicates.

# In[1]:


def pair_sum_to_target(input_list, target):
    # TODO: Write pair sum to target function
    
    visited = {}
    
    for i, el in enumerate(input_list):
        if el in visited:
            return [visited[el], i]
        else:
            visited[target-el] = i


# In[2]:


def test_function(test_case):
    output = pair_sum_to_target(test_case[0], test_case[1])
    print(output)
    if sorted(output) == test_case[2]:
        print("Pass")
    else:
        print("Fail")


# In[ ]:


test_case_1 = [[1, 5, 9, 7], 8, [0, 3]]
test_function(test_case_1)


# In[ ]:


test_case_2 = [[10, 5, 9, 8, 12, 1, 16, 6], 16, [0, 7]]
test_function(test_case_2)


# In[ ]:


test_case_3 = [[0, 1, 2, 3, -4], -4, [0, 4]]
test_function(test_case_3)


# <span class="graffiti-highlight graffiti-id_snm0ke6-id_tv0tye7"><i></i><button>Show Solution</button></span>
