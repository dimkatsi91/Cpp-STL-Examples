#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Editor {
public:
    enum class ToolBarActions {File, Edit, Selection, View, Go, Debug, Terminal, Help} action;
    enum class SideActions {Explorer, sourceControl, Debugger, Extensions, GitLens} sideAction;
    virtual void setFont(vector<string> &) = 0;
};


class Atom : Editor {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////// MEMENTO CLASS
    class AtomMemento {
        vector<string> fontInfo;
        string name;
        AtomMemento(const string & name, const vector<string> & fontInfo)
            : name(name), fontInfo(fontInfo) {}
        explicit AtomMemento(const Atom & atom)
            : name(atom.getName()), fontInfo(atom.getFontInfo()) {}
        public:
        /*
        static AtomMemento createEditorMemento(const string & name, vector<string> & fontInfo) {
            return {name, fontInfo};
        }
        */
        static AtomMemento createAtomMemento(const Atom & atom) {
            return {atom.getName(), atom.getFontInfo()};
        }
        vector<string> getfontInfo() const { return fontInfo; }
        string getName() const { return name; }
    };
    ///////////////////////////////////////////////////////////////////////

    virtual void setFont(vector<string> & fontInfo) override {
        if(fontInfo.size() < 4) {
            cout << "Please specify font 'family', 'PointSize', 'Boldness' & 'Italicness' and try again!\n";
            font = {"None", "None", "None", "None"};
            return;
        }
        vector<string>::iterator start = fontInfo.begin();
        while(start != fontInfo.end()) {
            font.push_back(*start);
            start++;
        }
    }

    static Atom NewAtom(const string & name, const vector<string> & font) {
        return {name, font};
    }

    friend ostream &operator<<(ostream & os, const Atom & atom) {
        os << "Editor : " << atom.name << endl;
        vector<string> fontInfo{atom.font};
        sItr itr = fontInfo.begin();
        os << "Font   : {" << *itr << ", " << *(++itr) << ", " << *(++itr) << ", " << *(++itr) << "}\n";
        return os;
    }

    void restore(const AtomMemento & eMemento) {
        this->name = eMemento.getName();
        this->font = eMemento.getfontInfo();
    }

    string getName() const { return name; }
    void setName(const string & name) { this->name = name; }
    vector<string> getFontInfo() const { return font; }

private:
    typedef vector<string>::iterator sItr;
    vector<string> font;    // font{"family", "PointSize", "bold", "Italic"}
    string name{"Atom"};
    Atom(const string& name, const vector<string> & font) 
        : name(name), font(font) {}
};


int main() {
    // create the atom object
    //
    cout << "******************************************************************\n";
    vector<string> fontInfo{"Verdana", "14", "True", "False"};
    Atom atom_une = Atom::NewAtom("Atom Editor", fontInfo); 
    cout << atom_une;

    // create a snapshot of previous atom configuration
    //
    auto snapshot_une = Atom::AtomMemento::createAtomMemento(atom_une);

    // Now update atom_une Editor Consfigurations
    //
    cout << "******************************************************************\n";
    atom_une.setName("VS Code Editor");
    fontInfo = {"Courier", "18", ""};
    atom_une.setFont(fontInfo); // exception cout message printed out here
    cout << atom_une;

    // restore atom configurations
    //
    cout << "******************************************************************\n";
    atom_une.restore(snapshot_une);
    cout << atom_une;

    return 0;
}