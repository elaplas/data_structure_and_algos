#!/usr/bin/env python
# coding: utf-8

# # Min Operations

# Starting from the number `0`, find the minimum number of operations required to reach a given positive `target number`. You can only use the following two operations:
# 
#     1. Add 1
#     2. Double the number
#     
# ### Example:
# 
# 1. For `Target = 18`,  `output = 6`, because it takes at least 6 steps shown below to reach the target
# 
#  * `start = 0`
#  * `step 1 ==> 0 + 1 = 1`
#  * `step 2 ==> 1 * 2 = 2`              # or 1 + 1 = 2
#  * `step 3 ==> 2 * 2 = 4`
#  * `step 4 ==> 4 * 2 = 8`
#  * `step 5 ==> 8 + 1 = 9`
#  * `step 6 ==> 9 * 2 = 18`
# 
#  
# 
# 2. For `Target = 69`, `output = 9`, because it takes at least 8 steps to reach `69` from `0` using the allowed operations
# 
#  * `start = 0`
#  * `step 1 ==> 0 + 1 = 1`
#  * `step 2 ==> 1 + 1 = 2`
#  * `step 3 ==> 2 * 2 = 4`
#  * `step 4 ==> 4 * 2 = 8`
#  * `step 5 ==> 8 * 2 = 16`
#  * `step 6 ==> 16 + 1 = 17`
#  * `step 7 ==> 17 * 2 = 34`
#  * `step 8 ==> 34 * 2 = 68`
#  * `step 9 ==> 68 + 1  = 69`
# 
# 

# In[26]:


# Your solution
def min_operations(n):
    """
    Return number of steps taken to reach a target number
    input: target number (as an integer)
    output: number of steps (as an integer)
    """
    return min_operand(1, n, 0 ) + 1

def min_operand(guess, target, num_operands):
    
    if guess == target:
        return num_operands
    
    if guess > target:
        return num_operands * 1000 # Multiply with a big number to disqualify the solution
    
    
    sol_1 = min_operand(guess+1, target, num_operands+1)
    sol_2 = min_operand(guess*2, target, num_operands+1)
    
    return min(sol_1, sol_2)
        
        
    
    


# In[27]:


# Test Cases

def test_function(test_case):
    target = test_case[0]
    solution = test_case[1]
    output = min_operations(target)
    
    print(output)
    
    if output == solution:
        print("Pass")
    else:
        print("Fail")


# In[28]:


target = 18
solution = 6
test_case = [target, solution]
test_function(test_case)


# In[29]:


target = 69
solution = 9
test_case = [target, solution]
test_function(test_case)


# In[ ]:


def min_operations(target):
    """
    Return number of steps taken to reach a target number
    input:- target number an integer
    output:- number of steps an integer
    """
    num_steps = 0
    
    # start backwards from the target
    # if target is odd --> subtract 1
    # if target is even --> divide by 2
    while target != 0:
        if target % 2 == 0:
            target = target // 2

        else:
            target = target - 1
        num_steps += 1
    return num_steps


# <span class="graffiti-highlight graffiti-id_smc71m1-id_lhrilt9"><i></i><button>Show Solution</button></span>
