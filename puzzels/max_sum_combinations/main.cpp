#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

/// time complexity: o(n^2)
/// space complexity: o(n^2)
vector<int> getLargestSumCombinations(vector<int> A, vector<int> B, int k)
{
  vector<int> combinations;
  // Find all possible combinations
  for (int i=0; i<A.size(); ++i)
  {
    for (int j=0; j < B.size(); ++j)
    {
      combinations.push_back(A[i] + B[j]);
    }
  }
  sort(combinations.rbegin(), combinations.rend());

  return vector<int>(combinations.begin(), combinations.begin() + k);
}


/// time complexity: o(n^2)
/// space complexity: o(n)
vector<int> getLargestSumCombinationsOptimizedSpace(vector<int> A, vector<int> B, int k)
{
  priority_queue<int, vector<int>, greater<int>> minHeap;
  vector<int> res;

  for (int i=0; i < A.size(); ++i)
  {
    for (int j=0; j < B.size(); ++j)
    {
      minHeap.push(A[i] + B[j]);
      if (minHeap.size() > k)
        minHeap.pop();
    }
  }

  while(k>0)
  {
    res.push_back(minHeap.top());
    minHeap.pop();
    --k;
  }

  sort(res.rbegin(), res.rend());
  return res;
}


/// time complexity: o(nlogn)
/// space complexity: o(n)
vector<int> getLargestSumCombinationsOptimizedSpaceOptimizedRunTime(vector<int> A, vector<int> B, int k)
{
  priority_queue<tuple<int, int, int>> maxHeap;
  vector<int> res;
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(),B.rend());

  maxHeap.push(tuple<int, int, int>(A[0]+B[0], 0, 0));

  while(k>0)
  {
    auto element = maxHeap.top();
    auto sum = get<0>(element);
    auto i = get<1>(element);
    auto j = get<2>(element);
    maxHeap.pop();
    if (i==0)  /// handle edge case (ignore the same pair of indices that are already in maxHeap)
      maxHeap.push(tuple<int, int, int>(A[i]+B[j+1], i, j+1));
    maxHeap.push(tuple<int, int, int>(A[i+1]+B[j], i+1, j));
    res.push_back(sum);
    --k;
  }

  return res;
}

int main() {
  vector<int> A{1,3,5, 0};
  vector<int> B{2,6,3, 7};


  auto res = getLargestSumCombinations(A, B, 2);
  for (int i=0; i<res.size(); ++i)
  {
    cout<< res[i] << ", ";
  }

  cout<<"\n";
  auto res1 = getLargestSumCombinationsOptimizedSpace(A, B, 2);
  for (int i=0; i<res1.size(); ++i)
  {
    cout<< res1[i] << ", ";
  }

  cout<<"\n";
  auto res2 = getLargestSumCombinationsOptimizedSpaceOptimizedRunTime(A, B, 2);
  for (int i=0; i<res2.size(); ++i)
  {
    cout<< res2[i] << ", ";
  }


  return 0;
}
