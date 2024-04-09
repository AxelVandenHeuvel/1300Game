#include <iostream>
#include "player.h"

using namespace std;

Player :: Player()
{
    name = " ";
    fullness = 50;
}
Player :: Player(string playerName, int playerFullness)
{
    name = playerName;
    fullness = playerFullness;
}
string Player :: getName()
{
    return name;
}
int Player :: getFullness()
{
    return fullness;
}
void Player :: setFullness(int playerFullness)
{
    fullness = playerFullness;
}