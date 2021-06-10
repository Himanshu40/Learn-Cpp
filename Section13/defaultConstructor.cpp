#include <iostream>

using namespace std;

class Player {
        string name;
        int health;
        int xp;
    public:
        Player(string nameVal = "None", int healthVal = 0, int xpVal = 0);
};

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three-args constructor" << endl;
}

int main() {
    Player frank;
    Player enemy {"Enemy"};
    Player thor {"Thor", 100, 0};

    Player *cap =  new Player("Cap");

    delete cap;

    return 0;
}