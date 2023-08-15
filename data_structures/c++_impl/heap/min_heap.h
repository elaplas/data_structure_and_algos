#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

using namespace std;

template<class TVal, class TCost>
class MinHeap
{
    public:
    struct Node{

        Node(const TVal& v, const TCost& c):value(v), cost(c){}
        Node() {}
        TVal value;
        TCost cost;
    };

    MinHeap():m_next(0), m_size(0) {}

    void push(const TVal& val, const TCost& cost)
    {
        m_data[m_next] = Node(val, cost);
        heapifyUp();
        ++m_next;
        ++m_size;
    }

    void pop() {
        if (m_size)
        {
            m_data[0] = m_data[m_next-1];
            heapifyDown();
            --m_size;
            --m_next;
        }
    }

    Node& top() {return m_data[0];}
    int size() {return m_size;};
    bool empty(){return !m_size;}

    private:

    void heapifyUp() {

        auto curChild = m_next;

        while (curChild)
        {
            auto curParent = static_cast<int>( (curChild-1)/2 ); 
            if (m_data[curChild].cost < m_data[curParent].cost)
            {
                auto tmp = m_data[curParent];
                m_data[curParent] = m_data[curChild];
                m_data[curChild] = tmp;
                curChild = curParent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown()
    {

        auto curParent = 0;

        while (curParent*2+1 < m_size && curParent*2+2 < m_size)
        {
            auto leftChild = curParent*2 + 1;
            auto rightChild = curParent*2 +2;
            auto curChild = leftChild;
            if (m_data[rightChild].cost < m_data[leftChild].cost)
            {
                curChild = rightChild;
            }

            if (m_data[curChild].cost < m_data[curParent].cost)
            {
                auto tmp = m_data[curParent];
                m_data[curParent] = m_data[curChild];
                m_data[curChild] = tmp;
                curParent = curChild;
            }
            else
            {
                break;
            }
        }
    }

    private:
    Node m_data[100];
    int m_next;
    int m_size;
};




#endif//MIN_HEAP_H_
