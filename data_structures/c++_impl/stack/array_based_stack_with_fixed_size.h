#ifndef STATIC_Stack_H_
#define STATIC_Stack_H_

using namespace std;


int modulo(int x, int y)
{
    int res;
    if (x < 0)
    {
        x *= -1;
        auto reminder = x%y;
        res = y - reminder;
    }
    else
    {
        res = x%y;
    }
    return res;
}

template<class T, int SIZE>
class StaticStack
{

public:

    template<class TElement>
    class Iterator
    {
        public:
        Iterator(TElement* data, int count): m_data(data), m_count(count){}

        Iterator& operator++()
        {
            m_count = modulo(m_count-1, SIZE);
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        TElement& operator*() {return *(m_data+m_count);}

        bool operator==(const Iterator& other)
        {
            return m_count == other.m_count && m_data == other.m_data;
        }

        bool operator!=(const Iterator& other)
        {
            return !(*this==other);
        }

        private:
        TElement* m_data;
        int m_count;
    };

    using TIterator = Iterator<T>;
    using TConstIterator = Iterator<const T>;

    StaticStack(): m_top(0), m_size(0){}

    void push(const T& val)
    {
        m_data[m_top] = val;
        m_top = modulo(m_top+1, SIZE);
        if (m_size < SIZE)
        {
            ++m_size;
        }
    }

    void pop()
    {
        if (m_size)
        {
            --m_size;
            m_top = modulo(m_top-1, SIZE);
        }
    }

    int size() {return m_size;}
    bool empty(){return !m_size;}

    TIterator begin(){return TIterator(m_data, modulo(m_top-1, SIZE));}
    TConstIterator begin() const {return TConstIterator(m_data, modulo(m_top-1, SIZE));}

    TIterator end(){return TIterator(m_data, 0);}
    TConstIterator end() const {return TConstIterator(m_data, 0);}


private:
    int m_top;
    int m_size;
    T m_data[SIZE];

};


#endif //STATIC_Stack_H_