#ifndef ARRAY_H_
#define ARRAY_H_

template<class T, int SIZE>
class Array{

    public:
        template<class ElementType>
        class Iterator{

            public:

            Iterator(ElementType* ptr):m_ptr(ptr){}

            Iterator& operator++()
            {
                ++m_ptr;
                return *this;
            }

            Iterator operator++(int){
                auto tmp = *this;
                ++(*this);
                return tmp;
            }

            ElementType& operator*()
            {
                return *m_ptr;
            }

            bool operator==(const Iterator& other)
            {
                return m_ptr == other.m_ptr;
            }

            bool operator!=(const Iterator& other)
            {
                return !(*this == other);
            }

            private:
            ElementType* m_ptr;
        };

        using TIterator = Iterator<T>;
        using TConstIterator = Iterator<const T>;

        Array(): m_size(0), m_front(0), m_back(0){}

        void push_back(const T& value) 
        { 
          if ( m_size < SIZE)
          {
            m_data[m_size] = value;
            ++m_size;
            ++m_back;
          }
        }

        template<class... Args>
        void emplace_back(Args&... args)
        {
          if (m_size < SIZE)
          {
            new (m_data+m_back) T(args...);
            ++m_size;
            ++m_back;
          }
        }

        void pop_front()
        {
            if (m_size)
            {
                m_data[m_front] =T();
                --m_size;
                ++m_front;
            }
        }

        bool empty(){return !m_size;}
        bool empty() const {return !m_size;} // only for const reference of Array

        int size() {return m_size;}
        int size() const {return m_size;} // only for const reference of Array

        int max_size(){return SIZE;}
        int max_size() const {return SIZE;} // only for const reference of Array

        T& back()
        {
            return m_data[m_back-1];
        };

        T& front()
        {
            return m_data[m_front];
        };

        const T& back() const  // only for const reference of Array
        {
            return m_data[m_back-1];
        };

        const T& front() const // only for const reference of Array
        {
            return m_data[m_front];
        };

        T& operator[](int i){return m_data[i];} // calling this function shouldn't increment the size of array
        const T& operator[](int i) const {return m_data[i];} // only for const reference of Array

        TIterator begin() { return TIterator(&m_data[m_front]);}
        TIterator end() { return TIterator((&m_data[m_back-1])+1);}
        TConstIterator begin() const { return TConstIterator(&m_data[m_front]);} // only for const reference of Array
        TConstIterator end() const { return TConstIterator((&m_data[m_back-1])+1);} // only for const reference of Array

        /*
        * Important hints:
         1- In const functions of a class, we can only return copy of no-reference and non-pointer members.
         2- In const functions of a class, we can only return copy of const-reference and const-pointer members.
         3- In const functions of a class, we can pass copys of no-reference and non-pointer members into other 
         objects/functions without caring if they are modified later or not
         4- In const functions of a class, we can pass copy of reference and pointer members into other objects/functions
         but we need to take care of not being modified or non-cost copy of is returned.
         5- In const functions of a class if an object is constructed and a copy of it returned, all static and non-static members of 
          constructed object can be called!
        
         6- In a const functions, non-const functions cannot be called.
        */

    private:

        T m_data[SIZE];
        int m_size;
        int m_front;
        int m_back;
};



#endif //ARRAY_H_
