#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/// If the range of array of numbers is unknown

int FindDuplicatesInArray1(const std::vector<int>& A)
{
  std::vector<int> history;
  int res =-1;
  for (int i=0; i<A.size(); ++i)
  {
    if(std::find(history.begin(), history.end(), A[i]) != history.end())
    {
      res =i;
      break;
    }
    history.push_back(A[i]);
  }
  return res;

}

/// If the range of array of numbers is known and b/W 0 - size of array

int FindDuplicatesInArray2(const std::vector<int>& A)
{
  bool visited[A.size()+1];
  std::memset(visited, false, sizeof(visited));
  int res =-1;
  for (int i=0; i<A.size(); ++i)
  {
    if(visited[A[i]])
    {
      res = i;
      break;
    }
    visited[A[i]]=true;
  }
  return res;

}



int main() {

  std::vector<int> A{1,3,4,1,0};

  std::cout << FindDuplicatesInArray1(A) << std::endl;
  std::cout << FindDuplicatesInArray2(A) << std::endl;
  return 0;
}
