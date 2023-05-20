#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

/// print vec of vec
void PrintVecOfVec(const vector<vector<int>>& vecOfVec)
{
  for (const auto vec: vecOfVec)
  {
    for (const auto v: vec)
    {
      cout<<v<<", ";
    }
    cout<<"\n";
  }
}


bool IsCombinationInRes(const vector<vector<int>>& vecOfVec, vector<int> vec )
{
  bool res = false;

  for (const auto& v: vecOfVec)
  {
    int counter = 0;
    for (int i=0; i< v.size(); ++i)
    {
      if (v[i] == vec[i])
      {
        ++counter;
      }
    }
    if (counter == vec.size())
    {
      res = true;
      break;
    }
  }
  return res;
}


/// naive approach
vector<vector<int>> find4Sum(const vector<int>& vec, int x)
{
  vector<vector<int>> res;
  int numOfCombinations{0};
  for (int i=0; i< vec.size(); ++i)
  {
    for (int j=0; j< vec.size(); ++j)
    {
      for (int k=0; k< vec.size(); ++k)
      {
        for (int l=0; l< vec.size(); ++l)
        {
          if ( j != i && k != i && k != j && l != i && l != j && l != k )
          {
            ++numOfCombinations;
            if (vec[i] + vec[j] + vec[k] + vec[l] == x )
            {
              vector<int> oncCombination{vec[i], vec[j], vec[k], vec[l]};
              sort(oncCombination.begin(), oncCombination.end());
              if (!IsCombinationInRes(res, oncCombination))
              {
                res.push_back(oncCombination);
              }
            }
          }
        }
      }
    }
  }
  cout<<"number of combinations: "<<numOfCombinations<<endl;
  return res;
}

///optimized algo based on hash map
vector<vector<int>> find4SumOptimized(const vector<int>& vec, int x)
{
  unordered_map<int, vector<int>> myMap;
  vector<vector<int>> res;
  for (int i=0; i< vec.size(); ++i)
  {
    for (int j =0; j < vec.size(); ++j)
    {
      if ( i != j)
      {
        int myKey = vec[i]+ vec[j];
        if (myMap.find(myKey) != myMap.end())
        {
          ///skip the current combination and the stored combination that have the same element
          if (i == myMap[myKey][0] || i == myMap[myKey][1] ||
              j == myMap[myKey][0] || j == myMap[myKey][1] )
          {
            continue;
          }
          vector<int> myVec{ vec[i], vec[j], vec[myMap[myKey][0]], vec[myMap[myKey][1]]};
          sort(myVec.begin(), myVec.end());
          ///skip repetitive combinations
          if (!IsCombinationInRes(res, myVec))
          {
            res.push_back(myVec);
          }
        }
        vector<int> myVec {i,j};
        myMap[x - (vec[i] + vec[j])] = myVec;
      }
    }
  }

  return res;
}

///optimized algo based on two pointers (a small bug is there)
vector<vector<int>> find4SumOptimizedLessSpace(vector<int>& vec, int x)
{
  vector<vector<int>> res;
  sort(vec.begin(), vec.end());
  for (int i=0; i<vec.size()-1; ++i)
  {
    int twoSum = vec[i] + vec[i+1];
    int start = 0;
    int end = vec.size()-1;
    while (start < end)
    {

      /// jump over the chosen elements
      if (end == i+1)
        end -= 2;
      if (start == i)
        start += 2;

      int fourSum = twoSum + vec[start] + vec[end];

      if (fourSum >= x)
        --end;
      if (fourSum < x)
        ++start;

      /// update fourSum after moving pointers
      fourSum = twoSum + vec[start] + vec[end];

      if (fourSum == x )
      {
        vector<int> myVec{vec[i], vec[i+1], vec[start], vec[end] };
        sort(myVec.begin(), myVec.end());
        ///scip repetitive combinations
        if (!IsCombinationInRes(res, myVec))
        {
          res.push_back(myVec);
        }
      }
    }
  }

  return res;
}


int main() {

  ///test naive algos
  vector<int> vec{1, 0, -1, 0, -2, 2};
  const auto& res = find4Sum(vec, 0);
  PrintVecOfVec(res);

  cout<<"........................"<<endl;
  ///test optimized algo based on hash map
  const auto& res1 = find4SumOptimized(vec, 0);
  PrintVecOfVec(res1);


  cout<<"........................"<<endl;
  const auto& res2 = find4SumOptimizedLessSpace(vec, 0);
  PrintVecOfVec(res2);
  return 0;
}
