#ifndef FINALBATTLE_H
#define FINALBATTLE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class final
{
    private:
        static const int ROWS = 3;
        static const int COLS = 3;
    public: 
        void displayBoard(char board[ROWS][COLS]);
        bool checkWin(char board[ROWS][COLS]);
        void sorcererMove(char board[ROWS][COLS]);
        void userMove(char board[ROWS][COLS]);
        //bool totalGame();
};

#endif