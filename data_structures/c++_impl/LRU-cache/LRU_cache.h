#ifndef LRU_CACHE_H_
#define LRU_CACHE_H_

#include <list>
#include <unordered_map>


 template<class TKey, class TValue>
class LRUCache{

    public:

    LRUCache(): LRUCache(5){}
    LRUCache(int maxSize):m_maxSize(maxSize){}

    void set(const TKey& key, const TValue& value)
    {
        if ( m_cache.find(key) == m_cache.end() )
        {
            m_cache[key] = value;
            m_frequency.push_back(key);
        }
        else
        {
            m_frequency.remove(key);
            m_frequency.push_back(key);
        }

        if (m_cache.size() > m_maxSize)
        {
            auto removedKey = m_frequency.front();
            m_frequency.pop_front();
            m_cache.erase(removedKey);
        }
    }

    TValue read(const TKey& key)
    {
        if (m_cache.find(key) != m_cache.end())
        {
            auto value = m_cache[key];
            m_frequency.remove(key);
            m_frequency.push_back(key);
            return value;
        }
        else
        {
            return TValue();
        }
    }

    typename std::unordered_map<TKey, TValue>::iterator begin(){return m_cache.begin();}
    typename std::unordered_map<TKey, TValue>::iterator end(){return m_cache.end();}


    private:

    std::unordered_map<TKey, TValue> m_cache;
    std::list<TKey> m_frequency;
    int m_maxSize;

};

#endif//LRU_CACHE_H_
