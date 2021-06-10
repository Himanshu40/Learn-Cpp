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
Player::Player() : name{"None"}, health{0}, xp{0} {}
Player::Player(string nameVal) : name{nameVal}, health{0}, xp{0} {}
Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {}

int main() {
    Player frank;
    Player enemy {"Enemy"};
    Player thor {"Thor", 100, 0};

    Player *cap =  new Player("Cap");

    delete cap;

    return 0;
}