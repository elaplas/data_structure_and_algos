
#include <iostream>


using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int val): value(val), next(nullptr){}
};


Node* reverseList(Node* linkedList)
{
    auto curNode = linkedList;
    Node* preNode = nullptr;
    Node* newHead;

    while (curNode)
    {
        if (!curNode->next){
            newHead = curNode;
        }
        auto tmp =  curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = tmp;
    }

    return newHead;
}



int main()
{
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    auto curNode = reverseList(head);

    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}