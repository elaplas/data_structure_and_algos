#include <iostream>
#include <string>

using namespace std;


int IsMatch(const string A, const string B) {

  bool matched = true;
  int i = 0;
  bool starInA = false;
  bool starInB = false;

  while(i < A.size() && i < B.size())
  {
    if (A[i] == '*')
      starInA = true;

    if (B[i] == '*')
      starInB = true;

    if (A[i] != B[i] && A[i] != '*' && B[i] != '*' && A[i] != '?' &&
        B[i] != '?')
    {
      if (A[i] != B[i])
        int kir =0;
      matched = false;
      break;
    }

    if(( A[i] == '*' && i == A.size()-1) || (B[i] == '*' && i == B.size()-1))
    {
      break;
    }
    ++i;
  }

  if(matched && i == A.size() && A.size() < B.size() )
  {
    if (!starInA)
      matched = false;
  }

  int kir = B.size();
  int kir1 = A.size();

  if(matched && i == B.size() && B.size() < A.size() )
  {
    if (!starInB)
      matched = false;
  }

  return matched;
}

int main() {
  string A = "cc";
  string B = "?";
  std::cout << IsMatch(A, B) << std::endl;
  return 0;
}
