#!/usr/bin/env python
# coding: utf-8

# # Knapsack Problem
# Now that you saw the dynamic programming solution for the knapsack problem, it's time to implement it. Assume you are given two things:
# 1. The `items`, each having its associated weight (kg) and value ($\$$). 
# 1. A knapsack  that can hold a maximum weight of `knapsack_max_weight` (kg).
# 
# Use dynamic programming to implement the function `knapsack_max_value()` to **return the maximum total value**  of items that can be accommodated into the given knapsack.
# 
# 
# **Note** - The `items` variable is the type `Item`, which is a [named tuple](https://docs.python.org/3/library/collections.html#collections.namedtuple).

# In[3]:


# Helper code
import collections

# An item can be represented as a namedtuple
Item = collections.namedtuple('Item', ['weight', 'value'])


def knapsack_max_value(knapsack_max_weight, items):
    return knapsack_max_val_recursive(items, knapsack_max_weight, 0,0,0)
    
# All possible combinations (2^n) are formed using recursions then the max result 
# is returned on each recursion
def knapsack_max_val_recursive(items, max_weight, sum_val, sum_weight, i):
    
    if i >= len(items):
        return sum_val, sum_weight

    
    val1, weight1 = knapsack_max_val_recursive(items, 
                                      max_weight,
                                      sum_val + items[i].value, 
                                      sum_weight + items[i].weight,
                                      i+1)
    
    val2, weight2 = knapsack_max_val_recursive(items,
                                      max_weight,
                                      sum_val,
                                      sum_weight,
                                      i+1)
    
    if weight1 > max_weight and weight2 > max_weight:
        return 0,0
    elif weight1 > max_weight and weight2 <= max_weight:
        return val2, weight2
    elif weight1 <= max_weight and weight2 > max_weight:
        return val1, weight1
    else:
        if val1 > val2:
            return val1, weight1
        else:
            return val2, weight2


items = [Item(10, 2), Item(29, 10), Item(5, 7), Item(5, 3), Item(5, 1), Item(24, 12)]
knapsack_max_weight = 25

output = knapsack_max_value(knapsack_max_weight, items)
print(output)


# 
# ### The Naive Approach - Based on Recursion:
# The idea is, for each given item, if the item-weight is less than the remaining capacity (kg) of the knapsack, then calculate the value ($\$$) of the knapsack if we:
# 1. **Do not put the item in the knapsack** - Value ($\$$) of the knapsack will be the output of the `knapsack_recursive()` function, with the same remaining capacity, and check for the next item down the list.  
# 1. **Put the item in the knapsack** - Value ($\$$) of the knapsack will be the **sum** of the current value of the item and output of the `knapsack_recursive()` function,  with **updated** remaining capacity, and check for the next item down the list.  
# 
# Return the **maximum of either of the above two values**. In `knapsack_recursive()` function, begin with developing the solution for the base case i.e., smallest subproblem. 
# 
# **Note** - Below is the implementation of this naive approach with recursion, that has an exponential time complexity as $O(2^n)$, where $n$ is the number of given items, becuase we are evaluating both the two options (put/not put) for each given item.

# In[ ]:


# Naive Approach based on Recursion
def knapsack_max_value(knapsack_max_weight, items):
    lastIndex = len(items) - 1
    return knapsack_recursive(knapsack_max_weight, items, lastIndex)


def knapsack_recursive(capacity, items, lastIndex):
    # Base case
    if (capacity <= 0) or (lastIndex<0):
        return 0
    
    # Put the item in the knapsack
    valueA = 0
    if (items[lastIndex].weight <= capacity):
        valueA = items[lastIndex].value + knapsack_recursive(capacity - items[lastIndex].weight, items, lastIndex - 1)

    
    # Do not put the item in the knapsack
    valueB = knapsack_recursive(capacity, items, lastIndex - 1)
    
    # Pick the maximum of the two results
    result = max(valueA, valueB)
    
    return result


# ### The Approach - Dynamic Programming
# Store and reuse the intermediate results in a lookup table. This step is called memoization. Start with initializing a lookup table (a list), where the index represents the remaining capacity (kg) of the knapsack, and the element represents the maximum value ($\$$) that it can hold. 
# 
# For a given item, if the item-weight is less than the remaining capacity (kg) of the knapsack, then we have two options:
# 1. **Do not pick the item** - In this case, the value ($\$$) of knapsack with the remaining capacity would not change. It can be represented as `lookup_table[capacity]`.
# 1. **Pick the item** - In this case, the value ($\$$) and capacity (kg) of the knapsack would be updated. The value ($\$$) of the knapsack will be equal to value ($\$$) of the current object + value ($\$$) in the lookup table at `[capacity - item.weight]` position. It can be represented as `lookup_table[capacity - item.weight] + item.value`. 
# 
# Update the lookup table, `lookup_table[capacity]`,  with the **maximum of either of the above two values**.  
# 
# **Note** - This approach with dynamic programming will have a time complexity as $O(2nC) \equiv O(nC)$, where $n$ is the number of given items and $C$ is the max capacity (kg) of the knapsack. 

# ### Exercise - Write the function definition here

# In[14]:


# Dynamic programming:
# Instead of generating all combinations at once and then select the best one, the combinations are formed iteratively 
# and stored which reduces the time complexity and break the problem into samller problems  

def knapsack_max_value(knapsack_max_weight, items):
    """
    Get the maximum value of the knapsack.
    """
    
    visited = {}
    cur_max_val = 0
    #items = sorted(items, key=lambda x: (x.weight, -x.value))
    
    for item in items:
        if item.weight <= knapsack_max_weight:
            new_visited = {}
            
            # Check if the current item should be put in the "visited
            if item.weight not in visited:
                new_visited[item.weight] = item.value
            else:
                if item.value > visited[item.weight]:
                    new_visited[item.weight] = item.value
                    
            # Update max value            
            if item.value > cur_max_val:
                cur_max_val = item.value
            
            # Form new combinations and store the results
            for weight in visited:
                    
                if weight + item.weight <= knapsack_max_weight:
                        
                    if weight + item.weight not in visited:
                        new_visited[weight + item.weight] = visited[weight] + item.value
                    else:
                        if visited[weight]+ item.value > visited[weight + item.weight]:
                            new_visited[weight + item.weight] = visited[weight] + item.value
                            
                     # Update max value                                                       
                    if visited[weight] + item.value > cur_max_val:
                        cur_max_val = visited[weight] + item.value
                        
            # Copy new combinations to "visited" map            
            for key in new_visited:
                visited[key] = new_visited[key]
                           
    return cur_max_val
                        
                            

items = [Item(10, 2), Item(29, 10), Item(5, 7), Item(5, 3), Item(5, 1), Item(24, 12)]
max_weight = 25

res = knapsack_max_value(max_weight, items)
print(res)

                
            
    


# <span class="graffiti-highlight graffiti-id_sczu399-id_vljhmf7"><i></i><button>Hide Solution</button></span>

# In[ ]:


# DP Solution
# Get the maximum total value ($) of items that can be accommodated into the given knapsack
def knapsack_max_value(knapsack_max_weight, items):
    
    # Initialize a lookup table to store the maximum value ($) 
    lookup_table = [0] * (knapsack_max_weight + 1)


    # Iterate down the given list
    for item in items:
        
        # The "capcacity" represents amount of remaining capacity (kg) of knapsack at a given moment. 
        for capacity in reversed(range(knapsack_max_weight + 1)):
            
            if item.weight <= capacity:
                lookup_table[capacity] = max(lookup_table[capacity], lookup_table[capacity - item.weight] + item.value)

    return lookup_table[-1]


# ### Test - Let's test your function

# In[7]:


tests = [
    {
        'correct_output': 14,
        'input':
            {
                'knapsack_max_weight': 15,
                'items': [Item(10, 7), Item(9, 8), Item(5, 6)]}},
    {
        'correct_output': 13,
        'input':
            {
                'knapsack_max_weight': 25,
                'items': [Item(10, 2), Item(29, 10), Item(5, 7), Item(5, 3), Item(5, 1), Item(24, 12)]}}]
for test in tests:
    assert test['correct_output'] == knapsack_max_value(**test['input'])


# In[ ]:




