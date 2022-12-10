#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

std::string Number2String(const std::vector<int>& number)
{
  std::string str;
  for (int i=0; i<number.size(); ++i)
  {
    std::string tmp = std::to_string(number[i]);
    str = str + tmp;
  }
  return str;
}

int GetNumDigits(int number)
{
  int tmp =number;
  int numDigits = 0;
  while(tmp)
  {
    ++numDigits;
    tmp /=10;
  }
  return numDigits;
}

std::string FindLargestNumber(const std::vector<int>& number)
{
  std::vector<int> number1=number;
  std::sort(number1.begin(), number1.end(), [](int a, int b)
  {
    int numDigitsA = GetNumDigits(a);
    int numDigitsB = GetNumDigits(b);
    int fitA = a* std::pow(10, numDigitsB);
    int fitB = b* std::pow(10, numDigitsA);
    return fitA + b > fitB + a;
  }
  );

  return Number2String(number1);
}


int main() {
  std::vector<int> A{3, 30, 34, 5,9 };
  std::cout << FindLargestNumber(A) << std::endl;
  return 0;
}
