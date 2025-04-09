#!/usr/bin/env python
# coding: utf-8

# # Longest Common Subsequence
# 
# In text analysis,  it is often useful to compare the similarity of two texts (imagine if you were trying to determine plagiarism between a source and answer text). In this notebook, we'll explore one measure of text similarity, the **Longest Common Subsequence** (LCS).
# 
# > The Longest Common Subsequence is the longest sequence of letters that are *present* in both the given two strings in the same relative order.
# 
# **Example** - Consider the two input strings, `str1 = 'ABCD'` and `str2 = 'AXBXDX'`. The LCS will be `'ABD'` with the length as **3 letters**. It is because each of the letters `'A'` , `'B'`, and `'D'` are *present* in both the given two strings in the same relative order. Note that:
# * An LCS need not necessarily be a contiguous substring. 
# * There can be more than one LCS present in the given two strings. 
# * There can be many more common subsequences present here, with smaller length. But, in this problem we are concerned with the **longest** common subsequence. 
# 
# ---
# 

# ## Dynamic Programming Approach - Storing Pre-Computed Values
# 
# The LCS algorithm depends on looking at two strings and comparing them letter by letter. You can solve this problem in multiple ways. You can iterate through each letter in the strings and compare them, adding to your value for LCS as you go. 
# 
# ### Use a 2-D Matrix to Store the Relationship Between Letters of the Two Strings
# Recall that **dynamic programming** is all about breaking a larger problem into a smaller set of subproblems, and building up a complete result without having to repeat any subproblems. This approach assumes that you can split up a large LCS task into a combination of smaller LCS tasks. Let's look at the short example in more detail:
# * `A = 'ABCD'`
# * `B = 'BD'`
# 
# We can see right away that _letters_ `B` and `D` are in sequence in both the strings, therefore LCS is `'BD'`. The length of the LCS here is 2. 
# 
# **The Idea** - We can calculate the LCS length by looking at relationships between *each* letter of the two strings. Let's make a matrix with the letters of first string on top and the letters of second string on the left side:
# 
# <img src='notebook_ims/initial_matrix.png' width=40% />
# 
# This starts out as a matrix that has as many columns and rows as number of letters in the strings A and B **plus 1**, filled with zeros on the top and left sides. So, in this case, instead of a 2x4 matrix it is a 3x5. We can fill this matrix up by breaking it into smaller LCS problems. Start with first picking up one letter each from the given two strings, and then check if we have a common letter. Gradually, we will add up more letters from each string. 
# 
# #### Check Row 1
# The shortest subproblem: pick the starting letter of given two strings. We'll first ask, "what is the Longest Common Subsequence between these two letters 'A' and 'B'?" **Here, the answer is zero and we fill in the corresponding grid cell with that value.**
# 
# <img src='notebook_ims/matrix_2.png' width=35% />
# 
# Gradually, add up more letters from first string. The next question we'd ask, "what is the LCS between 'AB' and 'B'?" **Here, we have a match, and can fill in the appropriate value 1**.
# 
# <img src='notebook_ims/matrix_3_match.png' width=30% />
# 
# If we continue along this row, we can actually see that B only matches this one time, and any further questions, such as — What is the LCS between 'ABCD' and 'B'? — will have that same value, 1, due to the initial B-B match.
# 
# <img src='notebook_ims/matrix_4.png' width=35% />
# 
# #### Check Row 2
# Then, we move on to the second row. 'A' and 'BD' have 0 matches.
# 
# <img src='notebook_ims/matrix_5.png' width=25% />
# 
# We have 'AB' after picking one more letter from first string and 'BD' from second string, that have a B-B match, which we've already noted in the cell above. Gradually, we will add up more letters from first string, just like we did in the previous row. Finally, we have a match at the end D-D, where we can add 1 to our current highest match (1) to get a final LCS length as 2.
# 
# <img src='notebook_ims/matrix_6_complete.png' width=25% />
# 
# **The final LCS will have length as 2 letters**.
# 
# ## The Matrix Rules
# One thing to notice here is that, you can efficiently fill up this matrix one cell at a time. Each grid cell only depends on the values in the grid cells that are directly on top and to the left of it, or on the diagonal/top-left. The rules are as follows:
# * Start with a matrix that has one extra row and column of zeros.
# * As you traverse your string:
#     * If there is a match, fill that grid cell with the value to the top-left of that cell *plus* one. So, in our case, when we found a matching B-B, we added +1 to the value in the top-left of the matching cell, 0.
#     * If there is not a match, take the *maximum* value from either directly to the left or the top cell, and carry that value over to the non-match cell.
# 
# <img src='notebook_ims/matrix_rules.png' width=40% />
# 
# * After completely filling the matrix, **the bottom-right cell will hold the non-normalized LCS length value**.

# ## Calculate the length of longest common subsequence
# 
# Implement the function `lcs`; this should calculate the length of *longest common subsequence* of characters between two strings. 

# In[8]:

import numpy as np

## Intutive approch using dynamic programming
def lcs(S1, S2, M, counter, i, j):

    if M[i, j] != -1:
       return M[i, j]
    
    counter[0] += 1
    
    if i >= len(S1):
        return 0
    
    if j >= len(S2):
        return 0
    
    if S1[i]==S2[j]:
        res = 1 + lcs(S1, S2, M, counter,i+1, j+1)
        M[i, j] = res
        return res
    else:
        res = max(lcs(S1, S2, M, counter, i, j+1), lcs(S1, S2, M, counter, i+1, j))
        M[i, j] = res
        return res
    
A = "CATSINSPACETWO"
B= "DOGSPACEWHO"
M = np.array([-1.0 for _ in range((len(A)+1)*(len(A)+1))]).reshape((len(A)+1,len(A)+1))
counter = [0]
print(lcs(A, B, M , counter, 0, 0))
print(M)
print(counter) ## 172

## Intutive approch without dynamic programming 
def lcs(S1, S2, counter, i, j):
    
    counter[0] += 1
    
    if i >= len(S1):
        return 0
    
    if j >= len(S2):
        return 0
    
    if S1[i]==S2[j]:
        res = 1 + lcs(S1, S2, counter,i+1, j+1)
        M[i, j] = res
        return res
    else:
        res = max(lcs(S1, S2, counter, i, j+1), lcs(S1, S2, counter, i+1, j))
        M[i, j] = res
        return res
    
A = "CATSINSPACETWO"
B= "DOGSPACEWHO"
counter = [0]
print(lcs(A, B, counter, 0, 0))
print(counter) # 1982357

def lcs_naive(string_a, string_b):
    base = string_a
    
    combinations = all_combinations(base)
    combinations = sorted(combinations, key=lambda x: -len(x))
    print("combinations:", combinations)
    
    for combination in combinations:
        if is_included(combination, string_b):
            return combination
    
    return ""

def all_combinations(base_str):
    combinations = []
    all_combinations_recursive(base_str, "", combinations, 0)
    return combinations

    
def all_combinations_recursive(base_str, cur_combination, combinations, i):

    if i >= len(base_str):
        return
    
    
    if cur_combination not in combinations:
        combinations.append(cur_combination)
        
    if cur_combination + base_str[i] not in combinations:
        combinations.append(cur_combination + base_str[i])

    all_combinations_recursive(base_str, cur_combination + base_str[i], combinations, i+1)
    all_combinations_recursive(base_str, cur_combination, combinations, i+1)
   
    
    
def is_included(base_str, string_b):
    i = 0
    j = 0
    while i < len(base_str) and j < len(string_b):
        if base_str[i] == string_b[j]:
            i += 1
        
        j +=1
        
        if i == len(base_str):
            return True
        
    return False
    

output = lcs_naive("ABCD", "AXBXD")
print("output of lcs_naive: ", output)

def lcs(string_a, string_b):
    
    num_cols = len(string_a) + 1
    num_rows = len(string_b) + 1
    
    one_row = [0 for i in range(num_cols)]
    matrix = [one_row for i in range(num_rows)]
    
    # We should start from 1 to avoid negative indeces which cause the inverse elements to be taken
    for row in range(1, num_rows):
        for col in range(1, num_cols):
                
                # If two characters are the same, we take the previous element on the diagonal to
                # avoid accumulating by one for each similar comparsion e.g. str_a= "LBBBS" and str_b= "B"
                # in this case, if we don't take the diagonal element, then we end up with 3 which is incorrect 
                if string_a[col-1] == string_b[row-1]:
                    matrix[row][col] = matrix[row-1][col-1] + 1
                    
                else:
                    matrix[row][col] = max(matrix[row][col-1], matrix[row-1][col])
    print(matrix)
    return matrix[-1][-1]
    


# <span class="graffiti-highlight graffiti-id_y0t2nv1-id_u8bn9wq"><i></i><button>Hide Solution</button></span>

# In[1]:


def lcs(string_a, string_b):
    
    # initialize the matrix 
    lookup_table = [[0 for x in range(len(string_b) + 1)] for x in range(len(string_a) + 1)]
    
    # enumerate(str) returns a tuple containing the index and character in each iteration
    for char_a_i, char_a in enumerate(string_a):
        
        for char_b_i, char_b in enumerate(string_b):
            
            # If there is a match, 
            # fill that grid cell with the value to the top-left of that cell plus one
            if char_a == char_b:
                lookup_table[char_a_i + 1][char_b_i + 1] = lookup_table[char_a_i][char_b_i] + 1
                
            # If there is not a match, 
            # take the maximum value from either directly to the left or the top cell
            else:
                lookup_table[char_a_i + 1][char_b_i + 1] = max(
                    lookup_table[char_a_i][char_b_i + 1],
                    lookup_table[char_a_i + 1][char_b_i])

    # the bottom-right cell will hold the non-normalized LCS length value.
    return lookup_table[-1][-1]


# Test your function on a few test strings by running the cell, below.

# In[9]:


## Test cell

# Run this cell to see how your function is working
test_A1 = "WHOWEEKLY"
test_B1 = "HOWONLY"

lcs_val1 = lcs(test_A1, test_B1)

test_A2 = "CATSINSPACETWO"
test_B2 = "DOGSPACEWHO"

lcs_val2 = lcs(test_A2, test_B2)

print('LCS val 1 = ', lcs_val1)
assert lcs_val1==5, "Incorrect LCS value."
print('LCS val 2 = ', lcs_val2)
assert lcs_val2==7, "Incorrect LCS value."
print('Tests passed!')


# ## Time Complexity
# 
# What is the time complexity of the above implementation?

# <span class="graffiti-highlight graffiti-id_g3jsc1o-id_kxwtio3"><i></i><button>Hide Solution</button></span>

# In[ ]:


'''
The time complexity of the above implementation is dominated by the two nested loops, 
Let the length of string_a and string_b is `n` and `m` respectively. 
This would lead to a time complexity of O(n*m). 
But, in general, we can consider it as O(n*n) instead of O(n*m).
'''

