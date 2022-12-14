#include <iostream>
#include <cstdlib>

#pragma

template<class T>
class allocator {

    public:

        typedef T value_type;

        allocator() = default;

        template<class U>
        allocator(const allocator<U>& other) noexcept{}

        // Allocate memory without initializing it / without constructing any objects
        T* allocate(size_t n)
        {
            std::cout<<"memory allocated: "<< n*sizeof(T) << " [bytes]" <<std::endl;
            return static_cast<T*>(std::malloc(n*sizeof(T)));
        }

        // Create and store an object in memory
        void construct(T* ptr, const T& val)
        {
            std::cout<<"one object is constructed in memory address: "<<ptr<<std::endl;
            ptr = new ((void*)ptr) T(val);
        }

        // Deallocate memory without destructing the stored objects
        void deallocate(T* ptr, size_t n) noexcept
        {
            std::cout<<"memory deallocated"<<std::endl;
            std::free(ptr);
        }

        // Destruct an object in memory
        void destroy(T* ptr)
        {
            std::cout<<"one object is destructed in memory address: "<<ptr<<std::endl;
            ptr->~T();
        }


};

