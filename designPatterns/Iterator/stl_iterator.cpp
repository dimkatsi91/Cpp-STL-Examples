/*
 * Simple Example for Iterator DP: Using STL's built-in iterator
 * upon a std::vector
 * Iterator is essentially used for traversing a vector, a map, etc.
 * It is a pointer and it can be a normal iterator or a reverse_iterator
 * Also, an iterator can be 'const'
*/
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;

enum class ORDER {
    NORMAL,
    REVERSE,
    SHUFFLE
};
 
template<class T>
void print(vector<T> & vec, const ORDER & order)
{
    // Just declare a normal iterator start pointing to the start of the vector
    // And another, a reverse iterator this time pointing to the end of the vector
    typename vector<T>::iterator start = vec.begin();
    typename vector<T>::reverse_iterator end = vec.rbegin();
    // Make a desicion based on the switch/option
    //
    switch(order)
    {
        case ORDER::NORMAL:
            while(start != vec.end()) {
                cout << *start;
                cout << ( (start != vec.end()-1) ? ", " : "\n" );
                start++;
            }
            break;
        case ORDER::REVERSE:
            while( end != vec.rend() ) {
                cout << *end;
                cout << ( (end != vec.rend()-1) ? ", " : "\n" );
                end++;
            }
            break;
        default:
            cout << "\nUnspecified traverse option/order ... Aborting ...\n";
            break;
    }
}


int main() 
{
    // 1st PART: Simple Vector
    //
    vector<string> skills{"C++", "K8s", "Git", "Linux", "OpenStack"};
    
    print(skills, ORDER::NORMAL);

    print(skills, ORDER::REVERSE);

    print(skills, ORDER::SHUFFLE);

    // 2nd PART: Vector of Vector of strings
    //
    vector<vector<string>> multi{
        {"une", "deux", "trois"},
        {"Jenkins", "VMware", "Go(lang)", "Python"}
    };

    for(size_t i = 0 ; i < multi.size() ; i++)
        (i%2==0) ? print(multi.at(i), ORDER::NORMAL) : print(multi.at(i), ORDER::REVERSE);

    return 0;
}
