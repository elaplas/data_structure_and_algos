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
template<class T>
class Stack
{
    public:
    struct Node
    {
        T value;
        Node* next;

        Node(const T& val): value(val){}
    };

    Stack():m_top(nullptr){}

    ~Stack()
    {
        auto curNode = m_top;
        while(curNode)
        {
            auto preNode = curNode;
            curNode = curNode->next;
            delete preNode;
        }
    }

    void push(const T& val)
    {
        auto tmp = new Node(val);
        tmp->next = m_top;
        m_top = tmp;
    }

    T pop()
    {
        if (!m_top)
        {
            return T();
        }

        auto tmpVal = m_top->value;
        auto tmpPtr = m_top;
        m_top = m_top->next;
        delete tmpPtr;
        return tmpVal;
    }

    bool empty(){ return m_top == nullptr;}

    T& top() {return m_top->value;}

    private:
    Node* m_top;
};


#endif //STACK_CMAKE_BUILD_DEBUG_DYNAMIC_STACK_H_
