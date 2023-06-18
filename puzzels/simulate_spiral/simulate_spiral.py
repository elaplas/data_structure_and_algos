

def simulate_spiral(n):

    dir = "right"
    row = col = 0
    counter = 1
    res = [ [0 for _ in range(n)] for _ in range(n) ]

    while counter <= n*n :

        res[row][col] = counter

        if dir == "right":
            col +=1 
            if col >= n or res[row][col] != 0:
                dir = "down"
                col -= 1
                row += 1
        elif dir == "down":
            row += 1
            if row >= n or res[row][col] != 0:
                dir = "left"
                row -= 1
                col -= 1
        elif dir == "left":
            col -= 1
            if col < 0 or res[row][col] != 0:
                dir = "up"
                col += 1
                row -= 1
        elif dir == "up":
            row -= 1
            if row < 0 or res[row][col] != 0:
                dir = "right"
                row += 1
                col += 1
        else:
            pass

        counter += 1

    return res


res = simulate_spiral(3)
print(res)

res = simulate_spiral(4)
print(res)

res = simulate_spiral(5)
print(res)