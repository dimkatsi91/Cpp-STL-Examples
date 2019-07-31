#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack< double > doubleStack;
    const size_t doubleStackSize = 5;
    double doubleValue = 1.1;

    cout << "Pushing elements onto doubleStack\n";

    for(size_t i=0; i<doubleStackSize; ++i)
    {
        doubleStack.push(doubleValue);
        cout << doubleValue << " ";
        doubleValue += 1.1;
    }

    cout << "\n\nPoping elements from doubleStack\n";
    while( !doubleStack.isEmpty() ) {
        cout << doubleStack.top() << " ";
        doubleStack.pop();
    }
    cout << "\nStack is now empty. Can not pop.\n\n";

    cout << "\n\nINTEGERS STACK NOW\n\n";
    Stack< int > intStack;
    const size_t intStackSize = 10;
    int intValue = 1;

    cout << "Pushing elements onto intStack\n";
    for(size_t i =0; i<intStackSize; ++i) {
        intStack.push( intValue );
        cout << intValue++ << " ";
    }

    cout << "\n\nPoping elements from intStack\n";
    while( !intStack.isEmpty() ) {
        cout << intStack.top() << " ";
        intStack.pop();
    }
    cout << "\nIntStack is now empty. Cannot pop anymore...\n";

    return 0;
}
