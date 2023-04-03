#include <iostream>
#include "skip_list.h"

using namespace std;



int main() {

  skip_list<int> sk_list;

  sk_list.insert(30);

  sk_list.insert(40);

  sk_list.insert(70);

  sk_list.insert(50);

  struct K{

    char i = 'c';
  };

  return 0;
}
