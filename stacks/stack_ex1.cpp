#include <iostream>
#include <list>           // vector
#include <algorithm>        // *max/*min_element(begin, end)

using namespace std;

// A stack implementation using STL vector class
// Example ::
/*  Number  --  Present Stack   --  minElem --  maxElem
      3               3                3           3
      5             5  3               3           5
      2           2  5  3              2           5
      1         1  2  5  3             1           5
     -1       -1  1  2  5  3          -1           5
*/
template<class T>
class dStack {
public:
    dStack() {}
    ~dStack() {}
    // push a value in front of the stack vector
    void push(T value) {
        stack.push_front(value);
        maxElem = *max_element(stack.begin(), stack.end());
        minElem = *min_element(stack.begin(), stack.end());
    }
    // pop element from stack
    void pop() {
        cout << "\nPoping element " << stack.back() << endl;
        stack.pop_back();
        maxElem = *max_element(stack.begin(), stack.end());
        minElem = *min_element(stack.begin(), stack.end());
    }
    // get max element from the stack
    T getMax() const { 
        if(!stack.empty())
            return maxElem;
        else
            cout << "Stack is empty ...\n";
            return 0; 
    }
    // get min element from the stack
    T getMin() const {
        if(!stack.empty())
            return minElem;
        else
            cout << "Stack is empty ...\n";
            return 0;
    }
    // print the stack values
    void printStack() {
        if(!stack.empty())
        {
            cout << "Stack: ";
            for(const auto & v : stack) {
                cout << v << " ";
            }
            cout << endl;
            cout << "Max element is: " << getMax() << endl;
            cout << "Min element is: " << getMin() << endl;
            cout << endl;
        } else
            cout << "\nStack is empty ... \n";
    }
    // get the stack as a whole
    //
    /* list<T> */ auto getStack() const { return stack; }
    // get the stack size
    //
    int getSize() { return stack.size(); }
    // erase all values from map
    //
    void clearStack() {
        while(!stack.empty()) {
            stack.pop_front();
        }
    }
private:
    list<T> stack{};      // initialize the stack via vector implementation
    T minElem;              // min element
    T maxElem;              // max element
};


int main() 
{
    dStack<int> st;
    st.push(3);
    //st.printStack();
    st.push(5);
    //st.printStack();
    st.push(2);
    //st.printStack();
    st.push(1);
    //st.printStack();
    st.push(-1);
    st.printStack();
    // pop an element
    cout << "Pop element ... \n";
    st.pop();
    st.printStack();

    cout << "Erase the stack ...\n ";
    st.clearStack();
    st.printStack();

    return 0;
}

/*  OUTPUT ::

Stack: 3 
Max element is: 3
Min element is: 3

Stack: 5 3 
Max element is: 5
Min element is: 3

Stack: 2 5 3 
Max element is: 5
Min element is: 2

Stack: 1 2 5 3 
Max element is: 5
Min element is: 1

Stack: -1 1 2 5 3 
Max element is: 5
Min element is: -1

Pop element ... 

Poping element 3
Stack: -1 1 2 5 
Max element is: 5
Min element is: -1

Erase the stack ...
 
Stack is empty ... 
*/