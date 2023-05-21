
"""
 * str1: ABCDET
 * str2: ANRCGT
 *
 * lcs: ACT
 * length of lcs: 3
 *
"""


 # idea:
 # if we iterate through characters of two strings:
 #  -if two characters are the same, we have to check the remaining part of two strings
 #  -if two characters are not the same, we have to skip one of the characters and check the remaining part
 # this is a substructure problem meaning that the problem can be divided to sub-problems --> recursive
 # time complexity: O(3^n) --> in each step, we have three choices --> 3^n --> exponential
def lcs(x, y):
    return lcs_helper(x,0,y, 0)


def lcs_helper(x, i, y, j):

    if i >= len(x) or j >= len(y):
        return 0


    if x[i] == y[j]:
        return 1 + lcs_helper(x, i+1, y, j+1)
    else:
        return max(lcs_helper(x, i+1, y, j), lcs_helper(x, i, y, j+1))

def lcs_with_str(x, y):
    return lcs_with_str_helper(x, 0,y, 0)


# idea: Dynamic Programming
#  - pointers i and j can only be in the range of n x m where n is the size of
#    str1 and m2 the size of str2, so we map the combinations i, j a matrix
#    then we iterate through the matrix for all combinations instead of forming them 
#    recursively and store the result in each iteration. The stored result is used 
#    for the next iteration. In this way we achieve a polynomial time complexity, 
#    which is a great achievement.
#  - time complexity: O(n*m) 
def lcs_dp(x,y):

    cols = len(y) + 1
    rows = len(x) + 1
    lookup = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(1, rows):
        for j in range(1, cols):
            if x[i-1] == y[j-1]:
                lookup[i][j] = 1 + lookup[i-1][j-1]
            else:
                lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1])

    return lookup[rows-1][cols-1]

    
# Returns both length of "lcs" and the string of "lcs". Time complexity: O(3^n)
def lcs_with_str_helper(x, i, y, j):

    if i >= len(x) or j >= len(y):
        return 0, ""

    if x[i] == y[j]:
        res = lcs_with_str_helper(x, i+1, y, j+1)
        return 1 + res[0] , x[i] + res[1]
    else:
        res_1  = lcs_with_str_helper(x, i+1, y, j)
        res_2 = lcs_with_str_helper(x, i, y, j+1)
        if res_1[0] > res_2[0]:
            return res_1
        else:
            return res_2

str1 = "ABCDET"
str2 ="ANRCGT"
res = lcs(str1, str2)
print(res)

str1 = "ABCDET"
str2 ="ANRCGT"
res = lcs_with_str(str1, str2)
print(res)


str1 = "ABCDET"
str2 ="ANRCGT"
res = lcs_dp(str1, str2)
print(res)
