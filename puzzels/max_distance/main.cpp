#include <iostream>
#include <vector>
#include <algorithm>
#include <map>





int FindMaxDistance(const std::vector<int>& A )
{
  std::vector<std::pair<int,int>> sorted;
  for (int i=0; i < A.size(); ++i)
  {
    sorted.push_back(std::make_pair(A[i], i));
  }

  std::sort(sorted.begin(), sorted.end());

  int ans=0;
  int indexMax = sorted[sorted.size()-1].second;

  for(int i = sorted.size()-2; i>=0; --i)
  {
    ans = std::max(ans, indexMax-sorted[i].second);
    indexMax = std::max(sorted[i].second, indexMax);
  }

  return ans;
}

int main() {
  std::vector<int> A{3,5,4,2};

  std::cout << FindMaxDistance(A) << std::endl;
  return 0;
}
