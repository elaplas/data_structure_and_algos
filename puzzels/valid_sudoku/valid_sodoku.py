

def valid_sudoku(A):

    # iterate 
    for i in range(len(A)):
        # row-wise memory
        MEM_ROW = [False for _ in range(10)]
        # column-wise memory
        MEM_COL = [False for _ in range(10)]
        # memory blocks for 3x3 boxes 
        MEM_BOXES= [ [False for _ in range(10)] for _ in range(9)]
        for j in range(len(A)):

            if A[i][j] != '.':

                if MEM_ROW[int(A[i][j])]: 
                    return False
                
                if MEM_BOXES[(i//3) * 3 + (j//3)][int(A[i][j])]:
                    return False
            
            if A[j][i] != '.':

                if MEM_COL[int(A[j][i])]:
                    return False
            

            if A[i][j] != '.':
                MEM_ROW[int(A[i][j])] = True
                MEM_BOXES[(i//3) * 3 + (j//3)][int(A[i][j])] = True

            if A[j][i] != '.':
                MEM_COL[int(A[j][i])] = True
        
    return True
            
board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

res = valid_sudoku(board)
print(res)

board = [["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

res = valid_sudoku(board)
print(res)
   


