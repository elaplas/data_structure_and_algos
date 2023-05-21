def lcs(x, y):
    return lcs_helper(x,0,y, 0)


def lcs_helper(x, i, y, j):

    if i >= len(x) or j >= len(y):
        return 0


    if x[i] != y[j] and i != j:
        return 1 + lcs_helper(x, i+1, y, j+1)
    else:
        return max(lcs_helper(x, i+1, y, j), lcs_helper(x, i, y, j+1))


def lcs_with_str(x, y):
    return lcs_with_str_helper(x, 0,y, 0)


def lcs_with_str_helper(x, i, y, j):

    if i >= len(x) or j >= len(y):
        return 0, ""

    if  x[i] == y[j] and i != j:
        res = lcs_with_str_helper(x, i+1, y, j+1)
        return 1 + res[0] , x[i] + res[1]
    else:
        res_1  = lcs_with_str_helper(x, i+1, y, j)
        res_2 = lcs_with_str_helper(x, i, y, j+1)
        if res_1[0] > res_2[0]:
            return res_1
        else:
            return res_2

str1 = "AABEBGCC"
str2 ="AABEBGCC"
res = lcs(str1, str2)
print(res)


str1 = "AABEBGCC"
str2 ="AABEBGCC"
res = lcs_with_str(str1, str2)
print(res)