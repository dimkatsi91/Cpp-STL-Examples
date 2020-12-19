/*
 * Iterator DP via a stack
 * Original Example url: https://sourcemaking.com/design_patterns/iterator/cpp/1
 * Iterator DP : Used for traversing a container class (Stack class) 
 * using a second dedicated class (Iterator class). The Iterator class can be designed
 * to adapt to the program's needs with a variety of different functionality
*/
#include <iostream>
#include <vector>

using namespace std;

// just for the compiler to know at first that we have
// an Iterator class
//
class Iterator;

class Stack {
public:
    friend class Iterator;
    Iterator *createIterator() const;
    Stack() {
        ptr=-1;
    }
    void push(int val) {
        // increment ptr and push the value
        s[++ptr] = val;
    }
    int pop() {
        // Get the value where current pointer 
        // points to and decrement it
        return s[ptr--];
    }
    bool isEmpty() {
        // return true if pointer points to -1
        // i.e. outside the matrix's index
        return ptr==-1;  // ? true : false;
    }
private:
    int s[10];
    int ptr;
};

// Iterator Class for iterating a stack's elements
// It is nice to separate the base class with the
// iteration class and think about it like an interface
// for the base Stack class in this specific example
//
class Iterator {
public:
    Iterator(const Stack * stack)
        : stack(stack)
    {}
    void first() {
        idx=0;
    }
    void next() {
        idx++;
    }
    bool isDone() {
        return idx == stack->ptr + 1;
    }
    int currentItem() {
        // return stack's value of its 's' matrix at current index/position
        return stack->s[idx];
    }
private:
    const Stack * stack;
    int idx;
};

Iterator *Stack::createIterator() const {
    return new Iterator(this);
}

// == Operator for two stacks
bool operator == (const Stack & stack1, const Stack & stack2) {
    // Create two iterator objects/instances for each stack
    Iterator * s1_itr = stack1.createIterator();
    Iterator * s2_itr = stack2.createIterator();

    for(s1_itr->first(), s2_itr->first(); !s1_itr->isDone(); s1_itr->next(), s2_itr->next())
        if(s1_itr->currentItem() != s2_itr->currentItem())
            break;
    bool res = s1_itr->isDone() && s2_itr->isDone();

    delete s1_itr, s2_itr;
    return res;
}


int main() {
    Stack s1;
    for(int val=10; val<60; val+=10)
        s1.push(val);

    Stack s2(s1), s3(s1);

    s3.pop();
    cout << " s1 ~ s2 : " << (s1==s2) << endl;
    cout << " s1 ~ s3 : " << (s1==s3) << endl;

    return 0;
}
