#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/**
 * str1: ABCDET
 * str2: ANRCGT
 *
 * lcs: ACT
 * length of lcs: 3
 *
 */


/**
 * if we iterate through characters of two strings:
 *  -if two characters are the same, we have to check the remaining part of two strings
 *  -if two characters are not the same, we have to scip one of the characters and check the remaining part
 * this is a substructure problem meaning that the problem can be divided to sub-problems, so we go for dynamic programming:
 *
 * first try --> top-down approach --> recursive
 *
 */
int lcs(const string& str1, const string& str2, int i, int j)
{

  if (i > str1.size()-1 || j > str2.size()-1 )
  {
    return 0;
  }

  if (str1[i] == str2[j])
  {
    return 1 + lcs(str1, str2, i+1, j+1);
  }
  else
    return max(lcs(str1, str2, i+1, j), lcs(str1, str2, i, j+1));
}

/**
 *
 * -pointers i and j can only be in the range of n x m where n is the size of str1 and m2 the size of str2, so we can store all combinations
 * -If we start storing combinations we are only able to calculate the result of next combination if we have the previous result
 *
 * this sounds to go for bottom-up dynamic approach
 *
 */

int lsc(const string& str1, const string& str2)
{
  int db[str1.size()+1][str2.size()+1];
  memset(db, 0, str1.size()+1 * str2.size()+2);

  for (int i=1; i< str1.size(); ++i)
  {
    for (int j=1; j< str2.size(); ++j)
    {
      if ( str1[i-1] == str2[j-1] )
      {
        db[i][j] = 1 + db[i-1][j-1];
      }
      else
      {
        db[i][j] = max(db[i][j-1], db[i-1][j]);
      }
    }
  }

  return db[str1.size()][str2.size()];
}

/**
 *
 * -in each iteration of nested for loops, we access maximum two rows and m columns where m is the size of str2
 * so we can reduce db array and save some memory
 *
 */

int lscSpaceOptimized(const string& str1, const string& str2)
{
  int db[2][str2.size()+1];
  memset(db, 0, 2 * str2.size()+2);

  for (int i=1; i< str1.size(); ++i)
  {
    for (int j=1; j< str2.size(); ++j)
    {
      if ( str1[i-1] == str2[j-1] )
      {
        db[i%2][j] = 1 + db[(i-1)%2][j-1];
      }
      else
      {
        db[i%2][j] = max(db[i%2][j-1], db[(i-1)%2][j]);
      }
    }
  }
}


/**
 * print lcs
 *
 */
void printLsc(const string& str1, const string& str2)
{

  int n = str1.size();
  int m = str2.size();


  int db[n+1][m+1];
  memset(db, 0, n+1 * m+1);

  for (int i=1; i< n; ++i)
  {
    for (int j=1; j< m; ++j)
    {
      if ( str1[i-1] == str2[j-1] )
      {
        db[i][j] = 1 + db[i-1][j-1];
      }
      else
      {
        db[i][j] = max(db[i][j-1], db[i-1][j]);
      }
    }
  }

  int length_lcs = db[n][m];
  char lcs[length_lcs];
  int i = n;
  int j = m;
  int index = length_lcs-1;

  while( i > 0 && j > 0)
  {

    if( str1[i] == str2[j])
    {
      lcs[index] = str1[i];
      i--;
      j--;
      index--;
    }
    else if (db[i][j-1] > db[i-1][j])
    {
      j--;
    }
    else
    {
      i--;
    }
  }
  cout<<lsc<<endl;
}


int main() {

  return 0;
}
