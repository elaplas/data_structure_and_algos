

"""
*
* input: "bbbbbbbbbbb"
* output: 1
*
* input: "abcabcc"
* output: 3
*
* input: "adababcddcc"
* output: 4
*
"""






def lswr(str_x):
    res = ""
    for character in str_x:
        if character not in res:
            res = res + character
    
    return len(res), res


str_x = "bbbbbbbbbbb"
res = lswr(str_x)
print(res)


str_x = "abcabcc"
res = lswr(str_x)
print(res)


str_x = "adababcddcc"
res = lswr(str_x)
print(res)