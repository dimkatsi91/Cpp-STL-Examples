#include <iostream>
#include <string>

using namespace std;

class Test {
public:
    Test(string _str) : str(_str) {}
    bool replace_str(string &s, const string &oldsubstr, const string &newsubstr) {
        
        s.assign(str.begin(), str.end());
        string::size_type idx;
        idx = s.find(oldsubstr);
        if(idx!=string::npos) {
            s.replace(idx, oldsubstr.size(), newsubstr);
            str.assign(s.begin(), s.end());
            return true;
        }
        return false;
    }
    void print_replaced_str(const string &_old, const string &_new) {
        if (!replace_str(str, _old, _new))  
            cout << "ERROR!\n";
        else
            cout << str << endl;
    }
private:
    string str;
};


int main()
{
    Test test("This is [space] a demonstration test.");
    test.print_replaced_str("[space]", "only");


    return 0;
}