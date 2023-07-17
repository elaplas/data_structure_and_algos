#ifndef QUEUE__STATIC_QUEUE_H_
#define QUEUE__STATIC_QUEUE_H_

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

    T pop_front()
    {
      if (!m_size)
      {
        return T();
      }
      auto tmp = m_data[m_front];
      m_front = (m_front+1) % SIZE;
      --m_size;
      return tmp;
    }

    bool empty(){ return !m_size;}

    T& front(){return m_data[m_front];}
    T& back(){return m_data[m_back];}


    private:
    T m_data[SIZE];
    int m_front;
    int m_back;
    int m_size;
};

#endif //QUEUE__STATIC_QUEUE_H_
