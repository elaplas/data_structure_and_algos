#!/usr/bin/env python
# coding: utf-8

# # Case Specific Sorting of Strings
# 
# ## Problem statement
# Given a string consisting of uppercase and lowercase ASCII characters, write a function, `case_sort`, that sorts uppercase and lowercase letters separately, such that if the $i$th place in the original string had an uppercase character then it should not have a lowercase character after being sorted and vice versa.
# 
# For example:  
# **Input:** fedRTSersUXJ  
# **Output:** deeJRSfrsTUX

# In[1]:


def case_sort(string):
    """
    Here are some pointers on how the function should work:
    1. Sort the string
    2. Create an empty output list
    3. Iterate over original string
        if the character is lower-case:
            pick lower-case character from sorted string to place in output list
        else:
            pick upper-case character from sorted string to place in output list
    
    Note: You can use Python's inbuilt ord() function to find the ASCII value of a character
    """
    sorted_str = sorted(string)
    res = ""
    l_index = 0
    u_index = 0
    for c in string:
        if c.islower():
            while sorted_str[l_index].isupper():
                l_index += 1
            res += sorted_str[l_index]
            l_index += 1
        else:
            while sorted_str[u_index].islower():
                u_index += 1
            res += sorted_str[u_index]
            u_index += 1
    return res
            


# In[ ]:


def case_sort(string):
    upper_ch_index = 0
    lower_ch_index = 0
    
    sorted_string = sorted(string)
    for index, character in enumerate(sorted_string):
        # check if character is lower-case
        ascii_int = ord(character)
        if 97 <= ascii_int <= 122:       # ASCII value of a = 97 & ASCII value of z = 122
            lower_ch_index = index
            break
            
    output = list()
    for character in string:
        ascii_int = ord(character)
        # if character is lower case pick next lower_case character
        if 97 <= ascii_int <= 122:
            output.append(sorted_string[lower_ch_index])
            lower_ch_index += 1
        else:
            output.append(sorted_string[upper_ch_index])
            upper_ch_index += 1
    return "".join(output)


# <span class="graffiti-highlight graffiti-id_mw53bf1-id_fsblbn3"><i></i><button>Show Solution</button></span>

# In[2]:


def test_function(test_case):
    test_string = test_case[0]
    solution = test_case[1]
    
    if case_sort(test_string) == solution:
        print("Pass")
    else:
        print("False")


# In[3]:


test_string = 'fedRTSersUXJ'
solution = "deeJRSfrsTUX"
test_case = [test_string, solution]
test_function(test_case)


# In[4]:


test_string = "defRTSersUXI"
solution = "deeIRSfrsTUX"
test_case = [test_string, solution]
test_function(test_case)


# In[ ]:




