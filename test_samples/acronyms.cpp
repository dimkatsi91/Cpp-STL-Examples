/*
 * Acronyms Test
 *
 * INPUT: [Zone, Improvement, Plan]
 * OUTPUT: Z.I.P.
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
        itr = word.end();

        cout << endl;
    }

    return check;
}


int main()
{
    vector<string> test{"Zone", "Improvement", "Plan"};
    cout << acronym(test) << endl;

    return 0;
}

