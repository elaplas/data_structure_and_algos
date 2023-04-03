#!/usr/bin/env python
# coding: utf-8

# # Binary search practice
# 
# Let's get some practice doing binary search on an array of integers. We'll solve the problem two different ways—both iteratively and resursively.
# 
# Here is a reminder of how the algorithm works:
# 
# 1. Find the center of the list (try setting an upper and lower bound to find the center)
# 2. Check to see if the element at the center is your target.
# 3. If it is, return the index.
# 4. If not, is the target greater or less than that element?
# 5. If greater, move the lower bound to just above the current center
# 6. If less, move the upper bound to just below the current center
# 7. Repeat steps 1-6 until you find the target or until the bounds are the same or cross (the upper bound is less than the lower bound).
# 
# 
# ## Problem statement:
# Given a sorted array of integers, and a target value, find the index of the target value in the array. If the target value is not present in the array, return -1.
# 
# ## Iterative solution
# 
# First, see if you can code an iterative solution (i.e., one that uses loops). If you get stuck, the solution is below.

# In[17]:


def binary_search(array, target):
    '''Write a function that implements the binary search algorithm using iteration
   
    args:
      array: a sorted array of items of the same type
      target: the element you're searching for
   
    returns:
      int: the index of the target, if found, in the source
      -1: if the target is not found
    '''
    start_index = 0
    end_index = len(array)
    while start_index < end_index:
        mid_index = ( end_index - start_index ) // 2 + start_index
        if array[mid_index] == target:
            return mid_index
        elif target < array[mid_index]:
            end_index = mid_index
        else:
            start_index = mid_index
            
    return -1


# <span class="graffiti-highlight graffiti-id_2fv59c4-id_271h0jf"><i></i><button>Hide Solution</button></span>

# In[ ]:


def binary_search(array, target):
    start_index = 0
    end_index = len(array) - 1
    
    while start_index <= end_index:
        mid_index = (start_index + end_index)//2        # integer division in Python 3
        
        mid_element = array[mid_index]
        
        if target == mid_element:                       # we have found the element
            return mid_index
        
        elif target < mid_element:                      # the target is less than mid element
            end_index = mid_index - 1                   # we will only search in the left half
        
        else:                                           # the target is greater than mid element
            start_index = mid_element + 1               # we will search only in the right half
    
    return -1


# Here's some code you can use to test the function:

# In[18]:


def test_function(test_case):
    answer = binary_search(test_case[0], test_case[1])
    print(answer)
    if answer == test_case[2]:
        print("Pass!")
    else:
        print("Fail!")


# In[19]:


array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
target = 6
index = 6
test_case = [array, target, index]
test_function(test_case)


# ## Recursive solution
# Now, see if you can write a function that gives the same results, but that uses recursion to do so.

# In[ ]:


def binary_search_recursive(array, target):
    '''
    This function will call `binary_search_recursive_soln` function.
    You don't need to change this function.
    
    args:
      array: a sorted array of items of the same type
      target: the element you're searching for
    '''
    return binary_search_recursive_soln(array, target, 0, len(array) - 1)


def binary_search_recursive_soln(array, target, start_index, end_index):
    '''Write a function that implements the binary search algorithm using recursion
    
    args:
      array: a sorted array of items of the same type
      target: the element you're searching for
      start_index: beginning of the index of the sub-arrays
      end_index: end of the index of the sub-arrays
         
    returns:
      int: the index of the target, if found, in the source
      -1: if the target is not found
    '''
    if start_index > end_index:
        return -1
    
    mid_index = (start_index + end_index)//2
    if array[mid_index] == target:
        return mid_index
    elif target< array[mid_index]:
        end_index = mid_index
    else:
        strat_index = mid_index
        
    binary_search_recursive_soln(array, target, start_index, end_index)
        


# <span class="graffiti-highlight graffiti-id_6wztnno-id_9gaa8a3"><i></i><button>Show Solution</button></span>

# Here's some code you can use to test the function:

# In[ ]:


def test_function(test_case):
    answer = binary_search_recursive(test_case[0], test_case[1])
    if answer == test_case[2]:
        print("Pass!")
    else:
        print("Fail!")


# In[ ]:


array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 4
index = 4
test_case = [array, target, index]
test_function(test_case)

