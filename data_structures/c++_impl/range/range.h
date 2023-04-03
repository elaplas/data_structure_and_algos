#include <iterator>
#include <iostream>

#pragma

template<long From, long To>
class range {

    class Iterator: public std::iterator<std::input_iterator_tag, 
                                        long,  // value tape
                                        long,  // difference type
                                        long*, // pointer type
                                        long   // reference type
                                        >{
        public:

            Iterator(long num=0):m_num(num)
            {
                std::cout<<"iterator constructed in address "<<this<<" with num: "<<m_num<<std::endl;
            }

            ~Iterator()
            {
                std::cout<<"iterator destructed in address "<<this<<" with num: "<<m_num<<std::endl;
            }
        
            Iterator& operator++(){
                m_num = To >= From? m_num+1 : m_num-1;
                return *this;
            }

            Iterator operator++(int){
                auto tmp_it = *this;
                ++(*this);
                return tmp_it;
            }

            bool operator==(const Iterator& other) const
            {
                return m_num == other.m_num;
            }

            bool operator!=(const Iterator& other) const
            {
                return !(*this == other);
            }

            long operator*() const
            {
                return m_num;
            }
        private:
            long m_num;
    };

    public:
        Iterator begin() {      
            return Iterator(From);
        }

        Iterator end() {
            return Iterator(To >= From? To+1 : To-1);
        }
};