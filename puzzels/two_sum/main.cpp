#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> FindTwosum(const vector<int>& vec, int x)
{

  unordered_map<int, int> myMap;
  vector<int> res;
  for (int i=0; i < vec.size(); ++i)
  {
    if(myMap.find(vec[i]) != myMap.end())
    {
      res.push_back(myMap[vec[i]]);
      res.push_back(i);
      break;
    }
    myMap[x-vec[i]] = i;
  }
  return res;
}

int main() {
  vector<int>  vec{2,7,8,12,5,4};
  auto res =  FindTwosum(vec, 6);

  for (const auto& r: res)
    cout<<r<<", ";

  return 0;
}
