#include <iostream>
#include <string>

using namespace std;


/**
 * input: "  the sky is  blue "
 * output: "blue is sky the"
 *
 *  Hint: spaces b/w words more than one shall be ignored
 *  Hint: trailing and leading spaces shall be ignored
 */

string reverseString(const string& str)
{
  string res;
  int start = 0;
  int end = str.size();
  for (int i=str.size()-1; i >0; --i) {

    if (str[i - 1] == ' ' && str[i] != ' ') {
      start = str[i];
      res += str.substr(start, end);
    }

    if (str[i - 1] != ' ' && str[i] == ' ') {
      end = str[i];
    }

    ///handle edge case
    if (i - 1 == 0 && str[i - 1] != ' ') {
      start = 0;
      res += str.substr(start, end);
    }
  }
  return res;
}



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
