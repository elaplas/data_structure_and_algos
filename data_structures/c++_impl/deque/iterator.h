#ifndef ITERATOR_H_
#define ITERATOR_H_


template<class T, class U>
class iterator {

public:

iterator():iterator(nullptr, nullptr, 0){}

iterator (T* currArrPtr, U* currBookPtr, int arrCapacity):m_currArrPtr(currArrPtr),
                                                                       m_currBookPtr(currBookPtr),
                                                                       m_arrCapacity(arrCapacity)
                                                                       {}


iterator& operator++()
{
    if (m_currArrPtr == (*m_currBookPtr) + m_arrCapacity - 1)
    {
        ++m_currBookPtr;
        m_currArrPtr = *m_currBookPtr;
    }
    else
    {
        ++m_currArrPtr;
    }
    return *this;
}        

iterator operator++(int)
{
    auto tmpIt = *this;
    ++this;
    return tmpIt;
}

T& operator*()
{
    return *m_currArrPtr;
}

bool operator==(const iterator& other) const
{
   return  m_currBookPtr == other.m_currBookPtr && m_currArrPtr == other.m_currArrPtr;
}

bool operator!=(const iterator& other) const
{
    return !(*this == other);
}

private:

T* m_currArrPtr;
U* m_currBookPtr;
int m_arrCapacity;
};




#endif //ITERATOR_H_