#include <iostream>

#define MAX(x,y,z) (x > y) && (x > z ) ? x : y > z ? y : z


int main() {
  float res = MAX(2.2,3.1,4.6);
  std::cout << res << std::endl;
  return 0;
}
