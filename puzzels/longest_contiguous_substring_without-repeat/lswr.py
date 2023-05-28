

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

