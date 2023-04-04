#!/usr/bin/env python
# coding: utf-8

# # Permutation

# 
# **Question** - Let's use recursion to help us solve the following permutation problem:
# 
# Given a list of items, the goal is to find all of the permutations of that list. For example,<br>
# Given a list like: `[0, 1, 2]` <br>
# Permutations: `[[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]]` <br><br>
# Notice that the expected output is a list of permutation with each permuted item being represented by a list. Such an object that contains other object is called "compound" object. <br>
# 
# **The Idea**<br>
# Build a compoundList incrementally starting with a blank list, and permute (add) each element of original input list at all possible positions. <br><br>
# 
# For example, take `[0, 1, 2]` as the original input list:<br>
# 
# 1. Start with a blank compoundList `[[]]`. This is actually the last call of recursive function stack. Pick the element `2` of original input list, making the compoundList as `[[2]]`<br><br>
# 
# 2. Pick next element `1` of original input list, and add this element at position 0, and 1 for each list of previous compoundList. **We will require to create copy of all lists of previous compoundList, and add the new element.** Now, the compoundList will become `[[1, 2], [2, 1]]`.<br><br>
# 
# 3. Pick next element `0` of original input list, and add this element at position 0, 1, and 2 for each list of previous compoundList. Now, the compoundList will become `[[0, 1, 2], [1, 0, 2], [1, 2, 0], [0, 2, 1], [2, 0, 1], [2, 1, 0]]` .<br><br>
# 

# 
# **Additional Resource**<br>
# While dealing with a "compound" object, a simple copy operation might not work as expected. You would need a function that can create a deep copy. For this purpose, you can make use of `deepcopy()` function from the `copy` module in Python. This module provides the function for normal (Shallow) and deep copy operations. Refer here - https://docs.python.org/3/library/copy.html for syntax and detailed information, that says:  <br>
# <br>
# >**Difference between Deep and Shallow Copy**<br>
# The difference between shallow and deep copying is only relevant for compound objects (objects that contain other objects, like lists or class instances):
#  - A shallow copy constructs a new compound object and then inserts references into it to the objects found in the original.
#  - A deep copy constructs a new compound object and then, recursively, inserts copies into it of the objects found in the original.
#  
# **Example Illustration of deep copy, shallow copy, and assignment operator**<br>

# In[1]:


import copy                                           # `copy` module

list1 = [0, 1, 2]
list2 = [7, 8, 9]                                     
compoundList1 = [list1, list2]                        # create a compound object


'''ASSIGNMENT OPERATION - Points a new reference to the existing object.'''
compoundList2 = compoundList1

# id() - returns the identity of the object passed
print(id(compoundList1) == id(compoundList2))          # True - compoundList2 is the same object as compoundList1
print(id(compoundList1[0]) == id(compoundList2[0]))    # True - compoundList2[0] is the same object as compoundList1[0]


'''SHALLOW COPY'''
compoundList2 = copy.copy(compoundList1)

print(id(compoundList1) == id(compoundList2))          # False - compoundList2 is now a new object
print(id(compoundList1[0]) == id(compoundList2[0]))    # True - compoundList2[0] is the same object as compoundList1[0]


'''DEEP COPY'''
compoundList2 = copy.deepcopy(compoundList1)

print(id(compoundList1) == id(compoundList2))          # False - compoundList2 is now a new object
print(id(compoundList1[0]) == id(compoundList2[0]))    # False - compoundList2[0] is now a new object


# ---
# ### Exercise - Write the function definition here

# In[3]:


# Code

import copy

def permute(inputList):
    """
    Args: myList: list of items to be permuted
    Returns: list of permutation with each permuted item being represented by a list
    """
    
    if not len(inputList):
        return [[]]
    
    one_el = inputList[0]
    sub_compound_list = permute(inputList[1:])
    final_compound_list = []
    
    for a_list in sub_compound_list:
        for i in range(len(a_list) + 1):
            copy_a_list = copy.copy(a_list)
            copy_a_list.insert(i, one_el)
            final_compound_list.append(copy_a_list)
    
    return final_compound_list
    


# ### Test - Let's test your function

# In[4]:


# Test Cases 

# Helper Function
def check_output(output, expected_output):
    """
    Return True if output and expected_output
    contains the same lists, False otherwise.
    
    Note that the ordering of the list is not important.
    
    Examples:
        check_output([ [0, 1], [1, 0] ] ], [ [1, 0], [0, 1] ]) returns True

    Args:
        output(list): list of list
        expected_output(list): list of list
    
    Returns:
        bool
    """
    o = copy.deepcopy(output)  # so that we don't mutate input
    e = copy.deepcopy(expected_output)  # so that we don't mutate input
    
    o.sort()
    e.sort()
    return o == e

print ("Pass" if  (check_output(permute([]), [[]])) else "Fail")
print ("Pass" if  (check_output(permute([0]), [[0]])) else "Fail")
print ("Pass" if  (check_output(permute([0, 1]), [[0, 1], [1, 0]])) else "Fail")
print ("Pass" if  (check_output(permute([0, 1, 2]), [[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]])) else "Fail")


# In[ ]:



# Recursive Solution 
"""
Args: myList: list of items to be permuted
Returns: compound list: list of permutation with each permuted item being represented by a list
"""
import copy                                # We will use `deepcopy()` function from the `copy` module

def permute(inputList):
    
    # a compound list
    finalCompoundList = []                  # compoundList to be returned 
    
    # Set a base condition to terminate recursion function when the `inputList`
    # cannot be divided further and return the `finalCompoundList`
    
    if len(inputList) == 0:
        finalCompoundList.append([])
        
    else:
        # We are going to split the input into two lists as follows:
        # `first_list` consisting of the first element on the `inputList`
        # `rest_list` consisting the remaining `inputList`
        
        first_element = inputList[0]        # Pick one element to be permuted
        after_first = slice(1, None)        # `after_first` is an object of type 'slice' class
        rest_list = inputList[after_first]  # convert the `slice` object into a list
        
        # Call the recursive function to split the `rest_list` further until it meets the base condition
        # and store the last `finalCompoundList` output into `sub_compoundList` variable
        
        sub_compoundList = permute(rest_list)
        
        # Once the recursion function meets the base condition, we can build the permutation by
        # iterating through all lists of the `compoundList` returned from previous recursive call
        
        for aList in sub_compoundList:
            # Permuted the `first_element` at all positions 0, 1, 2 ... len(aList) in each iteration
            for j in range(0, len(aList) + 1): 
                
                # A normal copy/assignment will change aList[j] element
                bList = copy.deepcopy(aList)  
                
                # A new list with size +1 as compared to aList
                # is created by inserting the `first_element` at position j in bList
                bList.insert(j, first_element)
                
                # Append the newly created list to the finalCompoundList
                finalCompoundList.append(bList)
                
    return finalCompoundList


# <span class="graffiti-highlight graffiti-id_7mkz7sx-id_al2wv3g"><i></i><button>Show Solution</button></span>
