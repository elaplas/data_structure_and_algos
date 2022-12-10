#include <iostream>
#include <string>
#include <vector>


using namespace std;

/**
 * minimum operations to edit a string to make a equal to another string
 *
 * operations:
 *  - remove a character from S1
 *  - replace a character of S1 with the corresponding one of S2
 *  - insert a character of S2 to S1
 *
 */

int EditDisRec(const string& S1, int indexS1,  const string& S2, int indexS2)
{

 if (indexS1 > S1.size() && indexS2 > S2.size())
   return 0;

 if (indexS1 > S1.size() && indexS2 < S2.size())
   return S2.size() - indexS2 ;

 if (indexS1 < S1.size() && indexS2 > S2.size())
   return S1.size() - indexS1;

  if (S1[indexS1] == S2[indexS2])
    return EditDisRec(S1, indexS1+1, S2, indexS2+1);
  else
    return 1 + std::min(std::min(EditDisRec(S1, indexS1+1, S2, indexS2), EditDisRec(S1, indexS1+1, S2, indexS2+1)), EditDisRec(S1, indexS1, S2, indexS2+1));
}

/**
 * Solving by dynamic programming, top-down approach without using memory
 *
 * time complexity = O(3^n)
 *
 */
int EditDis(const string& S1, const string& S2)
{
  int indexS1 = 0;
  int indexS2 = 0;
  return EditDisRec(S1, indexS1,  S2, indexS2);
}


int EditDisRecWithMem(const string& S1, int indexS1,  const string& S2, int indexS2)
{

  if (indexS1 > S1.size() && indexS2 > S2.size())
    return 0;

  if (indexS1 > S1.size() && indexS2 < S2.size())
    return S2.size() - indexS2 ;

  if (indexS1 < S1.size() && indexS2 > S2.size())
    return S1.size() - indexS1;

  if (S1[indexS1] == S2[indexS2])
    return EditDisRec(S1, indexS1+1, S2, indexS2+1);
  else
    return 1 + std::min(std::min(EditDisRec(S1, indexS1+1, S2, indexS2), EditDisRec(S1, indexS1+1, S2, indexS2+1)), EditDisRec(S1, indexS1+1, S2, indexS2));
}

/**
 * Solving by dynamic programming bottom-up approach with using memory
 *
 * time complexity = O(n*m)
 *
 */


int EditDisWithMem(string S1, string S2)
{
  int M = S1.size()-1;
  int N = S2.size()-1;
  vector<vector<int>> RT(M+2, vector<int>(N+2, 0));
  for (int i=M; i >= 0; --i)
  {
    for (int j=N; j >= 0; --j)
    {
      if (j == N && M > N)
        RT[i][j] = M-j;

      else if (i == M && N > M)
        RT[i][j] = N-i;

      else if (S1[i] == S2[j])
        RT[i][j] = RT[i+1][j+1];
      else
      {
        RT[i][j] = 1+min(min(RT[i+1][j+1], RT[i+1][j]), RT[i][j+1]);
      }
    }
  }

  return RT[0][0];
}

/**
 * Solving by dynamic programming bottom-up approach with using memory
 *
 * time complexity = O(2*m) = O(m)
 *
 */

int EditDisWithLessMem(const string& S1, const string& S2)
{
  int M = S1.size()-1;
  int N = S2.size()-1;
  vector<vector<int>> RT(2, vector<int>(N+2, 0));
  for (int i=M; i >= 0; --i)
  {
    for (int j=N; j >= 0; --j)
    {
      if (j == N && M > N)
        RT[i%2][j] = M-j;

      else if (i == M && N > M)
        RT[i%2][j] = N-i;

      else if (S1[i] == S2[j])
        RT[i%2][j] = RT[(i+1)%2][j+1];
      else
      {
        RT[i%2][j] = 1+min(min(RT[(i+1)%2][j+1], RT[(i+1)%2][j]), RT[i%2][j+1]);
      }
    }
  }

  return RT[0][0];
}

int main() {

  string S1 = "abcc";
  string S2 = "alc";
  std::cout << EditDis(S1, S2) << std::endl;
  std::cout << EditDisWithMem(S1, S2) << std::endl;
  std::cout << EditDisWithLessMem(S1, S2) << std::endl;

  S1 = "a";
  S2 = "aclmn";
  std::cout << EditDis(S1, S2) << std::endl;
  std::cout << EditDisWithMem(S1, S2) << std::endl;
  std::cout << EditDisWithLessMem(S1, S2) << std::endl;

  S1 = "aclmn";
  S2 = "a";
  std::cout << EditDis(S1, S2) << std::endl;
  std::cout << EditDisWithMem(S1, S2) << std::endl;
  std::cout << EditDisWithLessMem(S1, S2) << std::endl;

  S1 = "aac";
  S2 = "abac";
  std::cout << EditDis(S1, S2) << std::endl;
  std::cout << EditDisWithMem(S1, S2) << std::endl;
  std::cout << EditDisWithLessMem(S1, S2) << std::endl;


  return 0;
}
