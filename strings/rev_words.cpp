#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;


// reverse a char
//
string reversed(char *tok)
{
    stringstream ss;
    string s, ret;
    ss << tok;
    s = ss.str();

    ret.assign(s.rbegin(), s.rend());
    return ret;
}


// reverse every word in a string/sentence and not all string/sentence
//
void rev_sent(char *s)
{
    char *tok;
    const char * delimeters = " ";
    
    tok = strtok(s, delimeters);
    
    while(tok)
    {
        cout << reversed(tok) << " ";
        tok = strtok(NULL, delimeters);
    }
}




int main()
{
    char sentence[] = "This should be printed correctly!";
    char rev_sentence[] = "sihT dluohs eb detnirp !yltcerroc";

    rev_sent(rev_sentence);
    cout << "\nThis should NOT :: \n";
    rev_sent(sentence);
    cout << endl;

    return 0;
}