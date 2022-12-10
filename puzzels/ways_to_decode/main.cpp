#include <iostream>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

/**
 *
 * input: "123"
 * output: ABC, AU, LU --> 3
 */


/**
 *
 * time complexity: o(2^n)
 *
 */
int decode(const string& str, int i, int j )
{

  /// chosen subsequence shall be smaller than 26
  if (j - i == 2)
  {
    if ( str[i] - '0' > 2)
      return 0;

    int num = str[i] - '0' * 10 + str[j-1] - '0';
    if (num > 26)
      return 0;
  }

  if (j == str.size())
  {
    return 1;
  }

  if (j > str.size())
  {
    return 0;
  }

  return decode(str, j, j+1) + decode(str, j, j+2);
}


/**
 *
 * time complexity o(n)
 *
 */

int decodeWithMemory(const string& str, int i, int j, vector<vector<int>>& db )
{

  if (db[i][j] != -1)
    return db[i][j];

  /// chosen subsequence shall be smaller than 26
  if (j - i == 2)
  {
    if ( str[i] - '0' > 2)
      return 0;

    int b = str[j-1] - '0';
    int num = str[i] - '0' * 10 + b;
    if (num > 26)
      return 0;
  }

  if (j == str.size())
  {
    return 1;
  }

  if (j > str.size())
  {
    return 0;
  }

  db[i][j] = decode(str, j, j+1) + decode(str, j, j+2);
  return db[i][j];
}

int main() {
  string str = "121";
  std::cout << decode(str, 0, 0)<< std::endl;

  str = "1234";
  std::cout << decode(str, 0, 0)<< std::endl;

  vector<vector<int>> db(str.size(), vector<int>(str.size(), -1));
  std::cout << decodeWithMemory(str, 0, 0, db) << std::endl;

  return 0;
}
