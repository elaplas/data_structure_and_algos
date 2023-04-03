#ifndef LRU_CACHE_H_
#define LRU_CACHE_H_

#include <list>
#include <unordered_map>

using namespace std;

template<class TKey, class TVal>
class LRU{

 public:

  using TPair = pair<TVal, typename list<TKey>::iterator>;
  using TIterator = typename unordered_map<TKey, TPair>::iterator;

  LRU(int memorySize): memorySize_(memorySize)
  {
  }

  void insert(const TKey& key, const TVal& value)
  {
    map_[key].first = value;
    doublyLinkedList_.push_front(key);
    auto& it = map_[key].second;
    // Check if iterator is dereferenceable and points to some memory
    if (it._M_node)
    {
      doublyLinkedList_.erase(it);
    }
    it = doublyLinkedList_.begin();
    // keep cache small
    if (map_.size() > memorySize_)
    {
      auto keyToDelete = doublyLinkedList_.back();
      doublyLinkedList_.pop_back();
      map_.erase(keyToDelete);
    }

  }

  TVal& get(const TKey& key)
  {
    
    auto& res = map_[key].first;
    auto& it = map_[key].second;
    // Check if iterator is dereferenceable and points to some memory
    if (it._M_node)
    {
      doublyLinkedList_.erase(it);
    }
    doublyLinkedList_.push_front(key);
    it = doublyLinkedList_.begin();
    return res;
  }

  TIterator begin()
  {
    return map_.begin();
  }

  TIterator end()
  {
    return map_.end();
  }


 private:
  unordered_map<TKey, TPair> map_;
  list<TKey> doublyLinkedList_;
  int memorySize_;
};


#endif//LRU_CACHE_H_
