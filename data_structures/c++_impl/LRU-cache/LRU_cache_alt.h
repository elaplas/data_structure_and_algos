#ifndef LRU_CACHE_ALT_H_
#define LRU_CACHE_ALT_H_

#include <list>
#include <unordered_map>


using namespace std;

/**
 * @brief Impl of LRU-cache with O(1) time complexity  
 * 
 */
class LRUCache{

    public:
    LRUCache(): LRUCache(5){}
    LRUCache(uint32_t cap):m_cap(cap){}

    struct Node{
        int value;
        list<int>::iterator ptr;

        Node(){}
        Node(int val, list<int>::iterator p): value(val), ptr(p) {}
    };

    void set(int key, int value) {

        if (m_map.size() == m_cap)
        {
            int removedKey = m_cache.back();
            m_cache.pop_back();
            m_map.erase(removedKey);
        }
        m_cache.push_front(key);
        auto ptr = m_cache.begin();
        m_map[key] = Node(value, ptr);
    }

    int read(int key)
    {
        if (m_map.find(key) == m_map.end())
        {
            return -1;
        }
        auto& node = m_map[key];
        m_cache.erase(node.ptr);
        m_cache.push_front(key);
        node.ptr = m_cache.begin();
        return node.value;
    }

    unordered_map<int,Node>::iterator begin(){return m_map.begin(); }
    unordered_map<int,Node>::iterator end(){return m_map.end(); }

    private:
    uint32_t m_cap;
    unordered_map<int, Node> m_map;
    list<int> m_cache;
};



#endif//LRU_CACHE_ALT_H_
