//
// Created by z639627 on 2/27/21.
//

#ifndef QUEUE__DYNAMIC_QUEUE_H_
#define QUEUE__DYNAMIC_QUEUE_H_

/**
 * @brief implements a queue using "linked-list" as base data structure
 * 
 * @tparam T   template type
 */
template<class T>
class DynamicQueue
{
    public:

    struct Node
    {
        T value;
        Node* next;
    };

    DynamicQueue(): 
     m_front(nullptr),
     m_back(nullptr),
     m_size(0){}

     ~DynamicQueue()
     {
        auto curNode = m_front;
        while (curNode)
        {
            auto tmp = curNode;
            curNode = curNode->next;
            delete tmp;
        }
     }

    void push_back(const T& value)
    {
        if (!m_front)
        {
            m_front = m_back = new Node{value, nullptr};
        }
        else
        {
            m_back->next = new Node{value, nullptr};
            m_back = m_back->next;
        }
        ++m_size;
    }

    T pop_front()
    {
        if (!m_size)
        {
            return T();
        }

        T tmpVal = m_front->value;
        auto tmpNode = m_front;
        m_front = m_front->next;
        delete tmpNode;
        --m_size;
        return tmpVal;
    }

    int size() {return m_size;}

    T& back(){return m_back->value;}
    T& front(){return m_front->value;}

    private:
    Node* m_front;
    Node* m_back;
    int m_size;

};


#endif //QUEUE__DYNAMIC_QUEUE_H_
