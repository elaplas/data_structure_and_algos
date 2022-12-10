#include <iostream>
#include <vector>

using namespace std;

/**
 * input: [100, 200, 150, 50, 700, 800, 500]
 * output: 800 - 50 : 750
 *
 */

int MaxProfit(const vector<int>& A)
{

  if (A.size() == 0 || A.size() == 1)
    return 0;

  int minStock = A[0];
  int maxProfit = A[1] - A[0];
  if (A[1] < minStock)
    minStock = A[1];

  for (int i =2; i < A.size(); ++i)
  {
    maxProfit = max(maxProfit, A[i] - minStock);

    if (A[i] < minStock)
      minStock = A[i];
  }

  if (maxProfit < 0)
    maxProfit = 0;

}

int main() {
  vector<int> stocks{100, 200, 150, 50, 700, 800, 500};
  std::cout << MaxProfit(stocks) << std::endl;
  return 0;
}
