
'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

    Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
        The solution set must not contain duplicate quadruplets.

Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
'''

# First finds the permutations with length 2, then it uses 
# a map to find a pair of permutations summed up to the target value
def four_sum(arr, target):
    lookup = {}
    result = []
    for i in range(len(arr)):
        for j in range(len(arr)):
            if i != j:
                key = arr[i] + arr[j] 
                if key in lookup:
                    stored_indices = lookup[key]
                    if i not in stored_indices and j not in stored_indices:
                        sorted_res = sorted([arr[i], arr[j], arr[stored_indices[0]], arr[stored_indices[1]]])
                        if sorted_res not in result:
                            result.append(sorted_res)
                else:
                    lookup[target-key] = [i,j]
    return result



arr = [1, 0, -1, 0, -2, 2]
target = 0
res = four_sum(arr, target)
print(res)

        


