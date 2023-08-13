
#pragma

#include <iostream>

using namespace std;


template<class T>
class Stack{

public:
    struct Node{
        Node(const T& val): value(val), next(nullptr){}

        T value;
        Node* next;
    };

    template<class TVal>
    class Iterator{

        public:
        Iterator(Node* node, int count): m_node(node), m_count(count){}

        Iterator& operator++()
        {
            m_node = m_node->next;
            --m_count;
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        TVal& operator*(){return m_node->value;}

        bool operator==(const Iterator& other)
        {
            return m_count == other.m_count && m_node == other.m_node;
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this==other);
        }

        private:
        Node* m_node;
        int m_count;
    };

    using TIterator = Iterator<T>;
    using TConstIterator = Iterator<const T>;

    Stack():m_top(nullptr), m_size(0){}

    void push(const T& val){

        auto newNode = new Node(val);
        newNode->next = m_top;
        m_top = newNode;
        ++m_size;
    }

    void pop()
    {
        if (m_size)
        {
            auto oldTop = m_top;
            m_top = m_top->next;
            --m_size;
            delete oldTop;
        }
    }

    int size(){return m_size;}
    bool empty(){return !m_size;}

    TIterator begin() {return TIterator(m_top, m_size);}
    TConstIterator begin() const {return TConstIterator(m_top, m_size);}

    TIterator end() {return TIterator(nullptr, 0);}
    TConstIterator end() const {return TConstIterator(nullptr, 0);}

private:
    Node* m_top;
    int m_size;
};



int main()
{
    using TSt = Stack<int>;
    TSt st;

    for(int i=0; i < 20; ++i)
    {
        st.push(i);
    }

    for(int i=0; i < 5; ++i)
    {
        st.pop();
    }

    for (auto el: st)
    {
        cout<<el<<"\n";
    }

    TSt& stRef = st;
    
    return 0;
}