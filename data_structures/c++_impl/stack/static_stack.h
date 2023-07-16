//
// Created by z639627 on 2/28/21.
//

#ifndef STACK_STATIC_STACK_H_
#define STACK_STATIC_STACK_H_

template<class T, int SIZE>
class StaticStack
{
    public:
    StaticStack():m_top(SIZE-1), m_size(0){}

    void push(const T& val)
    {

        m_top = mod(m_top+1, SIZE);
        m_data[m_top] = val;
        if(m_size < SIZE)
        {
            ++m_size;
        }
    }

    T pop()
    {
        if (!m_size)
        {
            return T();
        }

        auto tmp = m_data[m_top];
        m_top = mod(m_top-1, SIZE);
        --m_size;
        return tmp;
    }

    bool empty(){return !m_size; }

    int mod(int x, int y)
    {
        auto res = 0;
        if (x < 0)
        {
            x *= -1;
            res = x%y;
            res = y - res;
        }
        else
        {
            res = x%y;
        }
        return res;
    }

    private:
    T m_data[SIZE];
    int m_top;
    int m_size;
};


#endif //STACK__STATIC_STACK_H_
