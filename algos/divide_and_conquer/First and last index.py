#!/usr/bin/env python
# coding: utf-8

# ## Problem statement
# 
# Given a sorted array that may have duplicate values, use *binary search* to find the **first** and **last** indexes of a given value.
# 
# For example, if you have the array `[0, 1, 2, 2, 3, 3, 3, 4, 5, 6]` and the given value is `3`, the answer will be `[4, 6]` (because the value `3` occurs first at index `4` and last at index `6` in the array).
# 
# The expected complexity of the problem is $O(log(n))$.

# In[65]:





def first_and_last_index(arr, number):
    """
    Given a sorted array that may have duplicate values, use binary 
    search to find the first and last indexes of a given value.

    Args:
        arr(list): Sorted array (or Python list) that may have duplicate values
        number(int): Value to search for in the array
    Returns:
        a list containing the first and last indexes of the given value
    """
    start_index = 0
    end_index = len(arr)
    while start_index < end_index:
        mid_index = ( start_index + end_index ) // 2
        if arr[mid_index] == number:
            first_occurrence = second_occurrence = mid_index
            while first_occurrence and arr[first_occurrence] == arr[first_occurrence-1]:
                    first_occurrence -= 1
            while second_occurrence < len(arr)-1 and arr[second_occurrence] == arr[second_occurrence+1]:
                    second_occurrence += 1   
            return [first_occurrence, second_occurrence]
            
        elif number < mid_index:
            end_index = mid_index
        else:
            start_index = mid_index + 1
    
    return [-1,-1]


# <span class="graffiti-highlight graffiti-id_y3lxp1x-id_fkngaks"><i></i><button>Hide Solution</button></span>

# In[ ]:


def first_and_last_index(arr, number):
    # search first occurence
    first_index = find_start_index(arr, number, 0, len(arr) - 1)
    
    # search last occurence
    last_index =  find_end_index(arr, number, 0, len(arr) - 1)
    return [first_index, last_index]


def find_start_index(arr, number, start_index, end_index):
    # binary search solution to search for the first index of the array
    if start_index > end_index:
        return -1

    mid_index = start_index + (end_index - start_index)//2

    if arr[mid_index] == number:
        current_start_pos = find_start_index(arr, number, start_index, mid_index - 1)
        if current_start_pos != -1:
            start_pos = current_start_pos
        else:
            start_pos = mid_index
        return start_pos

    elif arr[mid_index] < number:
        return find_start_index(arr, number, mid_index + 1, end_index)
    else:
        return find_start_index(arr, number, start_index, mid_index - 1)


def find_end_index(arr, number, start_index, end_index):
    # binary search solution to search for the last index of the array
    if start_index > end_index:
        return  -1

    mid_index = start_index + (end_index - start_index)//2

    if arr[mid_index] == number:
        current_end_pos = find_end_index(arr, number, mid_index + 1, end_index)
        if current_end_pos != -1:
            end_pos = current_end_pos
        else:
            end_pos = mid_index
        return end_pos
    elif arr[mid_index] < number:
        return find_end_index(arr, number, mid_index + 1, end_index)
    else:
        return find_end_index(arr, number, start_index, mid_index - 1)


# Below are several different test cases you can use to check your solution.

# In[66]:


def test_function(test_case):
    input_list = test_case[0]
    number = test_case[1]
    solution = test_case[2]
    output = first_and_last_index(input_list, number)
    print(output)
    if output == solution:
        print("Pass")
    else:
        print("Fail")


# In[67]:


input_list = [1]
number = 1
solution = [0, 0]
test_case_1 = [input_list, number, solution]
test_function(test_case_1)


# In[68]:


input_list = [0, 1, 2, 3, 3, 3, 3, 4, 5, 6]
number = 3
solution = [3, 6]
test_case_2 = [input_list, number, solution]
test_function(test_case_2)


# In[69]:


input_list = [0, 1, 2, 3, 4, 5]
number = 5
solution = [5, 5]
test_case_3 = [input_list, number, solution]
test_function(test_case_3)


# In[70]:


input_list = [0, 1, 2, 3, 4, 5]
number = 6
solution = [-1, -1]
test_case_4 = [input_list, number, solution]
test_function(test_case_4)


# In[ ]:




