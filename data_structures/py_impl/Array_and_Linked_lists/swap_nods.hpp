
#include <iostream>



using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int val): value(val), next(nullptr){}
};


Node* swap_node_i_and_j(Node* linkedList, int i, int j)
{
    Node* curNode = linkedList;
    Node* preNode = nullptr;
    Node* node_i = nullptr;
    Node* preNode_i = nullptr;
    Node* node_j = nullptr;
    Node* preNode_j = nullptr;

    int count = 0;


    while (curNode){

        if (count == i)
        {
            preNode_i = preNode;
            node_i = curNode;
        }

        if (count == j)
        {
            preNode_j = preNode;
            node_j = curNode;
        }

        ++count;
        preNode = curNode;
        curNode = curNode->next; 
    }

    if (j -i > 1)
    {
        preNode_i->next = node_j;
        preNode_j->next = node_i;
        auto tmp = node_i->next;
        node_i->next = node_j->next;
        node_j->next = tmp; 
    }
    else
    {
        preNode_i->next = node_j;
        preNode_j->next = node_j->next;
        node_j->next = preNode_j;
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

    auto curNode = swap_node_i_and_j(head, 2, 6);

    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}