#include <iostream>

using namespace std;

void square(int &num) {
    num *= 2;
}

int main() {

    int num = 10;
    int *p = &num;
    // int num2 = 10;
    // int *p = &num2;

    square(num);
    cout << "num = " << num << endl;

    square(*p);
    cout << "*p = " << *p << endl;

    return 0;
}

// What is the output of num and the value pointed by p pointer ??
// Be careful, cause it is by reference

// 2nd :: comment out line 12 and un-comment lines 13+14
// What are the values of num and *p then ??

// 1st simple test out ...
//