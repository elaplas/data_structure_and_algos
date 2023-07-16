#include <iostream>
#include "dynamic_stack.h"
#include "static_stack.h"
#include "balanced_brackets.h"



int main() {

    Stack<int> st;
    for(int i=0; i < 10; ++i)
    {
        st.push(i);
    }

    while (!st.empty())
    {
        std::cout<<st.pop()<<"\n";
    }

    StaticStack<int, 10> st;
    for(int i=0; i < 15; ++i)
    {
        st.push(i);
    }

    while (!st.empty())
    {
        std::cout<<st.pop()<<"\n";
    }

  ///
  BalancedBrackets balancedBrackets;
  std::string myString1 {"{([])}"};
  std::string myString2 {"{([](}"};


  std::cout<<balancedBrackets.isBalanced(myString1)<<std::endl;
  std::cout<<balancedBrackets.isBalanced(myString2)<<std::endl;

  std::cout<< -12%10<<std::endl;

  return 0;
}
