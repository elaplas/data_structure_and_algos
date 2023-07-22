

"""
*
* input: "bbbbbbbbbbb"
* output: 1
*
* input: "abcabcc"
* output: 3
*
* input: "adababcddcc"
* output: 4 -->(abcd)
*
* input: "abacadag"
* output: 2 --> (ab) or 2 --> (ad)
*
"""


def lcswr(A):

    ptr = 0
    lookup = set()
    lcs = -1

    while ptr < len(A):

        if A[ptr] not in lookup:
            lookup.add(A[ptr])
            ptr += 1
        else:
            if len(lookup) > lcs:
                lcs = len(lookup)
            lookup = set()

    return lcs


A = "abcabcxr"
res = lcswr(A)
print(res)



def lcswr(str_x):
    lookup = set()
    counter = 0
    cur_res = ""
    max_len = 0
    max_res = ""
    for char in str_x:
        if char not in lookup:
            counter += 1
            lookup.add(char)
            cur_res += char
        else:
            if counter > max_len:
                max_len = counter
                max_res = cur_res
            
            counter = 1
            cur_res = char
            lookup.clear()
            lookup.add(char)

    return max_res, max_len


str_x = "adabacag"
res = lcswr(str_x)
print(res)

