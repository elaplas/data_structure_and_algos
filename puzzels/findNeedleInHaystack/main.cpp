#include <iostream>
#include <string>

using namespace std;


/**
 *
 * hayStack: "I am Ebi Goodarzi and work in ZKM"
 * needle: "Ebi"
 *
 * output: 5 ---> index of first occurrence of needle
 *
 */


int FindNeedleInHayStack(const string& hayStack, const string& needle)
{
  int res = -1;
  for (int i=0; i<hayStack.size(); ++i)
  {
    int counter=0;
    for (int j=0; j<needle.size(); ++j)
    {
      if (hayStack.size() - i >= needle.size())
      {
        if (hayStack[i+j] == needle[j])
          ++counter;
      }
    }
    if (counter == needle.size())
    {
      res = i;
      break;
    }
  }
  return res;
}



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
