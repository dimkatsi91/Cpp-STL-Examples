/*
 * Acronyms Test
 *
 * INPUT: [One, Two, Five]
 * OUTPUT: O.T.F.
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string acronym(vector<string> input)
{
    string check("");

    for(auto & word : input)
    {
        string::iterator itr = word.begin();
        check = check + *itr + ".";
        // itr = word.end();    // oops | no need 
    }

    //return check;
    
    // If you don't want last dot just ::
    return check.substr(0, check.size()-1);
}


int main()
{
    vector<string> test{"Zone", "Improvement", "Plan"};
    cout << acronym(test) << endl;

    vector<string> test2{"Yet", "Another", "Markup", "Language"};
    cout << acronym(test2) << endl;

    vector<string> dimkats{"Dimos", "Failes", "In", "Timing"};
    cout << acronym(dimkats) << endl;

    return 0;
}

