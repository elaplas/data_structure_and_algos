#include <iostream>
#include <vector>

int MaxSumSubArray(std::vector<int> A)
{

  int sum=0;
  int max = -1000000000;

  for (int i=0; i < A.size(); ++i)
  {
    sum +=A[i];
    max = std::max(max, sum);
    if(sum <0)
      sum=0;
  }

  return max;

}


int main() {

  std::vector<int> A{1,-2, 4};
  std::vector<int> B{-2, -3, 4, -1, -2, 1, 5, -3};
  std::vector<int> C{1,2,3,-1,10};


  std::cout << MaxSumSubArray(A) << std::endl;
  std::cout << MaxSumSubArray(B) << std::endl;
  std::cout << MaxSumSubArray(C) << std::endl;
  return 0;
}
