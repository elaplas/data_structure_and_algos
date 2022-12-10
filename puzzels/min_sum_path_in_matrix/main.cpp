#include <iostream>
#include <vector>
#include <cstring>


using namespace std;


/**
 * input:   1, 2, 3
 *          4, 8, 2
 *          1, 5, 3
 *
 *
 * output:  1, 2,
 *                2
 *                3
 *
 */

int minSumPath(vector<vector<int>> A, int i, int j)
{

  if (i < 0 || j < 0)
    return 1000000; // big number

  if (i==0 && j ==0 )
    return A[i][j];
  else
    return A[i][j] + min( min(minSumPath(A, i-1, j), minSumPath(A, i, j-1)), minSumPath(A, i-1, j-1));

}


int minSumPathWithMemory(vector<vector<int>> A, int n, int m)
{

  int dp[A.size()][A.size()];

  dp[0][0] = A[0][0];

  /// initialize first row because we are following bottom-up approach and we need the previous row in dp
  for (int i=1; i < A.size(); ++i)
  {
    dp[0][i] = A[0][i] + dp[0][i-1];
  }

  /// initialize first column because we are following bottom-up approach and we need the previous column in dp
  for (int i=1; i < A.size(); ++i)
  {
    dp[i][0] = A[i][0] + dp[i-1][0];
  }

  for (int i =1; i < A.size(); ++i)
  {
    for (int j =1; j < A.size(); ++j)
    {
      dp[i][j] = A[i][j] + min( min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
    }
  }

  return dp[n][m];

}



int main() {
  vector<vector<int>> A;
  A.push_back({1,2,3});
  A.push_back({4,8,2});
  A.push_back({1,5,3});

  std::cout << minSumPath(A, 2, 2) << std::endl;
  std::cout << minSumPathWithMemory(A, 2, 2) << std::endl;
  return 0;
}
