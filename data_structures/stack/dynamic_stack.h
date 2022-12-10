//
// Created by z639627 on 2/28/21.
//

#ifndef STACK_DYNAMIC_STACK_H_
#define STACK_DYNAMIC_STACK_H_

template<class Type>
class DynamicStack {

public:
  struct Node
      {
        Node* next_{nullptr};
        Type  value_;

        Node(Type value):value_(value){}
      };

 public:

  void pop()
  {
    if (!top_)
      return;

    Node* tmp = top_;
    top_ = top_->next_;
    delete tmp;
  }

  const Type& push(const Type& value)
  {
    Node* newNode = new Node(value);
    newNode->next_ = top_;
    top_ = newNode;
  }

   const Type& top()
   {
    top_->value_;
   }

 private:
  Node* top_{nullptr};
};


#endif //STACK_CMAKE_BUILD_DEBUG_DYNAMIC_STACK_H_
