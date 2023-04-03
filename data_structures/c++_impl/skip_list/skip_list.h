#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include <memory>

using namespace std;

// link: https://en.wikipedia.org/wiki/Skip_list 

template<class T, int LEVEL_SIZE = 4>
class skip_list{

 public:

 skip_list(): m_size(0)
 {
  for (int i = 0; i < LEVEL_SIZE; ++i)
  {
    m_roots[i] = nullptr;
  }
 }

  struct Node
  {
    typedef Node* TNodePtr;
    
    TNodePtr next;
    TNodePtr down;
    T val;

    Node(const T& value):val(value),
                         next(nullptr),
                         down(nullptr){}
  };

  void insert(const T& val){
    if(m_size == 0)
    {
      // First insertion
      initializeHeads(val);
    }
    else 
    {
      // Insertion of element small than head 
      if(val < m_roots[0]->val)
      {
        initializeHeads(val);
      }
      // Insertion of other elements
      else
      {
        bool continueRandomInsertion = true;
        typename Node::TNodePtr newDownPtr = nullptr;
        insert(m_roots[LEVEL_SIZE-1], val, continueRandomInsertion, newDownPtr);
      }
    }
    ++m_size;
  }

  void remove(const T& val)
  {
    if (!m_size)
     return;

    // If the node to be deleted is a root node, the removal logic is different and as following
    if (m_roots[0]->val == val)
    {
      typename Node::TNodePtr newRoot = nullptr;
      for(int i = 0; i < LEVEL_SIZE; ++i)
      {
        if (i == 0)
          newRoot = m_roots[i]->next;

        auto nextNode = m_roots[i]->next;
        delete m_roots[i];
        if(nextNode && newRoot)
        {
          if(nextNode->val == newRoot->val)
          {
            m_roots[i] = nextNode;
          }
          else
          {
            m_roots[i] = new Node(newRoot->val);
            m_roots[i]->next = nextNode;
          }

          if (i != 0)
          {
            m_roots[i]->down = m_roots[i-1];
          }

        }
      }
    }
    // If the node to be deleted is not a root node 
    else
    {
      // Traverse to find the node to be deleted in all levels
      auto currNode = m_roots[LEVEL_SIZE-1];
      while (currNode)
      {
        auto tmpNode = currNode;
        if (currNode->next)
        {
          if(val >= currNode->val && val <= currNode->next->val)
          {
            currNode = currNode->down;
          }
          else
          {
            currNode = currNode->next;
          }
        }
        else
        {
          currNode = currNode->down;
        }

        if(currNode->val == val)
        {
          if (tmpNode->next)
          {
            // Because there is no access to previous horizontal node, we cannot delete the current node and update the next node of previous node with the 
            // next node of current node so the next nod eof current node is copied to current node and next node is deleted
            *tmpNode = *tmpNode->next;
            delete tmpNode->next;
          }
          else
          {
            // This is already a bug because we delete the current node without setting the next node of previous node to "nullptr"
            delete tmpNode;
          }
        }

      }
      
      --m_size;
    }

  }

 private:

 // Generate 0 and 1 randomly with equal probability 0.5
 bool rand50() 
 {
  return rand() & 1;
 }

 // Insert a root node
 void initializeHeads(const T& val)
 {
  for(int i=0; i < LEVEL_SIZE; ++i)
  {
    auto nodeTmp = m_roots[i];
    m_roots[i] = new Node(val);
    m_roots[i]->next = nodeTmp;
    if (i != 0 )
    {
      m_roots[i]->down = m_roots[i-1];
    }
  }
 }

 // Insert a node recursively
 void insert(Node* node, const T& val, bool& continueRandomInsertion, typename Node::TNodePtr& newDownNode)
 {
  if (!node)
  {
    return;
  }

  // Traverse horizontally
  auto currNode = node;
  if (currNode->next)
  {
    while(val > currNode->val && currNode->next)
    {
      if (val > currNode->next->val )
        currNode = currNode->next;
      else
        break;
    }
  }

  // Traverse vertically 
  insert(currNode->down, val, continueRandomInsertion, newDownNode);

  // Check if it reaches the first level
  if(!currNode->down)
  {
    auto tmpNode = currNode->next;
    currNode->next = newDownNode = new Node(val);
    currNode->next->next = tmpNode;
  }
  // it is on other levels
  else
  {
    // Check if the value should be put in to the list on this level
    if(continueRandomInsertion)
    {
      // Throw the coin to see if the element is randomly inserted 
      auto res = rand50();
      if(res)
      {
        auto newNode = new Node(val);
        auto tmpNode = currNode->next;
        currNode->next = newNode;
        newNode->next = tmpNode;
        newNode->down = newDownNode;
        newDownNode = newNode;
      }
      else
      {
        continueRandomInsertion = false;
      }
    }
  }

 }

 private:
 // Levels
 Node* m_roots[LEVEL_SIZE];
 // Number of nodes that are inserted
 int m_size;
  
};


#endif//TRIE_H_
