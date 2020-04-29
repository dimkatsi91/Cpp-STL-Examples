#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;


class Person {
public:
    string fname,  lname, phone;
    // CTor
    //
    Person(string fname, string lname, string cpNumber)
        : fname(fname), lname(lname), phone(cpNumber)
    {}
};


static int id=0;

class Dictionary {
public:
    Person entry;
    map<int, Person> entries;
    // CTor
    //
    Dictionary(Person person) 
        : entry(person) 
        {
            entries.insert(pair<int, Person>(id++, person));    
        }
    ~Dictionary() { id=0; }
    // add an entry in the dictionary
    //
    void addEntry(const Person &person) {
        entries.insert(pair<int, Person>(id++, person));
    }
};

typedef typename map<int, Person>::iterator mapItr;

class DictioPrinter {
public:
    void print(Dictionary dictio) 
    {
        mapItr start = dictio.entries.begin();
        mapItr end   = dictio.entries.end();
        cout << "ID      FIRST-NAME     LAST-NAME       PHONE-NUMBER" << endl;
        cout << "---------------------------------------------------" << endl; 
        while(start != end) {
            cout << start->first << "\t" << start->second.fname
                 << "\t\t" << start->second.lname
                 << "\t\t" << start->second.phone << endl;

            start++;
        }
    }
};

class DictioSaver {
public:
    void save(Dictionary dictio, const string & filename) 
    {
        ofstream fstream(filename);
        mapItr start = dictio.entries.begin();
        mapItr end   = dictio.entries.end();
        fstream << "ID      FIRST-NAME     LAST-NAME       PHONE-NUMBER" << endl;
        fstream << "---------------------------------------------------" << endl; 
        while(start != end) {
            fstream << start->first << "\t" << start->second.fname
                 << "\t\t" << start->second.lname
                 << "\t\t" << start->second.phone << endl;

            start++;
        }
        fstream.close();
    }
};

int main() {

    Person diman("Rivaldo", "Fereira", "123-456-789");
    Person gio("Ronaldo", "Lima", "987-333-444");
    Dictionary myDictio(diman);
    myDictio.addEntry(gio);

    DictioPrinter dictPrinter;
    dictPrinter.print(myDictio);

    DictioSaver dictSaver;
    dictSaver.save(myDictio, "dictionary.txt");


    return 0;
}

/*

ID      FIRST-NAME     LAST-NAME       PHONE-NUMBER
---------------------------------------------------
0       Rivaldo         Fereira         123-456-789
1       Ronaldo         Lima            987-333-444

*/