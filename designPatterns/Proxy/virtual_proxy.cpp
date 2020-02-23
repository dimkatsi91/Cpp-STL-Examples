#include <iostream>
#include <string>

using namespace std;

// Interface class for a Video
//
class Video {
public:
    // pure virtual function makes this class an abstract class
    virtual void play(double) = 0;
};

class Mp4 : public Video {
public:
    Mp4(const string & name) {
        cout << "File " << name << ".mp4 is loading ...\n";
    }
    void play(double bitrate) override {
        cout << "Playing Mp4 video ...\n";
    }
};

class SmartMp4 : public Video {
public:
    SmartMp4(const string & name)
        : name(name) {}
    void play(double bitrate) override {
        // if the mp4 is not loaded, then load it please cause we
        // are going to play this file <name>.mp4
        if(!video) {
            video = new Mp4(name);
        }
        video->play(bitrate);
    }
private:
    string name;
    // initialize this in nullptr, in order not be loaded
    // we do not want to load that video
    // Only when we are gonna play this mp4 video, we should load this object
    Video *video{nullptr};
};

int main() {

    cout << "**************************\n";
    Mp4 mp4("'Rambo I'");
    mp4.play(48.96);
    cout << "**************************\n";

    cout << "\n**************************\n";
    Mp4 rambo_iii("'Rambo III'");
    cout << "**************************\n";

    cout << "\n**************************\n";
    cout << "This is NOT going to be loaded ... \n";
    SmartMp4 rocky_i("'Rocky I'");
    cout << "**************************\n";

    cout << "\n**************************\n";
    SmartMp4 rocky_ii("'Rocky II'");
    rocky_ii.play(96.46);
    cout << "**************************\n";

    return 0;
}

/* OUTPUT 

**************************
File 'Rambo I'.mp4 is loading ...
Playing Mp4 video ...
**************************

**************************
File 'Rambo III'.mp4 is loading ...
**************************

**************************
This is NOT goingto be loaded ... 
**************************

**************************
File 'Rocky II'.mp4 is loading ...
Playing Mp4 video ...
**************************

*/