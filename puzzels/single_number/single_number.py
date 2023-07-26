

# Single Number Leetcode Solution – We are given 
# a non-empty array of integers and need to find 
# an element that appears exactly once. It is given
# in the question that every element appears twice except for one.

# Input: nums = [2,2,1]
# Output: 1

# Input: nums = [4,1,2,1,2]
# Output: 4

# This question is very easy if there were no constraints about the time and space complexity.

#In this case, there are multiple ways to solve this question.

# We can keep a hashmap and count the number of times an element appears. 
# We can run a loop on hashmap and print the element having the count as 1.
# We can sort the elements and check if a[i] ≠ a[i-1] & a[i]≠ a[i+1] 
# (assuming we take care of the first and last element), for i in size of array n and print a[i]

# The only way to solve this problem following the given constraint is to use the concept of XOR.

# Concept
#
#    XOR of zero and some bit returns that bit
#        a^0 = a
#    XOR of two same bits returns 0
#        a^a = 0
#    XOR of a^b^a for some bits a and b returns b
#        a^b^a = (a^a)^b = 0^b = b
#
# So we can XOR all bits together to find the unique number.

def find_single_number(arr):
    res = 0

    for el in arr:
        res ^= el
    return res

arr = [2,2,4,4,6,7,6]
res = find_single_number(arr)
print(res)