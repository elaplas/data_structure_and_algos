#!/usr/bin/env python
# coding: utf-8

# ### Problem Statement
# 
# Suppose there is a staircase that you can climb in either 1 step, 2 steps, or 3 steps. In how many possible ways can you climb the staircase if the staircase has `n` steps? Write a recursive function to solve the problem.
# 
# **Example:**
# 
# * `n == 1` then `answer = 1`
# 
# * `n == 3` then `answer = 4`<br>
#    The output is `4` because there are four ways we can climb the staircase:
#     - 1 step +  1 step + 1 step
#     - 1 step + 2 steps 
#     - 2 steps + 1 step
#     - 3 steps
# * `n == 5` then `answer = 13`
# 

# ### Exercise - Write a recursive function to solve this problem

# In[34]:


"""
param: n - number of steps in the staircase
Return number of possible ways in which you can climb the staircase
"""
def staircase(n):
    '''Hint'''
    # Base Case - What holds true for minimum steps possible i.e., n == 0, 1, 2 or 3? Return the number of ways the child can climb n steps.
    
    # Recursive Step - Split the solution into base case if n > 3.
    res = staircase_recursive(n)
    print(res)
    print(len(res))
    return len(res)


def staircase_recursive(n):
    
    if n == 0:
        return [[]]
    
    sub_list_1 = None
    if n-1 >= 0:
        sub_list_1 = staircase_recursive(n-1)
        for a_list in sub_list_1:
            a_list.append(1)
           
            
    sub_list_2 = None
    if n-2 >= 0:
        sub_list_2 = staircase_recursive(n-2)
        for a_list in sub_list_2:
            a_list.append(2)
            
    
    sub_list_3 = None
    if n-3 >= 0:
        sub_list_3 = staircase_recursive(n-3)
        for a_list in sub_list_3:
            a_list.append(3)
            
    final_list = []
    if sub_list_1 is not None:
        final_list = final_list + sub_list_1
        
    if sub_list_2 is not None:
        final_list = final_list + sub_list_2
        
    if sub_list_3 is not None:
        final_list = final_list + sub_list_3
    
    return final_list
    
    


# In[ ]:


# Solution
## Read input as specified in the question.
## Print output as specified in the question.


def staircase(n):
    if n <= 0:
        return 1
    
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3)


# <span class="graffiti-highlight graffiti-id_w7lklez-id_brqvnra"><i></i><button>Show Solution</button></span>

# In[35]:


def test_function(test_case):
    n = test_case[0]
    solution = test_case[1]
    output = staircase(n)
    if output == solution:
        print("Pass")
    else:
        print("Fail")


# In[36]:


n = 3
solution = 4
test_case = [n, solution]
test_function(test_case)


# In[37]:


n = 4
solution = 7
test_case = [n, solution]
test_function(test_case)


# In[38]:


n = 7
solution = 44
test_case = [n, solution]
test_function(test_case)


# In[ ]:




