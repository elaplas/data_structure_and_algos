
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>
#include <utility>


/***
 *  Merge k sorted linked lists and return it as one sorted list.
 * 
 *  1 -> 10 -> 20
 *  4 -> 11 -> 13
 *  3 -> 8 -> 9
 *  
 * 
 *  1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
 * 
 * 
*/




template<class T>
struct Node{

    T value;
    Node* next;

    Node():Node(T()){}
    Node(const T& val):value(val), next(nullptr){}
};

// O(nlogn)
Node<int>* mergeSortedLists1(const std::vector<Node<int>*>& sortedLists)
{
    std::vector<Node<int>*> allNodes;

    for (auto node: sortedLists)
    {
        auto curNode = node;
        while (curNode)
        {
            allNodes.push_back(curNode);
            curNode = curNode->next;
        }
    }

    std::sort(allNodes.begin(), allNodes.end(),
    [](Node<int>* a,
    Node<int>* b)
    {
        return a->value < b->value;
    });

    Node<int>* head = nullptr;
    Node<int>* curNode = nullptr;
    
    int counter = 0;
    for (auto node: allNodes)
    {
        if (!curNode)
        {
            head = curNode = node;
        }
        else
        {
            curNode->next = node;
            curNode = node;
        }
        ++counter;
        if (counter == allNodes.size())
        {
            curNode->next = nullptr;
        }
    }

    return head;
}

// O(nlogn)
Node<int>* mergeSortedLists2(const std::vector<Node<int>*>& sortedLists)
{
    using TNode = std::pair<int, Node<int>*>;
    std::priority_queue<TNode, std::vector<TNode>, std::greater<TNode>> minHeap;

    for (auto node: sortedLists)
    {
        auto curNode = node;
        while(curNode)
        {
            minHeap.push(std::pair<int, Node<int>*>(curNode->value, curNode));
            curNode = curNode->next;
        }
    }

    Node<int>* head = nullptr;
    Node<int>* curNode = nullptr;
    while (minHeap.size() > 0)
    {
        auto poppedNode = minHeap.top();
        minHeap.pop();
        if (!curNode)
        {
            curNode = head = poppedNode.second;
        }
        {
            curNode->next = poppedNode.second;
            curNode = curNode->next;
        }

        if (minHeap.size() == 0)
        {
            curNode->next = nullptr;
        }
    }

    return head;
}


// O(n)
Node<int>* mergeSortedLists3(const std::vector<Node<int>*>& sortedLists)
{
    using TNode = std::pair<int, Node<int>*>;
    std::priority_queue<TNode, std::vector<TNode>, std::greater<TNode>> minHeap;

    for (auto node: sortedLists)
    {
        minHeap.push(TNode(node->value, node));
    }

    Node<int>* head = nullptr;
    Node<int>* curNode = nullptr;

    while (minHeap.size())
    {
        auto poppedNode = minHeap.top();
        minHeap.pop();
        if (!curNode)
        {
            head = curNode = poppedNode.second;
        }
        else
        {
            curNode->next = poppedNode.second;
            curNode = curNode->next;
        }

        if (poppedNode.second->next)
        {
            minHeap.push(TNode(poppedNode.second->next->value, poppedNode.second->next));
        }

        if (minHeap.size() == 0)
        {
            curNode->next = nullptr;
        }
    }

    return head;
}




template<class T>
void printNodes(Node<T>* head)
{
    auto curNode = head;
    while(curNode->next)
    {
        std::cout<<curNode->value<<" ---> ";
        curNode = curNode->next;
    }
    std::cout<<curNode->value<<"\n";
}



int main(int argc, char **argv)
{
    
    Node<int>* head_1 = new Node<int>(1);
    head_1->next = new Node<int>(10);
    head_1->next->next = new Node<int>(20);

    auto head_2 = new Node<int>(4);
    head_2->next = new Node<int>(11);
    head_2->next->next = new Node<int>(13);

    auto head_3 = new Node<int>(3);
    head_3->next = new Node<int>(8);
    head_3->next->next = new Node<int>(9);

    std::vector<Node<int>*> sortedLists{head_1, head_2, head_3};

    // res = mergeSortedLists1(sortedLists);
    //printNodes(res);

    // auto res = mergeSortedLists2(sortedLists);
    // printNodes(res);

    auto res = mergeSortedLists3(sortedLists);
    printNodes(res);

}