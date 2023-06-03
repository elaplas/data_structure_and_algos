

def wildcard_matcher(pattern, text):
    return wildcard_matcher_helper(pattern, text, 0, 0, 0)

"""

the idea is to return three values 0, 1 and 2 corresponding to 
"they are not matched", "they are matched" an "we don't know yet".

Hint: if we already encountered a wildcard character in the pattern 
and the characters at i and j aren't the same, the next character 
at j+1 in text may be equal to the character at i in the pattern, 
so we return "2" meaning that we don't know yet if the pattern and 
text are matched. 

"""
# time complexity: O(2^n) because in each step if there is a wildcard
# character then we need to try two possibility 
def wildcard_matcher_helper(pattern, text, i, j, star_seen):
    
    if i >= len(pattern) and j >= len(text):
        return 1
    
    if i >= len(pattern) and j < len(text):
        return 0
    
    if i < len(pattern) and j >= len(text):
        return 0
    
    if pattern[i] == '*' and i == len(pattern)-1:
        return 1
    

    if pattern[i] == text[j]:
        return wildcard_matcher_helper(pattern, text, i+1, j+1, 0)
    
    elif pattern[i] == '*':
        if pattern[i+1] == '*':
            return wildcard_matcher_helper(pattern, text, i+1, j, 1)
        else:
            res1 = wildcard_matcher_helper(pattern, text, i+1, j, 1)
            if res1 == 2:
                return  wildcard_matcher_helper(pattern, text, i, j+1, 1)
            else:
                return res1
    else:
        if star_seen:
            return 2
        else:
            return 0


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