#!/usr/bin/env python
# coding: utf-8

# ### Problem Statement
# 
# The Tower of Hanoi is a puzzle where we have three rods and `n` unique sized disks. The three rods are - source, destination, and auxiliary as shown in the figure below.
# <br><img style="float: center;" src="TOH.png" alt="Image of 3 rod with all disks on the leftmost tower and instructions to move them to the rightmost tower."><br>
# Initally, all the `n` disks are present on the source rod. The final objective of the puzzle is to move all disks from the source rod to the destination rod using the auxiliary rod.<br><br> 
# **However, there are some rules applicable to all rods:**
#     1. Only one disk can be moved at a time.
#     2. A disk can be moved only if it is on the top of a rod.
#     3. No disk can be placed on the top of a smaller disk.
#     
# You will be given the number of disks `num_disks` as the input parameter. Write a **recursive function** `tower_of_Hanoi()` that prints the "move" steps in order to move `num_disks` number of disks from Source to Destination using the help of Auxiliary rod.
# 
# ---
# ### Example Illustration
# For example, if you have `num_disks = 3`, then the disks should be moved as follows:
#     
#         1. move disk from source to destination
#         2. move disk from source to auxiliary
#         3. move disk from destination to auxiliary
#         4. move disk from source to destination
#         5. move disk from auxiliary to source
#         6. move disk from auxiliary to destination
#         7. move disk from source to destination
#         
# You must print these steps as follows:    
# 
#                 S D
#                 S A
#                 D A
#                 S D
#                 A S
#                 A D
#                 S D
#         
# Where S = source, D = destination, A = auxiliary <br><br>
# An example illustration for `num_disks = 4` can be visualized in this [GIF from wikipedia](https://en.wikipedia.org/wiki/Tower_of_Hanoi#/media/File:Tower_of_Hanoi_4.gif)
# 
# ---
# 
# ### The Idea
# Assume you are writing a function that accepts the following arguments:
#         1. arg1 - number of disks
#         2. arg2 - rod A - this rod acts as the source (at the time of calling the function)
#         2. arg3 - rod B - this rod acts as the auxiliary
#         2. arg4 - rod C - this rod acts as the destination
#         
# Follow the steps below:
# 1. Given the `num_disks` disks on the source, along with auxiliary and destination rods<br><br>
# 2. Check if `num_disks == 1`. This must be the termination condition, therefore use recursion to reach at this moment. 
#  - If yes, move disk from source to destination. (Termination condition)<br><br>
# 3. For `num_disks > 1`, just think of your FIRST set of steps. You want to pick the bottom most disk on the source, to be transferred to the destination. For this reason, you will will perform the steps below:
#  - Step 1: Move `num_disks - 1` from source to auxiliary<br><br>
#  - Step 2: Now you are left with only the largest disk at source. Move the only leftover disk from source to destination<br><br>
#  - Step 3: You had `num_disks - 1` disks available on the auxiliary, as a result of Step 1. Move `num_disks - 1` from auxiliary to destination
# 
# ---
# ### Exercise - Write the function definition here

# In[11]:


def tower_of_Hanoi(num_disks):
    """
    :param: num_disks - number of disks
    TODO: print the steps required to move all disks from source to destination
    
    
    """
    tower_of_Hanoi_recursive(num_disks, "S", "A", "D")
    

def tower_of_Hanoi_recursive(num_disks, source, auxiliray, destination):
    if num_disks == 0:
        return
    
    tower_of_Hanoi_recursive(num_disks-1, source, destination, auxiliray)
    
    print("{} {}".format(source, destination))
    
    tower_of_Hanoi_recursive(num_disks-1, auxiliray, source, destination) 


tower_of_Hanoi(2)
print("................")
tower_of_Hanoi(3)
print("................")
tower_of_Hanoi(4)


# <span class="graffiti-highlight graffiti-id_rh9jy5w-id_aaedpt9"><i></i><button>Hide Solution</button></span>

# In[ ]:


# Recursive Solution
def tower_of_Hanoi_soln(num_disks, source, auxiliary, destination):
    
    # Base condition
    if num_disks == 0:
        return

    # Termination condition
    if num_disks == 1:
        print("{} {}".format(source, destination))
        return
    

    '''Just think of one iteration, rest the Recursion will take care!'''
    
    # Step 1: Move `num_disks - 1` from source to auxiliary
    tower_of_Hanoi_soln(num_disks - 1, source, destination, auxiliary)
    
    # Step 2: Now you are left with the only largest disk at source. 
    # Move the only leftover disk from source to destination
    print("{} {}".format(source, destination))
    
    # Step 3: Move `num_disks - 1` from auxiliary to destination
    tower_of_Hanoi_soln(num_disks - 1, auxiliary, source, destination)
    
def tower_of_Hanoi(num_disks):
    tower_of_Hanoi_soln(num_disks, 'S', 'A', 'D')


# #### Compare your results with the following test cases
# * num_disks = 2
# 
#         solution 
#                 S A
#                 S D
#                 A D
#                 
# * num_disks = 3
# 
#         solution 
#                 S D
#                 S A
#                 D A
#                 S D
#                 A S
#                 A D
#                 S D
# 
# * num_disks = 4
#     
#         solution
#                 S A
#                 S D
#                 A D
#                 S A
#                 D S
#                 D A
#                 S A
#                 S D
#                 A D
#                 A S
#                 D S
#                 A D
#                 S A
#                 S D
#                 A D

# In[ ]:




