

# Simple approach - Dynamic programming approach - improved time complexity but worse case is still exponential O(3^n)
def min_ops(A, i,  B, j, lookup):

    if (i, j) in lookup:
        return lookup[(i,j)]

    if i >= len(A) and j >= len(B):
        return 0
    
    if i >= len(A) and j < len(B):
        return len(B) - j

    if i < len(A) and j >= len(B):
        return len(A) - i
    
    if A[i] == B[j]:
        return min_ops(A, i+1, B, j+1, lookup)
    else:
        res = 1 + min(min_ops(A, i+1, B, j, lookup), min_ops(A, i+1, B, j+1, lookup), min_ops(A, i, B, j+1, lookup))
        lookup[(i,j)] = res
        return res



A = "aa"
B = "aaa"
lookup = {}
res = min_ops(A, 0, B, 0, lookup)
print(res)

A = "abaabbbbabaabaa"
B = "aaaababa"
lookup = {}
res = min_ops(A, 0, B, 0, lookup)
print(res)

A = "aab"
B = "abbbaababbbbaa"
lookup = {}
res = min_ops(A, 0, B, 0, lookup)
print(res)

A="bbaaaaaabbaabbabaaaa"
B="abbaababbaababbaaaba"
lookup = {}
res = min_ops(A, 0, B, 0, lookup)
print(res)
