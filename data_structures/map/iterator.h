#ifndef ITERATOR_H_
#define ITERATOR_H_


template<class T, class U>
class iterator {

public:

using PairType = U;

iterator():iterator(nullptr){}

iterator (T* currNodePtr, T** currTablePtr, T** endTablePtr):m_currNodePtr(currNodePtr),
                                                             m_currTablePtr(currTablePtr),
                                                             m_endTablePtr(endTablePtr)
{}


iterator& operator++()
{
    m_currNodePtr = m_currNodePtr->next;
    if (!m_currNodePtr)
    {
        while(!m_currNodePtr)
        {
            if (m_currTablePtr == m_endTablePtr)
            {
                break;
            }
            ++m_currTablePtr;
            m_currNodePtr = *m_currTablePtr;
        }
    }
    return *this;
}        

iterator operator++(int)
{
    auto tmpIt = *this;
    ++this;
    return tmpIt;
}

PairType& operator*()
{
    return m_currNodePtr->data;
}

bool operator==(const iterator& other) const
{
   return  m_currNodePtr == other.m_currNodePtr && m_currTablePtr == other.m_currTablePtr;
}

bool operator!=(const iterator& other) const
{
    return !(*this == other);
}

private:

T* m_currNodePtr;
T** m_currTablePtr;
T** m_endTablePtr;
};




#endif //ITERATOR_H_