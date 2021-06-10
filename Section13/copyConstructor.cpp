#include <iostream>

using namespace std;

class Player {
        string name;
        int health;
        int xp;
    public:
        Player(string nameVal = "None", int healthVal = 0, int xpVal = 0);
        // Copy constructor declaration
        Player(const Player &src);
        string getName();
        int getHealth();
        int getXp();
        ~Player();
};

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three-args constructor for: " << name << endl;
}

// Copy Constructor definition
/*Player::Player(const Player &src) : name{src.name}, health{src.health}, xp{src.xp} {
    cout << "Copy constructor - made copy of: " << src.name << endl;
}*/

// Copy Constructor definition using delegation
Player::Player(const Player &src) : Player {src.name, src.health, src.xp} {
    cout << "Copy constructor - made copy of: " << src.name << endl;
}

string Player::getName() {
    return name; 
}

int Player::getHealth() {
    return health;
}

int Player::getXp() {
    return xp;
}

Player::~Player() {
    cout << "Destructor called for: " << name << endl;
}

void display(Player p) {
    cout << "Name: " << p.getName() << endl;
    cout << "Health: " << p.getHealth() << endl;
    cout << "XP: " << p.getHealth() << endl;
}

int main() {
    Player frank;
    display(frank);

    /*Player empty {"Empty", 100, 50};
    Player newEmpty {empty};
    display(newEmpty);*/

    /*Player enemy {"Enemy"};
    Player thor {"Thor", 100, 0};

    Player *cap =  new Player("Cap");

    delete cap;*/

    return 0;
}