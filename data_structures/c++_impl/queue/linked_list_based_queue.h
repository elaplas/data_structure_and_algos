#ifndef DYNAMIC_QUEUE_H_
#define DYNAMIC_QUEUE_H_

/**
 * @brief implements a queue using "linked-list" as base data structure
 * 
 * @tparam T template type
 */

template<class T>
class Queue{

    public:

    struct Node
    {
        Node(const T& val): value(val), next(nullptr){}

        T value;
        T* valuePtr;
        Node* next;
    };


    template<class TVal>
    class Iterator
    {
        public:

        Iterator(Node* node, int count):m_count(count), m_node(node){}

        Iterator& operator++()
        {
            ++m_count;
            m_node = m_node->next;
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        TVal& operator*()
        {
            return m_node->value;
        }

        bool operator==(const Iterator& other)
        {
            return (m_count == other.m_count && m_node == other.m_node);
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this == other);
        }

        private:
        int m_count;
        Node* m_node;
    };

    using TIterator = Iterator<T>;
    using TConstIterator = Iterator<const T>;

    Queue():m_back(nullptr), m_front(nullptr), m_size(0){}

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

    void pop_front()
    {
        if (m_size)
        {
            auto tmp = m_front;
            m_front = m_front->next;
            delete tmp;
            --m_size;
        }
    }

    int size(){return m_size;}
    bool empty(){return !m_size;}

    T& front() {return m_front->value;}
    T& back() {return m_back->value;}

    TIterator begin(){return TIterator(m_front, 0);}
    TConstIterator begin() const {return TConstIterator(m_front, 0);}

    TIterator end(){return TIterator(nullptr, m_size);}
    TConstIterator end() const {return TConstIterator(nullptr, m_size);}


    private:
    Node* m_back;
    Node* m_front;
    int m_size;
};


#endif //DYNAMIC_QUEUE_H_
