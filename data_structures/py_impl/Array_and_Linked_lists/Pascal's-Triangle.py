#!/usr/bin/env python
# coding: utf-8

# # Problem Statement
# 
# Find and return the `nth` row of Pascal's triangle in the form a list. `n` is 0-based.
# 
# For example, if `n = 4`, then `output = [1, 4, 6, 4, 1]`.
# 
# To know more about Pascal's triangle: https://www.mathsisfun.com/pascals-triangle.html

# In[30]:



def row_pascal(in_list, n):
    if n < 2:
        return in_list
    
    out_list = []
    for i in range(len(in_list)+1):
        if i==0 or i == len(in_list):
            out_list.append(1)
        else:
            out_list.append(in_list[i-1] + in_list[i])
    return row_pascal(out_list, n-1)
   



def nth_row_pascal(n):
    """
    :param: - n - index (0 based)
    return - list() representing nth row of Pascal's triangle
    """
    
    if n == 0:
        return [1]
    
    if n == 1:
        return [1,1]
    
    return row_pascal([1,1], n)
    
    
    
    


# <span class="graffiti-highlight graffiti-id_wf20h2l-id_cuoppnd"><i></i><button>Show Solution</button></span>

# In[31]:


def test_function(test_case):
    n = test_case[0]
    solution = test_case[1]
    output = nth_row_pascal(n)
    print(output)
    if solution == output:
        print("Pass")
    else:
        print("Fail")


# In[32]:


n = 0
solution = [1]

test_case = [n, solution]
test_function(test_case)


# In[33]:


n = 1
solution = [1, 1]

test_case = [n, solution]
test_function(test_case)


# In[34]:


n = 2
solution = [1, 2, 1]

test_case = [n, solution]
test_function(test_case)


# In[35]:


n = 3
solution = [1, 3, 3, 1]

test_case = [n, solution]
test_function(test_case)


# In[36]:


n = 4
solution = [1, 4, 6, 4, 1]

test_case = [n, solution]
test_function(test_case)


# In[ ]:




