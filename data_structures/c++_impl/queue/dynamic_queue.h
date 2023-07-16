#ifndef QUEUE__DYNAMIC_QUEUE_H_
#define QUEUE__DYNAMIC_QUEUE_H_

/**
 * @brief implements a queue using "linked-list" as base data structure
 * 
 * @tparam T   template type
 */
template<class T, class TVal>
class Iterator
{
    public:
    Iterator(T* ptr, int i):m_ptr(ptr), m_i(i){}

    Iterator& operator++()
    {
        if (m_ptr->next)
        {
            m_ptr = m_ptr->next;
        }
        ++m_i;
        return *this;
    }

    Iterator operator++(int)
    {
        auto tmp = *this;
        if (m_ptr->next)
        {
            m_ptr = m_ptr->next;
        }
        ++m_i;
        return *this;
    }

    TVal& operator*()
    {
        return m_ptr->value;
    }

    bool operator==(const Iterator& other)
    {
        return m_i == other.m_i;
    }

    bool operator!=(const Iterator& other)
    {
        return !(*this == other);
    }

    private:
    T* m_ptr;
    int m_i;
};


template<class T>
class Queue
{
    public:

    struct Node
    {
        T value;
        Node* next;

        Node(const T& val): value(val), next(nullptr){}
    };

    using TIterator=Iterator<Node, T>;

    Queue():m_size(0), m_front(nullptr), m_back(nullptr){}



    void push_back(const T& val)
    {
        if (!m_back)
        {
            m_back = m_front = new Node(val);
        }
        else
        {
            m_back->next = new Node(val);
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

        auto tmp = m_front->value;
        auto tmpPtr = m_front;
        m_front = m_front->next;
        delete tmpPtr;
        --m_size;
        return tmp;
    }

    T& front()
    {
        return m_front->value;
    }

    T& back()
    {
        return m_back->value;
    }

    TIterator begin(){return TIterator(m_front, 0);}
    TIterator end(){ return TIterator(m_back, m_size);}

    private:

    Node* m_front;
    Node* m_back;
    int m_size;
};


#endif //QUEUE__DYNAMIC_QUEUE_H_
