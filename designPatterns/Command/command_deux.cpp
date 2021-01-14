/*
 * Command Design Pattern : deuxieme trivial demonstrational example
 * 
 *           Behavioral Pattern
 */

#include <iostream>

using namespace std;

// Interface class | Abstract | To be implemented
//
class Command {
public:
    virtual void action() = 0;
};

// TV class
//
class TV {
public:
    void turnOn() {
        cout << "Turning on TV ...\n";
    }
    void turnOff() {
        cout << "Turning off TV ...\n";
    }
};

// TurnOnCommand class implemenets Command class
// This class has a pointer to TV class, so we can call TV's 
// method while implementing Command interface
//
class TurnOnCommand : public Command {
public:
    TurnOnCommand(TV *tv) : tv(tv) {}
    ~TurnOnCommand() { delete this->tv; }
    void action() {
        tv->turnOn();
    }
private:
    TV *tv;
};

// TurnOffCommand class implements Command class
// Same logic as with TurnOnCommand's class binding
// with the Command class/interface
//
class TurnOffCommand : public Command {
public:
    TurnOffCommand(TV *tv) : tv(tv) {}
    ~TurnOffCommand() { delete this->tv; }
    void action() {
        tv->turnOff();
    }
private:
    TV *tv;
};

// TV class is controlled by the Controller class
// which has to execute a Command, either turnOn() or turnOff()
// Controller Object has a pointer to Command I/F and takes an action
// either turnOn() or turnOff()
//
class Controller {
public:
    void set_cmd(Command *cmd) {
        this->cmd = cmd;
    }
    void take_action() {
        this->cmd->action();
    }
    ~Controller() { delete this->cmd; }
private:
    Command *cmd;
};



int main() {

    // TV Object
    TV * MiTV = new TV();

    // On & Off Commands Objects
    TurnOnCommand * tonc = new TurnOnCommand(MiTV);
    TurnOffCommand * toffc = new TurnOffCommand(MiTV);

    // Controlelr Object
    Controller * ctrl = new Controller();

    // Set command and execute action via controller --> on()
    ctrl->set_cmd(tonc);
    ctrl->take_action();

    // Set command and execute action via controller --> onff()
    ctrl->set_cmd(toffc);
    ctrl->take_action();

    // Clear
    delete MiTV,tonc,toffc,ctrl;

    return 0;
}
