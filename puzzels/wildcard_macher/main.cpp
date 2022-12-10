#include <iostream>
#include "wildcard.h"

using namespace std;


int main() {

  string pattern = "baaaba*b";
  string text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;

  pattern = "**baaabab";
  text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;

  pattern = "**baaaba*";
  text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;


  pattern = "*******baaaba*";
  text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;


  pattern = "ba?aba**********";
  text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;


  pattern = "baaababn";
  text = "baaabab";
  cout << IsMatched(text, pattern)<< std::endl;

  return 0;
}
