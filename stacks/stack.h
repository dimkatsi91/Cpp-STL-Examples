#ifndef stack_h
#define stack_h

#include <deque>

template<typename T>
class Stack {
private:
    std::deque< T > stack;
public:
    // Return the up element of the stack
    T& top() {
        return stack.front();
    }
    // Add an element to the stack
    void push( const T &pushValue ) {
        stack.push_front( pushValue );
    }
    // Remove an element from the stack
    void pop() {
        stack.pop_front();
    }
    // Check if the stack is empty
    bool isEmpty() const {
        return stack.empty();
    }
    // Return the size of the stack
    size_t size() const {
        return stack.size();
    }
};

/*
template<c class T >
inline void Stack< T >:: pop()
{
    return stack.pop_front();
}
*/
#endif
