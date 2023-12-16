

class BIT2D:
    def __init__(self, matrix):
        self.rows = len(matrix)
        self.cols = len(matrix[0])
        self.matrix = matrix
        self.tree = [ [0 for _ in range(self.rows+1)] for _ in range(self.cols+1)]
        self.construct()

    def lsb(self, i):
        return i & (-i)

    def construct(self):
        for row in range(self.rows):
            for col in range(self.cols):
                i=row+1
                while i < self.rows+1:
                    j=col+1
                    while j < self.cols+1:
                        self.tree[i][j] += self.matrix[row][col]
                        j += self.lsb(j)
                    i += self.lsb(i)
    
    def update(self, row, col, value):
        self.matrix[row][col] = value
        diff = value - self.query(row, col, row, col)
        i=row+1
        while i < self.rows+1:
            j=col+1
            while j < self.cols+1:
                self.tree[i][j] += diff
                j += self.lsb(j)
            i += self.lsb(i)

    def query(self, row1, col1, row2, col2):
        return self.query_bit(row2, col2) + self.query_bit(row1-1, col1-1)- self.query_bit(row1-1, col2) - self.query_bit(row2, col1-1)

    def query_bit(self, row, col):
        i=row+1
        s = 0
        while i > 0:
            j=col+1
            while j > 0:
                s += self.tree[i][j]
                j -= self.lsb(j)
            i -= self.lsb(i)
        return s


def printMat(M):
    for i in range(len(M)):
        for j in range(len(M[0])):
            print(f"{M[i][j]}, ", end='')
        print("")


matrix = [
    [ 1,   2,  3, 4,  5],
    [ 6,   7,  8, 9,  10],
    [ 11, 12, 13, 14, 15],
    [ 16, 17, 18, 19, 20],
    [ 21, 22, 23, 24, 25],
]

bit2d = BIT2D(matrix)
printMat(bit2d.tree)
res = bit2d.query_bit(1,1)
print(res)
res = bit2d.query_bit(2,2)
print(res)
res = bit2d.query(1,1,3,3)
print(res)