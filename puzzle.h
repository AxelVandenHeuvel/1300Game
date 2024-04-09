#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>

using namespace std;

class Puzzle
{
    private:
        int numPuzzles;
        string questions[50];
        string answers[50];
    public:
        Puzzle();
        bool doorPuzzle();
        string getPuzzle(int index);
        string getAnswer(int index);
        int getNumPuzzles();
        void setNumPuzzles(int newNumPuzzles);

};

#endif