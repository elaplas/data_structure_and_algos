
#include <iostream>


using namespace std;



struct Node
{
    int value;
    Node* next;

    Node(int val): value(val), next(nullptr){}
};


Node* skip_i_delete_j(Node* linkedList, int i, int j)
{
    Node* curNode = linkedList;

    while (curNode){

        for (int n=0; n< i-1; ++n)
        {
            if (curNode)
            {
               curNode = curNode->next; 
            }
        }

        Node* newHead = curNode;

        for (int n=0; n < j+1; ++n)
        {
            if (curNode)
            {
               curNode = curNode->next; 
            }
        }

        if (newHead)
            newHead->next = curNode; 
    }

    return linkedList; 
}



int main()
{
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next->next->next->next->next->next = new Node(12);

    auto curNode = skip_i_delete_j(head, 2, 3);

    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}