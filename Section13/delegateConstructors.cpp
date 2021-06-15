#include <iostream>

using namespace std;

class Player {
        string name;
        int health;
        int xp;
    public:
        Player();
        Player(string nameVal);
        Player(string nameVal, int healthVal, int xpVal);
};

// Overloaded constructors with initializtion list
Player::Player() : Player {"None", 0, 0} {
    cout << "No-args constructor" << endl;
}

Player::Player(string nameVal) : Player {nameVal, 0, 0} {
    cout << "One-args constructor" << endl;
}

Player::Player(string nameVal, int healthVal, int xpVal) : name {nameVal}, health {healthVal}, xp {xpVal} {
    cout << "Three-args constructor" << endl;
}

int main() {
    Player frank;
    /*Player enemy {"Enemy"};
    Player thor {"Thor", 100, 0};

    Player *cap =  new Player("Cap");

    delete cap;*/

    return 0;
}