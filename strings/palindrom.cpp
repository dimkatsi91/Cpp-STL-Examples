#include <iostream>
#include <string>
#include <vector>

using namespace std;


template<class type>
class Palindrom {
public:
    Palindrom(type o) : obj(o) {}
    bool is_palindrom() {
        typename type::iterator start = obj.begin();
        typename type::reverse_iterator end = obj.rbegin();
        size_t iterations = obj.size()/2;
        while( iterations!=0 )
        {
            //cout << "Iteration #" << (obj.size()/2) - iterations << endl;
            //cout << "iter = " << *start << "\t\t\trev_iter = " << *end << endl;

            if( *start != *end )
            {
                return false;
            }

            start++;
            end++;

            iterations--;
        }
        return true;
    }
    //
    void palindrom() {
        cout << ( !is_palindrom() ? "not Palindrom!\n" : "Palindrom!\n");
        cout << endl;
    }
    type getObj() {
        return obj;
    }
private:
    // commonly a string
    type obj;
};



int main()
{
    Palindrom<string> diman("dimannamid");
    Palindrom<string> dim("dimos");
    Palindrom<string> three("123454321");
    Palindrom<vector<int>> four({1,2,3,4,5});
    Palindrom<vector<int>> five({1,2,3,4,5,4,3,2,1});

    diman.palindrom();
    dim.palindrom();
    three.palindrom();
    four.palindrom();
    five.palindrom();

    return 0;
}

/* OUTPUT :

Palindrom!

not Palindrom!

Palindrom!

not Palindrom!

Palindrom!

*/