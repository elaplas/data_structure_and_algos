
#include <vector>
#include <iostream>




using namespace std;

struct Node{
    Node(int val): value(val), next(nullptr){}
    Node(): Node(int()){}
    int value;
    Node* next;
};


Node* makeSortedList(const vector<int>& vec)
{
    auto front = new Node(vec[0]);

    for (int i=1; i < vec.size(); ++i)
    {
        auto curNode = front;
        while (curNode->next && curNode->value < vec[i])
        {
            curNode = curNode->next;
        }

        if (curNode == front && vec[i] < front->value)
        {
            auto tmp = new Node(vec[i]);
            tmp->next = front;
            front = tmp;
            
        }
        else
        {
            auto tmp = curNode->next;
            curNode->next = new Node(vec[i]);
            curNode->next->next = tmp;
        }
    } 
    return front;
}


int main()
{

    vector<int> vec{3,5,7,2,1,8};
    auto front = makeSortedList(vec);
    auto curNode = front;
    while (curNode)
    {
        cout<<curNode->value<<"\n";
        curNode = curNode->next;
    }
   
    return 0;
}