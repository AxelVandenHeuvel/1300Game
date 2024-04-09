#include <iostream>
#include <cstdlib>
#include "item.h"
#include "map.h"
#include "monsters.h"
#include "party.h"
#include "puzzle.h"
#include "misfortunes.h"


using namespace std;

class Game: public Map, public Monster, public Puzzle, public misfortune
{
    private:
        int sorcererAnger;
        int numRoomsPassed;
        int numKeys = 0;
        int rooms;
        int sorcerer;
        static const int ROWS = 3;
        static const int COLS = 3;
    public:
        Game(); // default constructor
        bool chance(int start, int end);
        int getSorcererAnger();
        void getSorcerer();
        int getRoomsCleared();
        void setSorcererAnger(int anger);
        void setRoomsPassed(int rooms);
        void printStatus(); // inventory and map and such
        bool actionMenu(); // playerAction
        bool roomSpaceMenu(); // actions when on a room
        bool npcMenu(); // actions when on an NPC space
        bool gameEnd(); 
        void misfortune100(); // misfortune class call
        void movement();
        bool activateFightMonster();
        void outputStats();
        int finalExit();
        void displayBoard(char board[ROWS][COLS]);
        bool checkWin(char board[ROWS][COLS]);
        void sorcererMove(char board[ROWS][COLS]);
        void userMove(char board[ROWS][COLS]);
        bool totalGame();
};