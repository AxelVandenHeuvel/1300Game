#include <iostream>
#include <ctime>
#include <cstdlib>
#include "gameActions.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Game game;
    game.totalGame();
    return 0;
}