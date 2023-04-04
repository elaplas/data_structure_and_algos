#!/usr/bin/env python
# coding: utf-8

# ### What is Caching?

# Caching can be defined as the process of storing data into a temporary data storage to avoid recomputation or to avoid reading the data from a relatively slower part of memory again and again. Thus cachig serves as a fast "look-up" storage allowing programs to execute faster.  
# 
# *Let's use caching to chalk out an efficient solution for **a problem from the Recursion lesson**.*

# ### Problem Statement - (Recursion) - Repeat Exercise 
# 
# A child is running up a staircase and can hop either 1 step, 2 steps or 3 steps at a time. 
# Given that the staircase has a total `n` steps, write a function to count the number of possible ways in which child can run up the stairs. 
# 
# For e.g. 
# 
# * `n == 1` then `answer = 1`
# 
# * `n == 3` then `answer = 4`<br>
#    The output is `4` because there are four ways we can climb the staircase:
#     - 1 step +  1 step + 1 step
#     - 1 step + 2 steps 
#     - 2 steps + 1 step
#     - 3 steps
#  
# * `n == 5` then `answer = 13`
# 
# **Hint**<br>
# You would need to make use of the [Inductive Hypothesis](https://en.wikipedia.org/wiki/Mathematical_induction#Description), which comprises of the following two steps:
# 1. **The Inductive Hypothesis**: Calculate/assume the results for base case. In our problem scenario, the base cases would be when n = 1, 2, and 3. 
# 
# 
# 2. **The Inductive Step**: Prove that for every $n >= 3$, if the results are true for $n$ , then it holds for $(n+1)$ as well. In other words, assume that the statement holds for some arbitrary natural number $n$ , and prove that the statement holds for $(n+1)$.
# 
# 

# In[14]:


def staircase(n):
    # Base Case - What holds true for minimum steps possible i.e., n == 1? Return the number of ways the child can climb one step.

    # Inductive Hypothesis - What holds true for n == 2 or n == 3? Return the number of ways to climb them.
    
    # Inductive Step (n > 3) - use Inductive Hypothesis to formulate a solution
    if n <= 0:
        return 1
    
    num1 = num2 = num3 = 0
    
    if n >= 1:
        num1 = staircase(n-1)
    if n >= 2:
        num2 = staircase(n-2)
    if n >= 3:
        num3 = staircase(n-3)
        
    return num1 + num2 + num3


# In[3]:


def test_function(test_case):
    answer = staircase(test_case[0])
    print(answer)
    if answer == test_case[1]:
        print("Pass")
    else:
        print("Fail")
            


# In[16]:


test_case = [4, 7]
test_function(test_case)


# In[17]:


test_case = [5, 13]
test_function(test_case)


# In[18]:


test_case = [3, 4]
test_function(test_case)


# In[19]:


test_case = [20, 121415]
test_function(test_case)


# <span class="graffiti-highlight graffiti-id_r189hz6-id_vtju73f"><i></i><button>Hide Solution</button></span>

# In[ ]:


def staircase(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3)


# ### Problem Statement - (Caching)
# 
# While using recursion for the above problem, you might have noticed a small problem with efficiency.
# 
# Let's take a look at an example.
# 
# * Say the total number of steps are `5`. This means that we will have to call at `(n=4), (n=3), and (n=2)`
# 
# * To calculate the answer for `n=4`, we would have to call `(n=3), (n=2) and (n=1)`
# 
# You can notice that even for a small number of staircases (here 5), we are calling `n=3` and `n=2` multiple times. Each time we call a method, additional time is required to calculate the solution. In contrast, instead of calling on a particular value of `n` again and again, we can **calculate it once and store the result** to speed up our program.
# 
# >Which data structure are you thinking to store the results?
# 
# Your job is to use any data-structure that you have used until now to write a faster implementation of the function you wrote earlier while using recursion. 
# 

# In[6]:


cache = {}

def staircase(n):
    if n == 1:
        return 1
    elif n== 2:
        return 2
    elif n == 3:
        return 4
    
    num1 = num2 = num3 = 0
    if n-1 in cache:
        num1 = cache[n-1]
    else:
        num1 = staircase(n-1)
        cache[n-1] = num1
        
    if n-2 in cache:
        num2 = cache[n-2]
    else:
        num2 = staircase(n-2)
        cache[n-2] = num2
        
    if n-3 in cache:
        num3 = cache[n-3]
    else:
        num3 = staircase(n-3)
        cache[n-3] = num3
        
    return num1 + num2 + num3
        
    
    


# In[7]:


test_case = [4, 7]
test_function(test_case)


# In[8]:


test_case = [5, 13]
test_function(test_case)


# In[9]:


test_case = [3, 4]
test_function(test_case)


# In[10]:


test_case = [20, 121415]
test_function(test_case)


# In[ ]:


def staircase(n):
    
    # start with a blank dictionary. It will populate in the recursive call
    num_dict = dict({})           
    return staircase_faster(n, num_dict)


'''Recursice function'''
def staircase_faster(n, num_dict):
    ''' 
    Here `n` is a key and `output` would be the corresponding value 
    to be inserted into the dictionary as a pair
    '''
    
    # Base cases
    if n == 1:
        output = 1
    elif n == 2:
        output = 2
    elif n == 3:
        output = 4
    else:
        
        # Simply check if the "value" corresponding to "(n-1)" key is already available in the dictionary
        if (n - 1) in num_dict:
            first_output = num_dict[n - 1]

        # Otherwise, calculate and insert the new key-value pair into the dictioanry
        else:
            first_output =  staircase_faster(n - 1, num_dict)
        
        if (n - 2) in num_dict:
            second_output = num_dict[n - 2]
        else:
            second_output = staircase_faster(n - 2, num_dict)
            
        if (n - 3) in num_dict:
            third_output = num_dict[n - 3]
        else:
            third_output = staircase_faster(n - 3, num_dict)
        
        output = first_output + second_output + third_output
    
    num_dict[n] = output;   # insert a key-value pair in the ORIGINAL dictionary 
    return output


# <span class="graffiti-highlight graffiti-id_0n79ls8-id_6t02ke7"><i></i><button>Show Solution</button></span>
