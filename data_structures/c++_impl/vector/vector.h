#ifndef VECTOR_H_
#define VECTOR_H_


namespace P{
template<class T>
class Iterator
{
    public:

    Iterator():Iterator(nullptr){}
    Iterator(T* ptr):m_ptr(ptr){}
    ~Iterator() = default;

    T& operator*()
    {
        return *m_ptr;
    }

    Iterator& operator++()
    {
        ++m_ptr;
        return *this;
    }

    Iterator operator++(int)
    {
        auto tmpIt=*this;
        ++m_ptr;
        return tmpIt;
    }

    bool operator==(const Iterator& other)
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const Iterator& other)
    {
        return m_ptr != other.m_ptr;
    }

    int operator-(const Iterator& other)
    {
        return m_ptr - other.m_ptr;
    }

    Iterator operator+(int i)
    {
        return Iterator(m_ptr + i);
    }

    Iterator operator-(int i)
    {
        return Iterator(m_ptr - i);
    }

    private:

    T* m_ptr;
};

template<class T>
class Allocator
{
    public:

    T* allocate(int n)
    {
        return static_cast<T*>(std::malloc(n*sizeof(T)));
    }

    void deallocate(T* ptr)
    {
        std::free(ptr);
    }

    template<class... Args>
    void construct(T* ptr, Args... args)
    {
        new ( (void*) ptr) T(args...); 
    }

    void destroy(T* ptr)
    {
        ptr->~T();
    }
};

template<class T, class TAllocator = Allocator<T>>
class Vector
{
    public:

    using TIterator = Iterator<T>;
    using TConst = const T;
    using TConstIterator = Iterator<TConst>;
    
    Vector():m_capacity(10), m_next(0)
    {
        m_data = new T[m_capacity];
    }

    void resize(int newCapacity)
    {
        int minCapacity = m_capacity;

        if ( newCapacity < minCapacity){
            minCapacity = newCapacity;
        }

        auto newData = new T[newCapacity];
        for (int i=0; i < minCapacity; ++i)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

    void push_back(const T& value)
    {
        if ( m_next >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_data[m_next] = value;
        ++m_next;
    }

    template<class... Args>
    void emplace_back(Args... args)
    {
        if (m_next >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_allocator.construct(m_data+m_next, args...);
        // new (void*(m_data+m_next)) T(args..); 
        ++m_next;
    }
    
    void pop_back()
    {
        if (!m_next)
        {
            return;
        }
        --m_next;
    }

    T& operator[](int i)
    {
        return m_data[i];
    }

    const T& operator[](int i) const
    {
        return m_data[i];
    }

    TIterator begin() {return TIterator(m_data); }
    TIterator end() { return TIterator(m_data+m_next);}
    TConstIterator begin() const {return TConstIterator(m_data); }
    TConstIterator end() const { return TConstIterator(m_data+m_next);}

    TIterator erase(TIterator first, TIterator last)
    {
        auto curFirst = first;
        auto curLast = last;

        while (curLast != end())
        {
            *curFirst = *curLast;
            ++curFirst;
            ++curLast;
        }

        auto diff = last - first;
        m_next -= diff;
        return TIterator(first + diff);
    }

    TIterator erase(TIterator it)
    {
        return erase(begin(), it);
    }

    private:
    int m_capacity;
    int m_next;
    T* m_data;
    TAllocator m_allocator;
};


}

#endif//VECTOR_H_
