#include <iostream>

class A{
 public:
  int x;
};



int main() {



  /// The content of pointer cannot be changed if it precedes with keyword "const" but the pointer itself can change
  const int* x = new int(3);
  *x = 6;
  x = nullptr;

  /// The content of pointer cannot be changed if the declaration precedes with keyword "const"
  /// The pointer itself can change if the declaration is followed with keyword "const"
  const int* const y = new int(5);
  y = nullptr;
  *y = 7;


  const A* a = new A();
  a->x = 6;
  a = nullptr;


  const A* const a1 = new A();
  a1->x = 6;
  a1 = nullptr;

  int const* c;
  *c = 10;
  c = nullptr;



  std::cout << "Hello, World!" << std::endl;
  return 0;
}
