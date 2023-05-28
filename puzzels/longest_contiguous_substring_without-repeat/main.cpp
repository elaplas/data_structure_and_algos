#include <iostream>
#include <vector>
#include <string>


using namespace std;


/**
 * input: "bbbbbbbbbbb"
 * output: 1
 *
 * input: "abcabcc"
 * output: 3
 *
 * input: "adababcddcc"
 * output: 4
 */

int FindLongestStr(const string& str)
{
  vector<bool> myMap(128, false);
  int maxLength = 0;

  for (int i=0; i < str.size(); ++i)
  {
    for(int j=i; j< str.size(); ++j)
    {
      if (myMap[str[j]] || j ==  str.size()-1)
      {
        maxLength = max(maxLength, j==str.size()-1 && str[i] != str[j]
                                       ? j-i+1 : j-i );
        myMap = vector<bool>(128, false);
        break;
      }
      else
      {
        myMap[str[j]] = true;
      }
    }
  }
  return maxLength;
}





int main() {

  auto res = FindLongestStr("abcabcbb");
  std::cout << res << std::endl;

  auto res1 = FindLongestStr("bbbbbbbb");
  std::cout << res1 << std::endl;

  auto res2 = FindLongestStr("abababcddcc");
  std::cout << res2 << std::endl;

  auto res3 = FindLongestStr("abcdefrtzio");
  std::cout << res3 << std::endl;

  auto res4 = FindLongestStr("abcahlm");
  std::cout << res4 << std::endl;

  return 0;
}
