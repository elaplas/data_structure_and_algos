
# time complexity: O(n) 
def wildcard_matcher(pattern, text):

    i = 0
    j = 0
    star_ptr = -1
    while i < len(text):

        if pattern[j] == '*' and j == len(pattern)-1:
            return True

        if pattern[j] == text[i]:
            i += 1
            j += 1
            # reset star pointer for the next wildcard character
            star_ptr = -1
        elif pattern[j] == '*':
            star_ptr = j
            j += 1
        else:
            if star_ptr != -1:
                j = star_ptr
                i +=1
            else:
                return False
    
    return True



pattern = "ab*c"
text = "abfgmc"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab*"
text = "abfgmc"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab*ln"
text = "abfgdlm"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab**ln"
text = "abfgdlm"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "abfgdln"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "fgdabfgdln"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "fgdafgdln"
res = wildcard_matcher(pattern, text)
print(res)
