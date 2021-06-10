#include <iostream>
#include "Player.h"

using namespace std;

void displayActivePlayers() {
    cout << "Active players: " << Player::getPlayerCount() << endl;
}

int main() {
    displayActivePlayers();

    Player hero {"Hero", 100};

    displayActivePlayers();

    {
        Player zero {"Zero", 100};
        displayActivePlayers();
    }

    displayActivePlayers();

    return 0;
}