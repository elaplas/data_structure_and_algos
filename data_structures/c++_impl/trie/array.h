#include<array>

using namespace std;

template<class T>
class Array{

public:

    Array():m_size(0)
    {
        m_data.fill(nullptr);
    }

    void insert(char key, const T& ptr)
    {
        int i = key - '0';
        i -= 49;
        m_data[i] = ptr;
        ++m_size;
    }

    void erase(char key)
    {
        int i = key - '0';
        i -= 49;
        m_data[i] = T();
        --m_size;
    }

     void erase(int i)
    {
        m_data[i] = T();
        --m_size;
    }

    int size(){return m_size;}

    int max_size(){return SIZE;}

    T& operator[](char key)
    {
        int i = key - '0';
        i -= 49;
        return m_data[i];
    }

      T& operator[](int i)
    {
        return m_data[i];
    }

private:
    static const int SIZE = 26;
    array<T, SIZE> m_data;
    int m_size;
};