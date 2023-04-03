#!/usr/bin/env python
# coding: utf-8

# # Counting Inversions
# 
# The number of *inversions* in a disordered list is the number of pairs of elements that are inverted (out of order) in the list.  
# 
# Here are some examples: 
#   - [0,1] has 0 inversions
#   - [2,1] has 1 inversion (2,1)
#   - [3, 1, 2, 4] has 2 inversions (3, 2), (3, 1)
#   - [7, 5, 3, 1] has 6 inversions (7, 5), (3, 1), (5, 1), (7, 1), (5, 3), (7, 3)
#   
# The number of inversions can also be thought of in the following manner. 
# 
# >Given an array `arr[0 ... n-1]` of `n` distinct positive integers, for indices `i and j`, if `i < j` and `arr[i] > arr[j]` then the pair `(i, j)` is called an inversion of `arr`.
# 
# ## Problem statement
# 
# Write a function, `count_inversions`, that takes an array (or Python list) as input, and returns a count of the total number of inversions present in the input.
# 
# Mergesort provides an efficient way to solve this problem.

# In[83]:



def count_recursive(arr, num_inv):
    if len(arr) < 2:
        return arr
    
    mid_index = len(arr) // 2
    left = count_recursive(arr[:mid_index], num_inv)
    right = count_recursive(arr[mid_index:], num_inv)
    
    left_index = 0
    right_index = 0
    merged = []
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            merged.append(left[left_index])
            left_index +=1 
        else:
            merged.append(right[right_index])
            right_index +=1
            num_inv[0] += (len(left) - left_index)
            
    
    merged += left[left_index:]
    merged += right[right_index:]
    
    return merged
            
            
def count_inversions(arr):
    # TODO: Complete this function
    num_inv = [0]
    res = count_recursive(arr, num_inv)
    print(num_inv[0])
    print(res)
    return num_inv[0]
   
            
    
    
    


# <span class="graffiti-highlight graffiti-id_8809fp2-id_8br31oi"><i></i><button>Hide Solution</button></span>

# In[78]:


def count_inversions(arr):
    start_index = 0
    end_index = len(arr) - 1
    output = inversion_count_func(arr, start_index, end_index)
    return output


def inversion_count_func(arr, start_index, end_index):
    if start_index >= end_index:
        return 0

    mid_index = start_index + (end_index - start_index) // 2
    
    # find number of inversions in left-half
    left_answer = inversion_count_func(arr, start_index, mid_index)
    
    # find number of inversions in right-half
    right_answer = inversion_count_func(arr, mid_index + 1, end_index)

    output = left_answer + right_answer
    
    # merge two sorted halves and count inversions while merging
    output += merge_two_sorted_halves(arr, start_index, mid_index, mid_index + 1, end_index)
    return output


def merge_two_sorted_halves(arr, start_one, end_one, start_two, end_two):
    count = 0
    left_index = start_one
    right_index = start_two

    output_length = (end_two - start_two + 1) + (end_one - start_one + 1)
    output_list = [0 for _ in range(output_length)]
    index = 0

    while index < output_length:
        # if left <= right, it's not an inversion
        if arr[left_index] <= arr[right_index]:
            output_list[index] = arr[left_index]
            left_index += 1

        else:
            count = count + (end_one - left_index + 1)           # left > right hence it's an inversion
            output_list[index] = arr[right_index]
            right_index += 1

        index = index + 1

        if left_index > end_one:
            for i in range(right_index, end_two + 1):
                output_list[index] = arr[i]
                index += 1
            break

        elif right_index > end_two:
            for i in range(left_index, end_one + 1):
                output_list[index] = arr[i]
                index += 1
            break

    index = start_one
    for i in range(output_length):
        arr[index] = output_list[i]
        index += 1
    return count


# In[84]:


def test_function(test_case):
    arr = test_case[0]
    solution = test_case[1]
    if count_inversions(arr) == solution:
        print("Pass")
    else:
        print("Fail")


# In[85]:


arr = [2, 5, 1, 3, 4]
solution = 4
test_case = [arr, solution]
test_function(test_case)


# In[86]:


arr = [54, 99, 49, 22, 37, 18, 22, 90, 86, 33]
solution = 26
test_case = [arr, solution]
test_function(test_case)


# In[82]:


arr = [1, 2, 4, 2, 3, 11, 22, 99, 108, 389]
solution = 2
test_case = [arr, solution]
test_function(test_case)


# In[ ]:




