

"""


Given a 2D integer array A of size M x N, you need to find a path 
from top left to bottom right which minimizes the sum of all numbers along its path.



A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]   
                    ] 

output --> 8 -------> 1, 3, 2 
                            1
                            1
"""








# Recursive approach: in each step we have two choices => O(2^n) => exponential
def min_path_in_matrix(M):
    return min_path_in_matrix_helper(M, 0, 0, 0)


def min_path_in_matrix_helper(M, row, col, res):

    if row >= len(M) or col >= len(M[0]):
        return float('inf')

    if row == len(M)-1 and col == len(M[0])-1:
        return res + M[row][col]
    
    res1 = min_path_in_matrix_helper(M, row+1, col, res + M[row][col])
    res2 = min_path_in_matrix_helper(M, row, col+1, res + M[row][col])

    return min(res1, res2)

# Dynamic programming: i and j are b/w (0, n)x(0, n) so we can map them to a nxn lookup table and 
# store the result in each step. O(n^2) => polynomial

def  min_path_in_matrix_dp(A):

    rows = cols = len(A) +1
    MEM = [[0.0 for _ in range(cols)] for _ in range(rows)]
    MEM[rows-1] = [float('inf')] * cols
    
    for i in range(rows-1):
        MEM[i][cols-1] = float('inf')

    MEM[rows-1][cols-1] = 0
    MEM[rows-2][cols-1] = 0
    MEM[rows-1][cols-2] = 0

    for i in range(rows-2, -1, -1):
        for j in range(cols-2, -1, -1):

            MEM[i][j] = A[i][j] + min(MEM[i+1][j], MEM[i][j+1])

    return MEM[0][0]


M = [[0 for _ in range(3)] for _ in range(3)]
M[0] = [1,3,2]
M[1] = [4,3,1]
M[2] = [5,6,1]

res = min_path_in_matrix(M)
print(res)

res = min_path_in_matrix_dp(M)
print(res)


