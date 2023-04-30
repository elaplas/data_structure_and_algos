#ifndef HEAP__MIN_HEAP_H_
#define HEAP__MIN_HEAP_H_

#include <vector>


template<class T>
class MinHeap
{
    public:

    struct Node
    {
        T value;
        float cost;
    };

    MinHeap():m_next(0), m_capacity(10)
    {
        m_data = new Node[m_capacity];
    }


    void push(const Node& node)
    {
        if (m_next >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_data[m_next] = node;
        heapify_up();
        ++m_next;
    }

    Node pop()
    {
        if (!m_next)
        {
            return Node();
        }

        auto tmpNode = m_data[0];
        m_data[0] = m_data[m_next-1];
        heapify_down();
        --m_next;
        return tmpNode;
    }

    int size() const {return m_next;}


    private:

    void resize(int newCapacity)
    {
        int minCapacity = m_capacity;
        if (newCapacity < m_capacity)
        {
            minCapacity = newCapacity;
        }
        auto newData = new Node[newCapacity];
        for (int i=0; i< minCapacity; ++i)
        {
            newData[i] = m_data[i];
        }
        m_data = newData;
        m_capacity = newCapacity;
    }

    void heapify_up()
    {
        int curChild = m_next;
        while(curChild!=0)
        {
            int curParent = static_cast<int>((curChild-1)/2);
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

    void heapify_down()
    {
        int curParent = 0;
        while ( curParent*2+2 < m_capacity)
        {
            int leftChild = curParent*2+1;
            int rightChild = curParent*2+2;
            int curChild = leftChild;
            if (m_data[rightChild].cost < m_data[leftChild].cost)
            {
                curChild = rightChild;
            }

            if (curChild >= m_next)
            {
                break;
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

    int m_next;
    int m_capacity;
    Node* m_data;
};

#endif//HEAP__MIN_HEAP_H_
