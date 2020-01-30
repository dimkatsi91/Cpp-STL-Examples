#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////                       MEMENTO PATTERN :: Returns an Object'ssnapshot               ////
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


// Interface class for any Linux distro
//
class Linux {
public:
    virtual float updateIsoSize() = 0;
};

// The Memento class !
//
// immutable Object | should not have a member variable/function that handles values of it
//
class Memento {
    float image_size;
public:
    Memento(float image_size) : image_size(image_size) {}
    float getImageSize() const { 
        return image_size;
    }
};

class Mint : Linux {
public:
    // factory pattern to create and return a new Mint Object please ::
    //
    static Mint newMint(float image_size) {
        return {image_size};
    }
    // implement Linux interface please now ::
    //
    virtual float updateIsoSize() override {
        return image_size;
    }

    float getIsoSize() const {
        return image_size;
    }

    // Grab the snapshot
    //
    Memento updateIsoSize(float image_size) {
        this->image_size = image_size;
        return /*Memento*/{image_size};
    }
    // Restore the Linux Mint's iso size to previous one using Memento's image_size
    //
    void restore(const Memento & snap) {
        this->image_size = snap.getImageSize();
    }
    // Print the Mint Object please ::
    //
    friend ostream &operator<<(ostream& os, const Mint & mint) {
        os << "Linux Mint Iso Size: " << mint.image_size << " GB\n";
        return os;
    } 
private:
    float image_size{0.0};
    Mint(float image_size) : image_size(image_size) {} 
};

//
// Not my favorite example , but You get the point of restoring to a specific snapshot back in time
//
// MAIN
//
int main()
{
    Mint mint = Mint::newMint(0.98);
    auto snapshot_une = mint.getIsoSize();                  // 0.98 GB
    auto snapshot_deux = mint.updateIsoSize(2.23);      // mint_deux has iso size : 2.23 GB
    auto snapshot_trois = mint.updateIsoSize(3.34);  // mint_trois has iso size : 3.34 GB 

    cout << mint;   // should be 3.34 GB
    
    mint.restore(snapshot_une);    // should now be 0.98 GB
    cout << mint;

    mint.restore(snapshot_deux);       // should be now 3.34 GB
    cout << mint;

    return 0;
}