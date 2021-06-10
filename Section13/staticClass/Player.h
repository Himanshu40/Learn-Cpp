#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
        static int count;
        std::string name;
        int health;
        int xp;
    public:
        std::string getName();
        int gethealth();
        int getXp();
        static int getPlayerCount();
        Player(std::string name = "None",
               int health = 0,
               int xp = 0);
        Player(const Player &src);
        ~Player();
};

#endif