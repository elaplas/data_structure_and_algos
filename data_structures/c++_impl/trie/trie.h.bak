#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include <memory>

#include "array.h"

using namespace std;

template<class TVal>
class Trie{

 public:

  struct Node
  {
    Array<Node*> arr;
    TVal val;
    bool terminated;
  };

  Trie():m_root(nullptr){}

  ~Trie()
  {
    // Remove all existing nodes
    remove_node(m_root);
    // Remove root node
    delete m_root;
  }

  void insert(const string& str, const TVal& val)
  {

    // Create root if it doesn't exist
    if (!m_root)
    {
      m_root = new Node();
    }

    Node* currNode = m_root;
    
    for (int i =0; i < str.size(); ++i)
    {
      // Create corresponding node if they doesn't exist
      if( !currNode->arr[str[i]] )
      {
          currNode->arr.insert(str[i], new Node());
      }

      // Some words may overlap
      if( currNode->terminated )
      {
        currNode->terminated = false;
      }

      // Update current node
      currNode = currNode->arr[str[i]];

      // Update value if the traversal od word is complete
      if (i == (str.size() - 1) )
      {
        currNode->terminated = true;
        currNode->val = val;
      }
    }
  }

  TVal& find(const string& str)
  {
    Node* currNode = m_root;
    for (int i=0; i < str.size(); ++i)
    {
      currNode = currNode->arr[str[i]];
    }
    return currNode->val;
  }

  void remove(const string& str)
  {
    remove_node(m_root, str, 0);
  }

 private:

  void remove_node(Node* node, const string& str, int i)
  {
    // Return if the last node is met
    if(i == str.size())
    {
      return;
    }
    // Traverse all the node to the last node corresponding to the last letter of str by recursively calling the function 
    Node* nextNode = node->arr[str[i]];
    ++i;
    remove_node(nextNode, str, i);
    // Check if a node should be deleted in the reverse direction of the traversal achieved by recursive calling
    if (nextNode->arr.size() == 0 || nextNode->terminated)
    {
      delete nextNode;
      node->arr.erase(str[i]);
    }
  }

  void remove_node(Node* node)
  {

    if (node->arr.size() == 0)
      return;

    for (int i =0; i < node->arr.max_size(); ++i){
      
      if(node->arr[i])
      {
        remove_node(node->arr[i]);

        if(node->arr[i]->arr.size() == 0)
        {
          delete node->arr[i];
          node->arr.erase(i);
        }
      }
    }

  }

 
 private:

 Node* m_root;
  
};


#endif//TRIE_H_
