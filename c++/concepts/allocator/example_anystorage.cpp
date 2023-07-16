
#include <iostream>
#include <utility>

/**
 * One application of "AnyStorage" is to storage and construct any type in-place
 */

template<int STORAGE_SIZE, int AlIGNMENT_SIZE>
class AnyStorage{

    public:
    AnyStorage() = default;
    ~AnyStorage() {destruct();}

    template<class T, class... Args>
    T* construct(Args... args)
    {
        static_assert(sizeof(T) <= STORAGE_SIZE, "type is bigger than storage");
        auto objPtr= new (&m_storage) T(args...);
        m_destruct = [](void* objPtr) 
        {
            static_cast<T*>(objPtr)->~T(); 
        };
        return objPtr;
    }

    void destruct()
    {
        m_destruct(&m_storage);
    }

    private:
    std::aligned_storage_t<STORAGE_SIZE, AlIGNMENT_SIZE> m_storage;
    using TDestructionFunction = void(*)(void* objPtr);
    TDestructionFunction m_destruct;
};


struct A
{
    int x;
    int y;
    int z;

    A(int x1, int y1): 
    x(x1),
    y(y1)
    {}
};

struct B
{
    int x;
    int y;
    int z;

    B(int x1, int y1, int z1): 
    x(x1),
    y(y1),
    z(z1)
    {}
};




int main()
{

    AnyStorage<16, 16> anyStorage;
    auto objPtr = anyStorage.construct<A>(1,2);
    std::cout<<".....A....."<<std::endl;
    std::cout<<objPtr->x<<std::endl;
    std::cout<<objPtr->y<<std::endl;
    anyStorage.destruct();

    auto objPtr1 = anyStorage.construct<B>(3,4,5);
    std::cout<<".....B....."<<std::endl;
    std::cout<<objPtr1->x<<std::endl;
    std::cout<<objPtr1->y<<std::endl;
    std::cout<<objPtr1->z<<std::endl;
    anyStorage.destruct();

    return 0;
}