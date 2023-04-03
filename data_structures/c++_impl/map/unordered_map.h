#ifndef UNORDERED_MAP_H_
#define UNORDERED_MAP_H_

#include <iostream>
#include <utility>
#include "iterator.h"

namespace P{

template<typename TKey, typename TValue>

class unordered_map{

  public:

    struct Node{
      typedef std::pair<TKey, TValue> Pair;

      Pair data;
      Node* next;

      Node() = default;

      Node(const TKey& key, Node* nextPtr = nullptr): next(nextPtr)
      {
        data.first = key;
        data.second = TValue();
      }
  };
    using PairType = typename Node::Pair;
    typedef iterator<Node, PairType> Iterator;
    typedef iterator<Node, const PairType> ConstIterator;

    unordered_map(): m_tableSize(100), m_size(0)
    {
      m_table = new Node*[m_tableSize]();
    }

    virtual ~unordered_map()
    {
      // Delete all nodes
      for (std::uint64_t i=0; i < m_tableSize; ++i)
      {
        auto currNode = m_table[i];
        while (currNode)
        {
          auto tmpNode = currNode;
          currNode = currNode->next;
          delete tmpNode;
        }
      }
    }

    TValue& operator[](const TKey& k)
    {
      auto hashKey = hash_function(k);
      Node* currNode = m_table[hashKey];
      
      if (!currNode)
      {
        m_table[hashKey] = new Node(k);
        return m_table[hashKey]->data.second;
      }

      Node* preNode = nullptr;
      while (currNode)
      {
        // Search for the corresponding pair
        if (currNode->data.first == k)
          return currNode->data.second;
        // Update pointer
        preNode = currNode;
        currNode = currNode->next;
      }

      preNode->next = new Node(k);
      return preNode->next->data.second;
    }

    void erase(const TKey& k)
    {
      auto hashKey = hash_function(k);
      auto currNode = m_table[hashKey];

      Node* preNode = nullptr;
      while(currNode)
      {
        if (currNode->data.first = k && !preNode)
        {
          m_table[hashKey] = currNode->next;
          delete currNode;
          return;
        }
        else if(currNode->data.first = k && preNode)
        {
          preNode->next = currNode->next;
          delete currNode;
          return;
        }
        else
        {
          // Do nothing
        }
        preNode = currNode;
        currNode = currNode->next;
      }
    }

    unsigned long hash_function(const TKey& k)
    {
      return static_cast<unsigned int>(k) % m_tableSize;
    }


    Iterator begin()
    {
      Node* currNodePtr;
      Node** tablePtr;
      for (std::uint64_t i=0; i < m_tableSize; ++i)
      {
        tablePtr = m_table + i;
        currNodePtr = *tablePtr;
        if (currNodePtr)
        {
          break;
        }
      }
      return Iterator(currNodePtr, tablePtr, m_table + m_tableSize);
    }

    Iterator end()
    {
  
      return Iterator(nullptr, m_table + m_tableSize, m_table + m_tableSize);
    }

    ConstIterator begin() const
    {
      Node* currNodePtr;
      Node** tablePtr;
      for (std::uint64_t i=0; i < m_tableSize; ++i)
      {
        tablePtr = m_table + i;
        currNodePtr = *tablePtr;
        if (currNodePtr)
        {
          break;
        }
      }
      return ConstIterator(currNodePtr, tablePtr, m_table + m_tableSize);
    }

    ConstIterator end() const
    {
  
      return ConstIterator(nullptr, m_table + m_tableSize, m_table + m_tableSize);
    }

  private:

    std::uint32_t m_tableSize;
    std::uint32_t m_size;
    Node** m_table;

};

}

#endif//UNORDERED_MAP_H_
