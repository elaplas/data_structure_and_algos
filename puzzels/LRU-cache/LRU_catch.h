#ifndef LRU_CACHE__LRU_CATCH_H_
#define LRU_CACHE__LRU_CATCH_H_

#include <list>
#include <unordered_map>

using namespace std;

class LRU{

 public:
  LRU(int memorySize): memorySize_(memorySize)
  {
  }

  void insert(int key, int value)
  {
    if (map_.find(key) == map_.end())
    {
      doublyLinkedList_.push_front(key);
      map_[key] = pair<int, list<int>::iterator>(value, doublyLinkedList_.begin());
    }
    else
    {
      map_[key].first = value;
      auto address = map_[key].second;
      doublyLinkedList_.erase(address);
      doublyLinkedList_.push_front(key);
      map_[key].second = doublyLinkedList_.begin();
    }

    if(doublyLinkedList_.size() > memorySize_)
    {
      auto key = doublyLinkedList_.back();
      doublyLinkedList_.pop_back();
      map_.erase(key);
    }

  }

  int get(int key)
  {
    int res = -1;
    if (map_.find(key) != map_.end())
    {
      res = map_[key].first;
      auto address = map_[key].second;
      doublyLinkedList_.erase(address);
      doublyLinkedList_.push_front(key);
      map_[key].second = doublyLinkedList_.begin();
    }
    return res;
  }


 private:
  unordered_map<int, pair<int, list<int>::iterator>> map_;
  list<int> doublyLinkedList_;
  int memorySize_;
};


#endif//LRU_CACHE__LRU_CATCH_H_
