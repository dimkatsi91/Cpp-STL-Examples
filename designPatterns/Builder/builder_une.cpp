#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Position {
    GK,
    Defender,
    Midfielder,
    Striker
};

// class for a player
class Player {
private:
    string name;
    Position position;
public:
    Player() {}
    Player(const Position & position, const string & name)
        : name(name), position(position) {}
    string getPos() const {
        switch(position) {
            case Position::GK:
                return "GoalKeeper";
                break;
            case Position::Defender:
                return "Defender";
                break;
            case Position::Midfielder:
                return "MidFielder";
                break;
            default:
                return "Striker";
                break;
        }
    }
    void info() {
        cout << "Player " << name;
    }
    void setName(const string & name) { this->name=name; }
    void setPosition(const Position & position) { this->position=position; }
};


class PlayerBuilder {
    Player player;
public:
    PlayerBuilder(const string & name,const  Position & position) {
        player.setName(name);
        player.setPosition(position);
    }
    void builderInfo() {
        player.info();
        cout <<  " is a " << player.getPos() << endl;
    }
};

static int once{-1};

// let's create a team of 5 players only | It is goingto play in 5X5
//
class FootballTeam {
private:
    vector<PlayerBuilder> players;
    int squadSize;
    string name;
public:
    FootballTeam(vector<PlayerBuilder> players, int squadlen, const string& teamName) 
        : players(players), squadSize(squadlen), name(teamName) 
    {
        if(once<0) {
            cout << "**********************************************************\n";
            cout << "Match type: " << squadSize << " X " << squadSize << endl;
            cout << "Team Name: " << name << endl;
            cout << "**********************************************************\n";
        }
        for(auto &player : players) {
            cout << " Adding a plyer in team: " << name << "\n";
            player.builderInfo();
        }
        once++;
    }
};


int main() {
    
    vector<PlayerBuilder> players{ {"Nikos", Position::GK}, 
                                   {"Thom", Position::Defender}, 
                                   {"Dimitri", Position::Midfielder},
                                   {"George", Position::Midfielder},
                                   {"Dimos", Position::Striker} };

    FootballTeam arakynthos
        {
            players,
            5,
            "Arakynthos United"
        };

    return 0;
}