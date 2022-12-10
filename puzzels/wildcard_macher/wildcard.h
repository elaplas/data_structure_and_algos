#ifndef WILDCARD_MACHER__WILDCARD_H_
#define WILDCARD_MACHER__WILDCARD_H_
#include <string>
#include <vector>

using namespace std;



void IsMatched(string text, string pattern, int sText, int sPattern, bool& res)
{

  if (res)
    return;

  for (int i=sPattern; i < pattern.size(); ++i)
  {

    if (sText > text.size()-1)
      return;

    if (pattern[i] == '*')
    {
      for (int j=sText; j < text.size(); ++j)
      {
        IsMatched(text, pattern, j, i+1, res);
      }
    }
    else if (pattern[i] == text[sText] || pattern[i] == '?')
    {
      ++sText;
    }
    else if (pattern[i] != text[sText] && pattern[i] != '?')
      return;
  }

  res = true;

}

bool IsMatched(string text, string pattern)
{
  bool res = false;
  IsMatched(text, pattern, 0, 0, res);
  return res;
}

#endif//WILDCARD_MACHER__WILDCARD_H_
