

'''
The idea is to use a 2D matrix where ith row represents the subsequence of "text"
from position 0 to i and jth column represents the subsequence of pattern 
from position 0 to j.

if the two characters at ith and jth are equal then the corresponding subsequences from 0 to i
and from 0 to j are matched if the corresponding subsequences from 0 to i-1 and from 0 to j-1 are
matched because the characters at i and j have no effect since they are 
equal and we can exclude them.

e.g. assuming that the subsequence of text at i position is "abcg" and the 
subsequence of pattern at position j is "ab*g", we can say text at i and 
pattern at j are matched if "abc" and "ab*"  are matched.


if the subsequence of pattern at position j is a wildcard character, then the 
subsequence of text at position i matches if one of the two following cases matches:

1- The wildcard indicates a zero subsequence:
e.g. assuming that the subsequence of text at i position is "ab" and the 
subsequence of pattern at position j is "ab*"; then, we can say text at i and 
pattern at j are matched if "ab" and "ab" (* represents zero sequence so it is deleted) are matched.

2- The ith character of text is a part of pattern:

e.g. assuming that the subsequence of text at i position is "abc" and the 
subsequence of pattern at position j is "ab*"; then, we can say text at i and 
pattern at j are matched if "ab" (c is part of wildcard character ('*') so it 
is deleted) and "ab*" are matched.

if the two characters at ith and jth are not equal then the corresponding subsequences from 0 to i
and from 0 to j are not matched. 


'''
def wildcard_matcher(pattern, text):

    rows = len(text) + 1
    cols = len(pattern) + 1
    lookup = [[False for _ in range(cols)] for _ in range(rows)]

    # Two zero sequences '' and '' are already matched
    lookup[0][0] = True

    # Wildcard character at the beginning of pattern and '' of text are already matched 
    if pattern[0] == '*':
        lookup[0][1] = True

    for i in range(1, rows):
        for j in range(1, cols):

            if text[i-1] == pattern[j-1]:
                lookup[i][j] = lookup[i-1][j-1]

            elif pattern[j-1] == '*':
                lookup[i][j] = lookup[i][j-1] or lookup[i-1][j]
            
            else:
                lookup[i][j] = False
    
    return lookup[-1][-1]


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