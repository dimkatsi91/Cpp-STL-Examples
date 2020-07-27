#include <iostream>
#include <vector>
#include <string>

using namespace std;


void print(string &other) {
    string::iterator start = other.begin();
    while(start!=other.end()) {
        cout << *start;
        start++;
    }
    cout << endl;
}

int main() 
{
    string name("Hello, Diman ...");
    string une(" -> ZInedine <- ");

    name.replace(name.end(), name.begin(), une);

    print(name);


    return 0;
}

