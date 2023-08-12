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
    
    Vector():m_capacity(10), m_back(0), m_front(0), m_size(0)
    {
        m_data = m_allocator.allocate(m_capacity);
    }

    void resize(int newCapacity)
    {
        int minCapacity = m_capacity;

        if ( newCapacity < minCapacity){
            minCapacity = newCapacity;
        }

        auto newData = m_allocator.allocate(newCapacity);
        for (int i=0; i < minCapacity; ++i)
        {
            newData[i] = m_data[i];
        }
        m_allocator.deallocate(m_data);
        m_data = newData;
        m_capacity = newCapacity;
    }

    void push_back(const T& value)
    {
        if ( m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_data[m_back] = value;
        ++m_back;
        ++m_size;
    }

    template<class... Args>
    void emplace_back(Args... args)
    {
        if (m_size >= m_capacity)
        {
            resize(m_capacity*2);
        }
        m_allocator.construct(m_data+m_back, args...);
        ++m_back;
        ++m_size;
    }
    
    void pop_back()
    {
        if (m_size)
        {
            --m_back;
            --m_size;
        }
    }

    void pop_front()
    {
        if (m_size)
        {
            ++m_front;
            --m_size;
        }
    }

    T& front(){ return m_data[m_front];}
    const T& front() const { return m_data[m_front];}

    T& back() {return m_data[m_back-1];}
    const T& back() const {return m_data[m_back-1];}

    T& operator[](int i){return m_data[i];}
    const T& operator[](int i) const{return m_data[i];}

    TIterator begin() {return TIterator(m_data); }
    TIterator end() { return TIterator(m_data+m_back);}
    TConstIterator begin() const {return TConstIterator(m_data); }
    TConstIterator end() const { return TConstIterator(m_data+m_back);}

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
        m_back -= diff;
        return TIterator(first + diff);
    }

    TIterator erase(TIterator it)
    {
        return erase(it, it+1);
    }

    private:
    int m_capacity;
    int m_back;
    int m_front;
    int m_size;
    T* m_data;
    TAllocator m_allocator;
};


}

#endif//VECTOR_H_
