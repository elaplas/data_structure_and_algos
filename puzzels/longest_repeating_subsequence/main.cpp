#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**
 * input: AABEBGCC
 * ABC is the longest repeating substring
 *
 * output: length of ABC: 3
 *
 * this problem is actually like finding the longest common substring
 *
 */


/// Recursive --> top-down
int findLongestRepeating(const string str, int i, int j)
{
  if (i > str.size()-1 || j > str.size()-1)
    return 0;

  if (str[i] == str[j] && i != j)
  {
    return 1 + findLongestRepeating(str, i+1, j+1);
  }
  else
  {
    return max(findLongestRepeating(str, i+1, j), findLongestRepeating(str, i, j+1));
  }
}

/// Tabulation --> bottom-up

int findLongestRepeating(const string str)
{
  int db[str.size()+1][str.size()+1];
  memset(db, 0, str.size()+1 * str.size()+1);

  for (int i = 1; i < str.size(); ++i)
  {
    for (int j = 1; j < str.size(); ++j)
    {

      if (str[i-1] == str[j-1] && i != j)
      {
        db[i][j] = 1 + db[i-1][j-1];
      }
      else
      {
        db[i][j] = max(db[i-1][j], db[i][j-1]);
      }
    }
  }

  return db[str.size()][str.size()];

}


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
