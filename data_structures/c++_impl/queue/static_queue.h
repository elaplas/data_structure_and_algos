//
// Created by z639627 on 2/27/21.
//

#ifndef QUEUE__STATIC_QUEUE_H_
#define QUEUE__STATIC_QUEUE_H_

/**
 * @brief implements a queue using an array as base data structure
 *   
 * @tparam Type      element type
 * @tparam MAX_SIZE  size of queue
 */
template <class Type, int MAX_SIZE>
class StaticQueue {
 public:

 public:
    StaticQueue():m_front(0), m_back(SIZE-1){}

    void push_back(const T& val)
    {
        m_back = (m_back+1)%SIZE;
        m_data[m_back] = val;
    }

    T pop_front()
    {
        auto tmp = m_data[m_front];
        m_front = (m_front+1) % SIZE;
        return tmp;
    }

    T& front(){return m_data[m_front];}
    T& back(){return m_data[m_back];}


    private:
    T m_data[SIZE];
    int m_front;
    int m_back;
  
 
};

#endif //QUEUE__STATIC_QUEUE_H_
