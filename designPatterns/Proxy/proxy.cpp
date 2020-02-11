#include <iostream>

using namespace std;


// Interface class
//
class Space {
public:
    virtual ~Space() {} 
    virtual void entropy() = 0;
};

// God implements Space interface
//
class God : public Space {
public:
    void entropy() {
        cout << "God is everything ... also implements space and has plenty of entropy due to Its wisdom...\n";
    }
};

// Religion is the Proxy class in order to access God
//
class Religion : Space {
    God *god;
public:
    Religion() : god(new God()) {}
    ~Religion() {
        delete god;     // play safe!
    }
    void entropy() {
        god->entropy();
        cout << " ... and speaks through Your religion (i.e the Proxy) ...\n";
    }
};


int main()
{
    Religion * rel = new Religion();

    rel->entropy();

    return 0;
}

/* OUTPUT ::    Have fun ! And believe in what has already hapenned ! We are just performers of this illusion !!!

God is everything ... also implements space and has plenty of entropy due to Its wisdom...
 ... and speaks through Your religion (i.e the Proxy) ...

*/