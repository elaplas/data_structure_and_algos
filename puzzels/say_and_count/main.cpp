#include <iostream>
#include <string>

using namespace std;



/// simulate the sequence: 1, 11, 21, 1211, ...


/**
 * input: 1
 * output: "11"
 *
 * input: 2
 * output: "21"
 *
 * input: 3
 * output: "1211"
 *
 *
 *
 */

string CountAndSay(int n)
{
  string res ="1";
  for (int i=0; i < n; ++i)
  {
    char pre = res[0];
    int counter =0;
    int c = 0;
    string tmp;
    while (c < res.size())
    {
      if (res[c] == pre)
        ++counter;
      else
      {
        tmp += to_string(counter);
        tmp += to_string(pre);
        counter = 0;
        pre = res[c];
      }

      /// Handel edge case
      if (c == res.size()-1)
      {
        tmp += to_string(counter);
        tmp += to_string(pre);
      }
    }
    res = tmp;
  }
  return res;
}



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
