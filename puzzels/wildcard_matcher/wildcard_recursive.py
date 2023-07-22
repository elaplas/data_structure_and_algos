

# time complexity: O(n) 
def wildcard_matcher(pattern, text):
    return wildcard_matcher_helper(pattern, text, 0, 0)


def wildcard_matcher_helper(pattern, text, i, j):
    
    if i >= len(pattern) and j >= len(text):
        return True
    
    if i >= len(pattern) and j < len(text):
        return False
    
    if i < len(pattern) and j >= len(text):
        return False
    
    if pattern[i] == '*' and i == len(pattern)-1:
        return True
    

    if pattern[i] == text[j]:
        return wildcard_matcher_helper(pattern, text, i+1, j+1)
    elif pattern[i] == '*':

        if pattern[i+1] == '*':
            return wildcard_matcher_helper(pattern, text, i+1, j)
        else:
            if pattern[i+1] == text[j]:
                return wildcard_matcher_helper(pattern, text, i+1, j)
            else:
                return wildcard_matcher_helper(pattern, text, i, j+1)
    else:
        return False


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


pattern = "ab*d"
text = "abfgmc"
res = wildcard_matcher(pattern, text)
print(res)