#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>       // accumulate
#include <string>


using namespace std;


class Programmer {
    enum Statistics { stamina, creativity, speed, count };
    array<int, count> statistics;
public:
    Programmer(int st, int cr, int sp)
    {
        set_stamina(st);
        set_creativity(cr);
        set_speed(sp);
    }

    int get_speed() const { return statistics[speed]; }
    void set_speed(int sp) { statistics[speed] = sp; }

    int get_creativity() const { return statistics[creativity]; }
    void set_creativity(int cr) { statistics[creativity] = cr; }

    int get_stamina() const { return statistics[stamina]; }
    void set_stamina(int st) { statistics[stamina] = st; }

    /////////////
    double total_score() const {
        return accumulate(statistics.begin(), statistics.end(), 0);
    }

    double avg() const {
        return total_score() / (double) count;
    }

    int best_ability() const {
        return *max_element(statistics.begin(), statistics.end());
    }

    string get_best_ability() const {
        int position=7; // [ NONE ]
        for (int i=0; i<count; i++) {
            if(statistics[i] == best_ability())
                position=i;
        }
        switch(position)
        {
            case 0:
                return "Stamina";
                break;
            case 1:
                return "Creativity";
                break;
            case 2:
                return "Speed";
                break;
            default:
                return "[ NONE ]";
                break;
        }
    }

    friend ostream & operator<<(ostream & os, const Programmer & pr) {
        os << "******************************************************\n"
           << "Stamina     : " << pr.get_stamina() << endl
           << "Speed       : " << pr.get_speed() << endl
           << "Creativity  : " << pr.get_creativity() << "\n"
           << "TOTAL SCORE : " << pr.total_score() << "/300 \n"
           << "Best ability : " << pr.get_best_ability() << " \n"
           << "******************************************************\n\n";
        return os;
    }
};


int main() {

    Programmer elliot(88, 90, 98);
    cout << elliot;

    Programmer diman(50, 70, 60);
    cout << diman;

    Programmer admin(79, 78, 77);
    cout << admin;

    return 0;
}

/* Example for Corona virus time pass .... times have already changed ... a pitty indeed ...

    OUTPUT ::

$ ./player.exe
******************************************************
Stamina     : 88
Speed       : 98
Creativity  : 90
TOTAL SCORE : 276/300
Best ability : Speed
******************************************************

******************************************************
Stamina     : 50
Speed       : 60
Creativity  : 70
TOTAL SCORE : 180/300
Best ability : Creativity
******************************************************

******************************************************
Stamina     : 79
Speed       : 77
Creativity  : 78
TOTAL SCORE : 234/300
Best ability : Stamina
******************************************************

*/