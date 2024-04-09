#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include "player.h"

using namespace std;

class Party
{
    private:
        int numPlayers = 0;
        Player players[5]; // zero is main character
    public:
        Party();
        int getNumPlayers();
        int getPlayerFullness(int index);
        Player getPlayer(int index);
        bool isMainPlayerAlive();
        void setNumPlayers(int num);
        void reducePlayerFullness(int index, int damage);
        void killPlayer(int index);
        void eatFood(int amount);
        void printParty();
        string getPartyPlayerName(int index);
};

#endif