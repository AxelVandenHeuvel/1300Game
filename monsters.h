#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>

using namespace std;

class Monster
{
    private:
        string monsters[50];
        string monstersDefeated[50];
        int numMonsters;
        int numMonstersDefeated;
    public:
        Monster();
        string getMonster(int tier);
        string getSorcerer();
        int getMonsterHealth(int tier);
        void defeatMonster(string monster);
        int getNumMonsters();
        int getNumMonstersDefeated();
        void addMonsterDefeated(string monsterName);
        bool monsterBattle(int roomsCleared, double prob);
};

#endif