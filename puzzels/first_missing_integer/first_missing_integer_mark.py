
#
# Given an unsorted integer array, find the first missing positive integer.
# Your algorithm should run in O(n) time and use constant space.
# Input 1:

# A = [1,2,0] --> 3
# 
# A = [3,4,-1,1] --> 2
# 
# A = [-8,-7,-6] --> 1
#

def first_missing_int(arr):

    max_el = max(arr)+1
    MEM = [False for _ in range(max_el)]

    for el in arr:
        if el > 0:
            MEM[el] = True
    
    i = 1
    while i < len(MEM):
        if not MEM[i]:
            break

        i += 1
    
    return i

        
A = [1,2,0]
res = first_missing_int(A)
print(res)

A = [3,4,-1,1]
res = first_missing_int(A)
print(res)

A = [-8,-7,-6]
res = first_missing_int(A)
print(res)
