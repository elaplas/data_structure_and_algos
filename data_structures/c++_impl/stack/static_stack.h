//
// Created by z639627 on 2/28/21.
//

#ifndef STACK_STATIC_STACK_H_
#define STACK_STATIC_STACK_H_


template<class Type, int MAX_SIZE>
class StaticStack {

 public:

  int modN(int a, int b)
  {
    int res = a%b;
    if (res<0)
    {
      res +=b;
    }
    return res;
  }

  void pop()
  {
    top_ = modN(top_-1, MAX_SIZE);
  }

  void push(const Type& value)
  {
    top_ = (top_+1)%MAX_SIZE;
    data_[top_] = value;
  }

  Type& top()
  {
    return data_[top_];
  }

 private:
  Type data_[MAX_SIZE];
  int top_{MAX_SIZE-1};
};

#endif //STACK__STATIC_STACK_H_
