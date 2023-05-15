#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>



using namespace std;


/**
 * input: cat, dog, god, tca
 * output: [[0, 3], [1,2]]
 *
 * Hint: Anagram: a word formed by rearranging the letters of another
 *
 */


vector<vector<int>> FindAnagrams(const vector<string>& words)
{

  unordered_map<string, vector<int>> myMap;
  vector<vector<int>> res;
  for (int i=0; i<words.size(); ++i)
  {
    string word = words[i];
    sort(word.begin(), word.end());

    if (myMap.find(word) != myMap.end() )
    {
      myMap[word].push_back(i);
    }
    else
    {
      vector<int> vec{i};
      myMap[word] = vec;
    }
  }

  for (const auto el: myMap)
  {
    res.push_back(el.second);
  }
  return res;
}



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
