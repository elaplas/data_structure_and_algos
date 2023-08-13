#pragma

#include <iostream>

using namespace std;

template<class T>
class Allocator{
public:
    T* allocate(int n)
    {
        malloc(n*sizeof(T));
    }

    template<class... Args>
    void construct(T* objPtr, Args... args)
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


template<class T, class TAllocator=Allocator<T>>
class Stack{

public:

    template<class TElement>
    class Iterator{

        public:

        Iterator(TElement* ptr):m_ptr(ptr){}

        Iterator& operator++()
        {
            --m_ptr;
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        TElement operator*()
        {
            return *m_ptr;
        }

        bool operator==(const Iterator& other)
        {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this==other);
        }

        private:
        TElement* m_ptr;
    };

    using TIterator = Iterator<T>;
    using TConstIterator = Iterator<const T>;

    Stack(): m_top(0), m_size(0), m_capacity(10)
    {
        m_data = m_allocator.allocate(m_capacity);
    }

    void push(const T& val)
    {
        if (m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_data[m_top] = val;
        ++m_top;
        ++m_size; 
    }

    template<class... Args>
    void push(Args&... args)
    {
        if (m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_allocator.construct(m_data+m_top, args...);
        ++m_top;
        ++m_size; 
    }

    void pop()
    {
        if (m_size)
        {
            --m_size;
            --m_top;
        }
    }

    int size(){return m_size;}
    bool empty(){return !m_size;}

    TIterator begin() {return TIterator(m_data+m_top-1);}
    TConstIterator begin()const {return TConstIterator(m_data+m_top-1);}

    TIterator end() {return TIterator(m_data-1);}
    TConstIterator end() const {return TConstIterator(m_data-1);}
    

private:
    void resize(int newCapacity)
    {
        auto newData = m_allocator.allocate(newCapacity);
        auto smallerCap = m_capacity;
        if (newCapacity < smallerCap)
        {
            smallerCap = newCapacity;
        }
        for (int i=0; i < smallerCap; ++i)
        {
            newData[i] = m_data[i];
        }
        m_allocator.deallocate(m_data);
        m_data = newData;
        m_capacity = newCapacity;
    }

private:
    int m_top;
    int m_size;
    int m_capacity;
    TAllocator m_allocator;
    T* m_data;

};


int main()
{
    using TSt = Stack<int>;
    TSt st;

    for(int i=0; i < 20; ++i)
    {
        st.push(i);
    }

    for (auto el: st)
    {
        cout<<el<<"\n";
    }

    TSt& stRef = st;
    
    return 0;
}