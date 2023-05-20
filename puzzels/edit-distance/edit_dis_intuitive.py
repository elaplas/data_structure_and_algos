

# Intuitive Recursive approach without memo - exponential time complexity O(6^n)
def min_ops(A, i, B, j):

    if A == B:
        return 0
    
    if i < len(A) and j < len(B):
        if A[i] == B[j]:
            return min_ops(A, i+1, B, j+1)
        else:
            # Replace characters
            new_A = A[:i] + B[j] + A[i+1:]
            res_1 = 1 + min_ops(new_A, i+1, B, j+1)
            new_B = B[:j] + A[i] + B[j+1:]
            res_2 = 1 + min_ops(A, i+1, new_B, j+1)
            # Remove characters
            new_A = A[:i] + A[i+1:]
            res_3 = 1 + min_ops(new_A, i, B, j)
            new_B = B[:j] + B[j+1:]
            res_4 = 1 + min_ops(A, i, new_B, j)
            # Add characters
            new_A = A[:i] + B[j] + A[i:]
            res_5 = 1 + min_ops(new_A, i+1, B, j+1)
            new_B = B[:j] + A[i] + B[j:]
            res_6 = 1 + min_ops(A, i+1, new_B, j+1)
            return min(res_1, res_2, res_3, res_4, res_5, res_6)

    if i >= len(A) and j < len(B):
        return len(B) - j
    elif i < len(A) and j >= len(B):
        return len(A) -i
    else:
        return 0

A = "aa"
B = "aaa"
res = min_ops(A, 0, B, 0)
print(res)

A = "abaabbbbabaabaa"
B = "aaaababa"
res = min_ops(A, 0, B, 0)
print(res) 

A = "aab"
B = "abbbaababbbbaa"
res = min_ops(A, 0, B, 0)
print(res)

#A="bbaaaaaabbaabbabaaaa"
#B="abbaababbaababbaaaba"
#res = min_ops(A, 0, B, 0)
#print(res)



