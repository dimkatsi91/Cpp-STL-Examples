#include <iostream>
#include <cstring>

using namespace std;


// char *strtok(char *str, const char *delimeters);
void test_strtok(char *str, const char *delimeters) {
    char *tok = strtok(str, delimeters);
    while(tok) {
        cout << tok << endl;
        tok = strtok(NULL, delimeters);
    }
}

// Another test function to extract email username & email given that the str is given correctly
// format: username@XXXXXXXX.YYY    || assasin_une@protonmail.com
void extract_info(char *email_addr) {
    const char* delims = "@.";
    char *tok = strtok(email_addr, delims);
    cout << "\nUsername: " << tok << endl;
    tok = strtok(NULL, delims);
    cout << "Domain: " << tok << "." << strtok(NULL, delims) << endl; 
}

int main()
{
    char str[] = "This is ?a test:for strtok function, use this one. Out!";
    const char *delimeters = ", .!?:";
    test_strtok(str, delimeters);

    char email_addr[] = "assassin_deux@protonmail.com";
    extract_info(email_addr);

    return 0;
}

/* OUTPUT :: 

This
is
a
test
for
strtok
function
use
this
one
Out

Username: assassin_deux
Domain: protonmail.com

*/