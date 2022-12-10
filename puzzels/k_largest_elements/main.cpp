#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


/// Solution using usual sorting
vector<int> findKLargestElements(vector<int> A, int k)
{
  vector<int> res;
  sort(A.begin(), A.end(), [](int a, int b){
    return a>b;
  });

  for (int i=0; i <k; ++i)
  {
    res.push_back(A[i]);
  }
  return res;
}


/// Solution using heap data structure
/// Hint: syntax for minHeap  priority_queue<int, vector<int>, greater<int>> minHeap
/// Hint: syntax for maxHeap  priority_queue<int> maxHeap;
vector<int> findKLargestElementsWithHeap(vector<int> A, int k)
{
  vector<int> res;
  priority_queue<int> maxHeap;
  for (int i=0; i<A.size(); ++i)
  {
    maxHeap.push(A[i]);
  }
  while (k>0)
  {
    res.push_back(maxHeap.top());
    maxHeap.pop();
    --k;
  }

  return res;
}




int main() {

  vector<int> data{1,8,5,6,3,4,0,9,7,2};

  auto res = findKLargestElements(data, 3 );
  for (int i=0; i<res.size(); ++i)
  {
    cout<< res[i] << ", ";
  }
  cout<<"\n";
  auto res1 = findKLargestElementsWithHeap(data, 3 );
  for (int i=0; i<res1.size(); ++i)
  {
    cout<< res1[i] << ", ";
  }
  cout<<"\n";
}
