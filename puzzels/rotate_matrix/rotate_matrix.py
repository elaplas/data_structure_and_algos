

"""
You are given a N x N 2D matrix A representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place. 

input:

[
    [1, 2],
    [3, 4]
]

output:

[
    [3, 1],
    [4, 2]
]

"""





"""
idea: transpose and then change the columns of the matrix.

Hint: in upper triangle of matrix rows are smaller than the cols
Hint: in lower triangle of matrix rows are bigger than the cols

"""




def rotate_matrix(matrix):

    rows = len(matrix)
    cols = len(matrix[0])
    # transpose the matrix
    for row in range(rows):
        for col in range(cols):
            if row != col and row < col:
                tmp = matrix[row][col] 
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = tmp
    # Change cols
    for row in range(rows):
        for col in range(cols//2):
            tmp = matrix[row][col] 
            matrix[row][col] = matrix[row][(cols-1)-col]
            matrix[row][(cols-1)-col] = tmp
    
    return matrix


matrix = [
    [1, 2],
    [3, 4]
]
res = rotate_matrix(matrix)
print(res)
    