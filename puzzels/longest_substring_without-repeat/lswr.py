

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
* output: 5 --> (abcdg)
*
"""



def lswr(str_x):
    lookup = set()
    res = ""
    for char in str_x:
        if char not in lookup:
            lookup.add(char)
            res += char
    return res, len(lookup)


str_x = "bbbbbbbbbbb"
res = lswr(str_x)
print(res)


str_x = "abcabcc"
res = lswr(str_x)
print(res)


str_x = "abacadag"
res = lswr(str_x)
print(res)