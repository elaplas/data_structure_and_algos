#include <iostream>
#include "dynamic_stack.h"
#include "static_stack.h"
#include "balanced_brackets.h"



int main() {

  DynamicStack<int>  stack1;
  StaticStack<int, 5> stack2;

  for(int i=0; i<10; ++i)
  {
    stack1.push(i);
  }



  std::cout << stack1.top() << std::endl;

  stack1.pop();

  std::cout << stack1.top() << std::endl;

  stack1.push(11);

  std::cout << stack1.top() << std::endl;

  std::cout << "....................." << std::endl;


  for(int i=0; i<5; ++i)
  {
    stack2.push(i);
  }

  std::cout << stack2.top() << std::endl;

  stack2.pop();

  std::cout << stack2.top() << std::endl;

  stack2.push(11);

  std::cout << stack2.top() << std::endl;

  stack2.push(12);

  std::cout << stack2.top() << std::endl;

  ///
  BalancedBrackets balancedBrackets;
  std::string myString1 {"{([])}"};
  std::string myString2 {"{([](}"};


  std::cout<<balancedBrackets.isBalanced(myString1)<<std::endl;
  std::cout<<balancedBrackets.isBalanced(myString2)<<std::endl;

  std::cout<< -12%10<<std::endl;

  return 0;
}
