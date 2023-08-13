#ifndef QUEUE_H_
#define QUEUE_H_


using namespace std;

template<class T>
class Allocator{

    public:

    T* allocate(int n)
    {
        return static_cast<T*>(malloc(n*sizeof(T)));
    }

    template<class... Args>
    void construct(T* objPtr, Args&... args)
    {
        new (objPtr) T(args...);
    }

    void destruct(T* objPtr)
    {
        objPtr->~T();
    }

    void deallocate(T* objPtr)
    {
        free(objPtr);
    }
};

/**
 * @brief implements a queue using an array as base data structure that can expand or shrink it size
 *   
 * @tparam Type      element type
 * @tparam MAX_SIZE  size of queue
 */

template<class T, class TAllocator = Allocator<T>>
class Queue{

public:

    Queue():m_front(0), m_back(0), m_size(0), m_capacity(10)
    {
        m_data = m_allocator.allocate(10);
    }

    void push_back(const T& val)
    {
        if (m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_data[m_back] = val;
        ++m_back;
        ++m_size;
    }

    template<class... Args>
    void emplace_back(Args&... args)
    {
         if (m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_allocator(m_data+m_back, args...);
        ++m_back;
        ++m_size;
    }

    void pop_front()
    {
        if (m_size)
        {
            --m_size;
            ++m_front;
        }
    }

    int size() {return m_size;}
    int empty() {return !m_size;}

    T& front() {return m_data[m_front];}
    T& back() {return m_data[m_back-1];}

private:
    void resize(int newCapacity) {

        auto newData = m_allocator.allocate(newCapacity);
        auto smallerCap = m_capacity;
        if (newCapacity < smallerCap)
        {
            smallerCap = newCapacity;
        }
        for (int i =0 ; i < smallerCap; ++i)
        {
            newData[i] = m_data[i];
        }
        m_allocator.deallocate(m_data);
        m_data = newData;
        m_capacity = newCapacity;
    }

private:
    int m_front;
    int m_back;
    int m_size;
    int m_capacity;
    TAllocator m_allocator;
    T* m_data;
};


#endif //QUEUE_H_
