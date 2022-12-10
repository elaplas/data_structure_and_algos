//
// Created by z639627 on 2/28/21.
//

#ifndef STACK__BALANCED_BRACKETS_H_
#define STACK__BALANCED_BRACKETS_H_

#include "stack"
#include "string"

class BalancedBrackets {

 public:

  int isBalanced(std::string  str)
  {
    stack_.empty();
    int res;
    for (int i=0; i < str.size(); ++i)
    {
      res = 0;
      if( str[i] == '(' ||
          str[i] == '[' ||
          str[i] == '{' )
      {
        stack_.push(str[i]);
      }
      else if (str[i] == ')')
      {
        if (check('('))
        {
          res=1;
          continue;
        }
        else
          break;
      }
      else if (str[i] == ']')
      {
        if (check('['))
        {
          res=1;
          continue;
        }
        else
          break;
      }
      else if (str[i] == '}')
      {
        if (check('{'))
        {
          res=1;
          continue;
        }
        else
          break;
      }
    }
    return res;
  }

  int check(char char1)
  {
    int res = 0;
    auto top = stack_.top();
    if(top == char1 )
    {
      stack_.pop();
      res = 1;
    }
    return res;
  }

 private:
  std::stack<char> stack_;
};

#endif //STACK__BALANCED_BRACKETS_H_
