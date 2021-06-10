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
        string getName() const {
            return name;
        }
        void setName(string name) {
            this->name = name;
        }
};

// Overloaded constructors with initializtion list
Player::Player() : Player {"None", 0, 0} {
    //cout << "No-args constructor" << endl;
}

Player::Player(string nameVal) : Player {nameVal, 0, 0} {
    // cout << "One-args constructor" << endl;
}

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    // cout << "Three-args constructor" << endl;
}

void display(const Player &src) {
    //src.setName("Hero1");
    cout << src.getName() << endl;
}

int main() {
    const Player villain {"Villain", 100, 55};
    // villain.setName("Super Villain");
    // villain.getName();
    Player hero {"Hero", 100, 15};

    display(villain);
    display(hero);

    return 0;
}