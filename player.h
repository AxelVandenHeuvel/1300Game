#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player
{
    private:
        string name;
        int fullness;
    public:
        Player();
        Player(string playerName, int playerFullness);
        string getName();
        int getFullness();
        void setFullness(int playerFullness);
};

#endif