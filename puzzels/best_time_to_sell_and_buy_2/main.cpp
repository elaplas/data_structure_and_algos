#include <iostream>
#include <vector>

using namespace std;

/**
 * input: [100, 200, 150, 50, 700, 800, 500]
 * output:  200-100: 100 , 800 - 50 : 750 --> 850
 *
 */

int MaxProfit(const vector<int>& A)
{

  if (A.size() == 0 || A.size() == 1)
    return 0;

  int i = 0;
  int buy = 0;
  int sell = 0;
  int profit = 0 ;

  while (i < A.size())
  {

    if (i >= A.size()-1)
      break;

    while( i < A.size()-1 && A[i+1] < A[i])
    {
      ++i;
      buy = i;
    }

    while( i < A.size()-1 && A[i+1] > A[i])
    {
      ++i;
      sell = i;
    }

    if (buy <= sell)
      profit += A[sell] - A[buy];

    if (profit < 0)
      profit = 0;
  }

  return profit;

}

int main() {
  vector<int> stocks{100, 200, 150, 50, 700, 800, 500};
  std::cout << MaxProfit(stocks) << std::endl;

  vector<int> stocks1{100, 200, 150, 50, 700, 800};
  std::cout << MaxProfit(stocks1) << std::endl;
  return 0;
}
