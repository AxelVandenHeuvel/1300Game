#include <iostream>
#include "party.h"

using namespace std;

Party :: Party()
{
    string inputName;

    cout << "Enter the name of the leader: ";
    cin >> inputName;
    
    players[0] = Player(inputName, 100);

    for (int i = 1; i <= 4; i++)
    {
        cout << "Enter the name of the party member: ";
        cin >> inputName;
        players[i] = Player(inputName, 100);
    }

    cout << "The party has been created." << endl;

    numPlayers = 5;
}

int Party :: getNumPlayers()
{
    // Get num players with health > 0
    int numAlive = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].getFullness() > 0)
        {
            numAlive++;
        }
    }
    return numAlive;
}

int Party :: getPlayerFullness(int index)
{
    return players[index].getFullness();
}
void Party :: setNumPlayers(int num)
{
    numPlayers = num;
}

Player Party :: getPlayer(int index)
{
    return players[index];
}
bool Party :: isMainPlayerAlive()
{
    if (players[0].getFullness() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Party :: reducePlayerFullness(int index, int damage)
{
    players[index].setFullness(players[index].getFullness() - damage);
}
void Party :: killPlayer(int index)
{
    players[index].setFullness(0);
    setNumPlayers(getNumPlayers() - 1);
}
void Party :: eatFood(int amount)
{
    int hp = amount / 5;
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].getFullness() > 0) // checking if they are dead 
        {
            players[i].setFullness(players[i].getFullness() + hp);
        }
    }
}
void Party :: printParty()
{
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    cout << "\033[34m" << "| Party       |" << "\033[0m" << endl;
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << players[i].getName() << " " << players[i].getFullness() << endl;
    }
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
}
string Party :: getPartyPlayerName(int index)
{
    return players[index].getName();
}