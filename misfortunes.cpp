#include <iostream>
#include <cstdlib>
#include "misfortunes.h"

using namespace std;

misfortune :: misfortune()
{
    // Nothing to do here
}
void misfortune :: robbed()
{
    srand(time(NULL));
    int random = rand() % 3 + 1;
    if (random == 1) // 3 different scenarios for being robbed
    {
        cout << "\033[31m" << "You were robbed by a group of dungeon bandits!" << "\033[0m" << endl;
        cout << "\033[31m" << "They have taken 10kg of ingredients from you!" << "\033[0m" << endl;
        if (getIngredients() < 10)
        {
            setIngredients(getIngredients() - getIngredients());
        }
        else
        {
            setIngredients(getIngredients() - 10);
        }
    }
    else if (random == 2)
    {
        cout << "\033[31m" << "You were robbed by a group of dungeon bandits!" << "\033[0m" << endl;
        cout << "\033[31m" << "They have taken one cookware item from you" << "\033[0m" << endl;
        if (getTotalCookware() < 1)
        {
            cout << "The bandits are dissapointed in you..." << endl;
        }
        else
        {
            bool cookwareRemoved = false;
            while (!cookwareRemoved)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (getCookware(i) < 1)
                    {
                        continue;
                    }
                    else
                    {
                        setCookware(getCookware(i) - 1, i);
                        cookwareRemoved = true;
                        break;
                    }
                }
            }
        }
    }
    else if (random == 3)
    {
        cout << "\033[31m" << "You were robbed by a group of dungeon bandits!" << "\033[0m" << endl;
        cout << "\033[31m" << "They have taken 1 armor from you!" << "\033[0m" << endl;
        if (getArmor() < 1)
        {
            cout << "The bandits are dissapointed you have no armor..." << endl;
        }
        else
        {
            setArmor(getArmor() - 1);
        }
    }
    else
    {
        cout << "..." << endl;
    }
}

void misfortune :: breaks()
{
    srand(time(NULL));
    int random = rand() % 2 + 1;
    if (random == 1)
    {
        if (getTotalWeapons() < 1)
        {
            cout << "Something bad was about to happen but luck was on your side..." << endl;
        }
        else
        {
            bool weaponBroken = false;
            while (weaponBroken == false)
            {
                for (int i = 0; i < getMaxWeapons(); i ++)
                {
                    if (getWeapons(i) < 1)
                    {
                        continue;
                    }
                    else
                    {
                        setWeapons(getWeapons(i) - 1, i);
                        weaponBroken = true;
                        break;
                    }
                }
            }
        }
    }
    if (random == 2)
    {
        if (getArmor() < 1)
        {
            cout << "Something bad was about to happen but luck was on your side..." << endl;
        }
        else
        {
            setArmor(getArmor() - 1);
        }
    }

}
void misfortune :: foodPoisoning()
{
    srand(time(NULL));
    int i = rand() % getNumPlayers() + 1;
    if (getPlayerFullness(i) < 10)
    {
        killPlayer(i);
        cout << "\033[31m" << "Player " << i << " has been poisoned and has died" << "\033[0m" << endl;
        setMaxArmor(getMaxArmor() - 1);
        setMaxWeapons(getMaxWeapons() - 1);
    }
    else
    {
    reducePlayerFullness(i, 10);
    cout << "\033[31m" << "Player " << i << " has been poisoned and has lost 10 health" << "\033[0m" << endl;
    }
}
void misfortune :: treasurefind() // positive misfortune
{
    cout << "Congratulations! You have found a treasure chest!" << endl;
    srand(time(NULL));
    int random = rand() % 30 + 1;
    cout << "You have found " << random << " gold!" << endl;
    setGold(getGold() + random);
}