#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



/**
 * input (a matrix of string showing relations b/w people. People are symbolized by indices)
 * output: number of groups that have direct or indirect relations for example if '0' is related to '1',
 *  and '1' is related to '2', then '0' and '1' are indirectly related
 *
 * input: [ "11000", "11100", "01100", "00010", "00001"]
 * output: three related groups: {[0,1,2], [3], [4]}
 *
 * input: [ "10000", "10000", "000100", "00010", "00001"]
 * output: five groups: {[0], [1], [2], [3], [4]}
 *
 */



int findRelatedGroups(const vector<string> related)
{
  /// store direct relations in hash map
  unordered_map<int, vector<int>> myMap;
  for (int i=0; i< related.size(); ++i ) {
    myMap[i] = vector<int>();
    for (int j = 0; j < related[i][j]; ++j) {
      if (i != j && related[i][j] - '0') {
        myMap[i].push_back(j);
      }
    }
  }

  /// merge groups if they are indirectly related
  bool merged = false;
  while(!merged)
  {
    merged = true;
    for (auto& el: myMap)
    {
      bool merging = false;
      for (int i=0; i<el.second.size(); ++i)
      {
        if (myMap.find(el.second[i]) != myMap.end() && el.second[i] != el.first)
        {
          el.second.insert(el.second.end(), myMap[el.second[i]].begin(), myMap[el.second[i]].end());
          myMap.erase(el.second[i]);
          merging=1;
          merged = false;
          break;
        }
      }
      if(merging)
        break;
    }
  }

  return myMap.size();
}

int main() {

  vector<string> related {"11000", "11100", "01100", "00010", "00001"};
  std::cout << "number of groups: "<<  findRelatedGroups(related) <<std::endl;

  vector<string> related1 {"10000", "01000", "00100", "00010", "00001"};
  std::cout << "number of groups: "<<  findRelatedGroups(related1) <<std::endl;

  vector<string> related2 {"11000", "11100", "01110", "00110", "00001"};
  std::cout << "number of groups: "<<  findRelatedGroups(related2) <<std::endl;

  return 0;
}
