#include <iostream>

using namespace std;







struct Node{
    Node(int val): value(val), next(nullptr){}
    Node(): Node(int()){}
    int value;
    Node* next;
};

struct NestedNode{
    NestedNode(Node* val): value(val), next(nullptr){}
    NestedNode(): NestedNode(nullptr){}
    Node* value;
    NestedNode* next;
};

Node* flattenSortedNestedLikedList(NestedNode* nestedList)
{
    if (!nestedList->next)
    {
        return nestedList->value;
    }
    

    auto flattenList = flattenSortedNestedLikedList(nestedList->next);

    Node* newFlattenList = nullptr;
    Node* headNewFlattenList;
    Node* curNode1 = flattenList;
    Node* curNode2 = nestedList->value;

    while(curNode1 && curNode2)
    {
        if (curNode1->value < curNode2->value)
        {
            if (!newFlattenList)
            {
                headNewFlattenList = newFlattenList = curNode1;
            }
            else
            {
                newFlattenList->next = curNode1;
                newFlattenList = newFlattenList->next;
            }
            curNode1 = curNode1->next;
        }
        else
        {
            if (!newFlattenList)
            {
                headNewFlattenList = newFlattenList = curNode2;
            }
            else
            {
                newFlattenList->next = curNode2;
                newFlattenList = newFlattenList->next;
            }
            curNode2 = curNode2->next;
        }
    }

    if (curNode1)
    {
        newFlattenList->next = curNode1;
    }

    if (curNode2)
    {
        newFlattenList->next = curNode2;
    }

    return headNewFlattenList;
}


int main()
{
    Node* head1 = new Node(2);
    head1->next = new Node(6);
    head1->next->next = new Node(8);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(7);

    Node* head3 = new Node(4);
    head3->next = new Node(5);
    head3->next->next = new Node(11);

    NestedNode* nestedList = new NestedNode(head1);
    nestedList->next = new NestedNode(head2);
    nestedList->next->next = new NestedNode(head3);
    auto curNode = flattenSortedNestedLikedList(nestedList);
    
    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}