#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;



/**
 * input:   1->2->5
 *          3->8->6
 *          4->7->9
 *
 * output: 1->2->3->4->5->6->7->8->9
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


/// time complexity: o(n*m * log(n*m)) where n is the number of sorted lists and m number of elements of list
/// space complexity: o(n*m) where n is the number of sorted lists and m number of elements of list
ListNode* mergeKLists(const vector<ListNode*> &A) {

  vector<pair<int, ListNode*>> vec;
  for (int i=0; i < A.size(); ++i)
  {
    ListNode* currentNode = A[i];
    while(currentNode)
    {
      vec.push_back(pair<int, ListNode*>(currentNode->val, currentNode));
      currentNode = currentNode->next;
    }
  }

  sort(vec.begin(), vec.end(), [](pair<int, ListNode*>& a, pair<int, ListNode*>& b)
  {
         return a.first < b.first;
       });


  for (int i=0; i<vec.size()-1; ++i)
  {
    vec[i].second->next = vec[i+1].second;
    if (i == vec.size()-1)
      vec[i].second->next = nullptr;
  }

  auto head = vec[0].second;

  return head;
}

struct CompareNodes{
  bool operator()(ListNode* a, ListNode* b)
  {
    return a->val > b->val;
  }
};
/// time complexity: o(n*m * log(n)) where n is the number of sorted lists and m number of elements of list
/// space complexity: o(n) where n is the number of sorted lists
ListNode* mergeKListsOptimized(vector<ListNode*> &A) {

  priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;
  // Initialize minHeap
  for (int i=0; i< A.size(); ++i)
  {
    minHeap.push(A[i]);
  }

  ListNode* previousNode = nullptr;
  ListNode* head = nullptr;
  while(!minHeap.empty())
  {
    auto currNode = minHeap.top();
    minHeap.pop();
    if (previousNode)
      previousNode->next = currNode;
    if(currNode->next)
      minHeap.push(currNode->next);
    previousNode = currNode;

    if (!head)
      head = currNode;
  }

  return head;

}

int main() {

  vector<ListNode*> vec;
  ListNode* head = nullptr;
  ListNode* pre = nullptr;
  for (int i=0; i < 5; ++i)
  {
    ListNode* node = new ListNode(i*2);
    if (pre)
      pre->next = node;

    pre = node;

    if (i == 0)
      head = node;
  }
  vec.push_back(head);

  head = nullptr;
  pre = nullptr;
  for (int i=1; i < 5; ++i)
  {
    ListNode* node = new ListNode(i);
    if (pre)
      pre->next = node;

    pre = node;

    if (i == 1)
      head = node;
  }
  vec.push_back(head);

  //auto res = mergeKLists(vec);

  auto res1 = mergeKListsOptimized(vec);

  return 0;
}
