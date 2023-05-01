//
// Created by z639627 on 2/28/21.
//

#ifndef STACK_DYNAMIC_STACK_H_
#define STACK_DYNAMIC_STACK_H_

/**
 * @brief implements an stack using a "linked-list" as base data structure
 * 
 * @tparam Type 
 */
template<class Type>
class DynamicStack {

public:
    struct Node
    {
        T value;
        Node* next;
    };

    Stack(): m_top(nullptr), m_size(0){}

    ~Stack()
    {
        auto curNode = m_top;
        while (curNode != nullptr){
            auto tmp = curNode;
            curNode = curNode->next;
            delete tmp;
        }
    }

    void push(const T& value)
    {
        auto newNode = new Node{value, nullptr};
        newNode->next = m_top;
        m_top = newNode;
        ++m_size;
    }

    T pop()
    {
        if (!m_size)
        {
            return T();
        }

        T tmpValue = m_top->value;
        auto tmpNode = m_top;
        m_top = m_top->next;
        delete tmpNode;
        --m_size;
        return tmpValue;
    }

    int size() {return m_size;}

    T& top() {return m_top->value;}

    private:
    Node* m_top;
    int m_size;
};


#endif //STACK_CMAKE_BUILD_DEBUG_DYNAMIC_STACK_H_
