
#include <iostream>


using namespace std;

struct Node{
    Node(int val): value(val), next(nullptr){}
    Node(): Node(int()){}
    int value;
    Node* next;
};

Node* evenAfterOdd(Node* linkedList)
{
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    auto curNode = linkedList;

    while (curNode)
    {
        if (curNode->value%2 == 0)
        {
            if (!evenHead)
            {
                evenHead = evenTail = curNode;
            }
            else
            {
                evenTail->next = curNode;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if(!oddHead)
            {
                oddHead = oddTail = curNode;
            }
            else
            {
                oddTail->next = curNode;
                oddTail = oddTail->next;
            }
        }

        curNode = curNode->next;
    }

    if (evenHead)
    {
        oddTail->next = evenHead;
        return oddHead;
    }
    else
    {
        return oddHead;
    }
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    auto curNode = evenAfterOdd(head);
    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}