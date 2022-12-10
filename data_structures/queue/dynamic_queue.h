//
// Created by z639627 on 2/27/21.
//

#ifndef QUEUE__DYNAMIC_QUEUE_H_
#define QUEUE__DYNAMIC_QUEUE_H_

template<class Type>
struct Node
    {
  Node* next;
  Type data_;
  Node(const Type& data )
  {
    data_=data;
  }
    };

template<class Type>
class DynamicQueue {

 public:
  typedef struct Node<Type> Node;

  void push(const Node& node)
  {
    Node* newNode= new Node(node);
    if(back_ == nullptr)
    {
      front_ = back_ = newNode;
    }
    else
    {
      back_->next=newNode;
      back_=newNode;
    }
  }

  void pop()
  {
    if(front_== nullptr)
    {
      return;
    }
    Node* oldFront = front_;
    front_=front_->next;
    delete oldFront;
  }

  const Node& operator[](int index) {
    int counter = 0;
    Node *current{front_};
    while (counter != index) {
      ++counter;
      current = current->next;
    }
    return *current;
  }

  const Type& front()
  {
    return front_->data_;
  }

  const Type& back()
  {
    return back_->data_;
  }

 private:
  Node* front_{nullptr};
  Node* back_{nullptr};
};

#endif //QUEUE__DYNAMIC_QUEUE_H_
