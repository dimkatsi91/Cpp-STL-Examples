#include <iostream>
#include <string>

using namespace std;

void capitalize(string & str) {
    for(auto & ch : str)
        ch = toupper(ch);
}

string shuffle_words(string input1, string input2, string input3) {
    
    if(input1.empty() || input2.empty() || input3.empty()) {
        cout << "One of three strings is empty .. Cannot be shuffle .. Aborting ...\n";
        return "no";
    }

    if(input1.empty() && input2.empty() && input3.empty()) {
        return "yes";
    }

    capitalize(input1);
    capitalize(input2);
    capitalize(input3);

    bool exists = true;
    string::iterator itr1 = input1.begin();
    string::iterator itr2 = input2.begin();

    while(itr1!=input1.end()) {
        size_t found1 = input3.find(*itr1);

        if(found1!=string::npos)
            exists=true;
        else {
            exists=false;
            break;
        }

        itr1++;
    }

    while(itr2!=input2.end()) {
        size_t found2 = input3.find(*itr2);

        if(found2!=string::npos)
            exists=true;
        else {
            exists=false;
            break;
        }

        itr2++;
    }

    return exists==false ? "no" : "yes";
}


int main()
{
    string s1("hellO");
    string s2("WoRlD");
    string s3("helloWorld");
    string s4("helloDiman");
    string s5("BUHAHAHAHAHA");
    string empty("");
    string reverse("OLLEHDLROW");

    cout << shuffle_words(s1, s2, s3) << endl;

    cout << shuffle_words(s1, s2, s4) << endl;

    cout << shuffle_words(s1, s2, s5) << endl;

    cout << shuffle_words(s1, s2, empty) << endl;

    cout << shuffle_words(s1, s2, reverse) << endl;

    return 0;
}