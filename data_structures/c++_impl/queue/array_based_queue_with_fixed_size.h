#ifndef STATIC_QUEUE_H_
#define STATIC_QUEUE_H_

/**
 * @brief implements a queue using an array as base data structure
 *   
 * @tparam Type      element type
 * @tparam MAX_SIZE  size of queue
 */
template <class T, int SIZE>
class StaticQueue{
 public:

 public:
    
    StaticQueue():m_front(0), m_back(SIZE-1), m_size(0){}

    template<class TElement>
    class Iterator{

      public:

      Iterator(TElement* data, int count): m_data(data), m_count(count){}

      Iterator& operator++(){
        m_count = (m_count+1)%SIZE;
        return *this;
      }

      Iterator operator++(int) {
        auto tmp = *this;
        ++(*this);
        return tmp;
      }

      TElement& operator*() {return *(m_data + m_count);}

      bool operator==(const Iterator& other)
      {
        return m_count == other.m_count && m_data == other.m_data;
      }

      bool operator!=(const Iterator& other)
      {
        return !(*this==other);
      }

      private:
      TElement* m_data;
      int m_count;
    };

    using TIterator = Iterator<T>;
    using TConstIterator = Iterator<const T>;

    void push_back(const T& val)
    {
      m_back = (m_back+1)%SIZE;
      m_data[m_back] = val;
      if (m_size < SIZE)
      {
        ++m_size;
      }
      else
      {
        m_front = (m_front+1)%SIZE;
      }
    }

    void pop_front()
    {
      if (m_size)
      {
        m_front = (m_front+1) % SIZE;
        --m_size;
      }
    }

    bool empty(){ return !m_size;}
    int size() {return m_size;}

    T& front(){return m_data[m_front];}
    T& back(){return m_data[m_back];}

    TIterator begin(){return TIterator(m_data, m_front);}
    TConstIterator begin() const {return TConstIterator(m_data, m_front);} 

    TIterator end(){return TIterator(m_data, m_back);}
    TConstIterator end() const {return TConstIterator(m_data, m_back);} 
    // There is bug because the m_back points to the same index as m_front if the full size is reached so
    // invalid end pointer cannot be achieved if he full size is reached!

    private:
    T m_data[SIZE];
    int m_front;
    int m_back;
    int m_size;
};

#endif //STATIC_QUEUE_H_
