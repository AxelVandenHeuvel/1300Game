#include <iostream>
#include <fstream>
#include "monsters.h"

using namespace std;

int split(string inputString, char separator, string arr[], int arrSize)
{
    int pieces = 0, startIndex = 0, endIndex = 0;
    if (inputString == "") // if no value in entered for the string. 
    {
        return 0;
    }
    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == separator)
        {
            endIndex = i; // if the charcter that the for loop is scanning is equal to the separator, then the end index is equal to the index of the for loop.
            if (pieces < arrSize) 
            {
                arr[pieces] = inputString.substr(startIndex, endIndex - startIndex); // if the number of pieces is less than the array size, then the array at the index of pieces is equal to the input string from the start index to the end index.
                pieces += 1; // increment the number of pieces by 1.
            }
            else
            {
                return -1; // if the number of pieces is greater than the array size, then return -1 according to github
            }
            startIndex = i + 1; // the start index is equal to the index of the for loop plus 1.
        }
    }
    if (pieces < arrSize)
    {
        arr[pieces] = inputString.substr(startIndex, inputString.length() - startIndex); // if the number of pieces is less than the array size, then the array at the index of pieces is equal to the input string from the start index to the end index.
        pieces++; // increment the number of pieces by 1 since one more was added
    }
    else
    {
        return -1; // if the number of pieces is greater than the array size, then return -1 according to github
    }
    return pieces;
}
Monster :: Monster()
{
    string line;

    ifstream fin("monsters.txt");

    if (fin.fail())
    {
        cout << "File failed to open" << endl;
    } 
    else
    {
        int i = 0;
        while (getline(fin, line))
        {
            monsters[i] = line;
            i++;
        }
        numMonsters = i;
    }

}
string Monster :: getMonster(int tier)
{
    // Loop through the monsters array, split and check if matches tier, also make sure monster name is not in monstersDefeated array
    string tempArr[2];
    for (int i = 0; i < numMonsters; i++)
    {
        split(monsters[i], ',', tempArr, 2);
        if (stoi(tempArr[1]) == tier)
        {
            if (numMonstersDefeated == 0)
            {
                return tempArr[0];
            }
            else
            {
                for (int j = 0; j < numMonstersDefeated; j++)
                {
                    if (tempArr[0] == monstersDefeated[j])
                    {
                        break;
                    }
                    else if (j == numMonstersDefeated - 1)
                    {
                        return tempArr[0];
                    }
                }
            }
            return tempArr[1];
        }
    }
}
void Monster :: addMonsterDefeated(string monsterName)
{
    monstersDefeated[numMonstersDefeated] = monsterName;
    numMonstersDefeated++;
}

int Monster :: getNumMonstersDefeated()
{
    return numMonstersDefeated;
}

string Monster :: getSorcerer()
{
    return getMonster(5); // level = 5 + 1 = 6
}

int Monster :: getMonsterHealth(int tier)
{
    return tier * 10; // tier = level
}

int Monster :: getNumMonsters()
{
    return numMonsters;
}

bool checkIfDefeated(string monsterName, string listOfMonsters[], int count=50) {
    
    for (int i = 0; i < count; i++) 
    {
        if (monsterName == listOfMonsters[i]) 
        {
            return true;
        }
    }
    
    return false;
}

void Monster :: defeatMonster(string monster)
{
    addMonsterDefeated(monster);
}

bool Monster :: monsterBattle(int roomsCleared, double prob)
{
    // Get monster for a particular level
    // level = roomsCleared + 1

    int level = roomsCleared + 1;

    string myMonsterName = "Troll";

    string tempArr[2];

    for (int i = 0; i < getNumMonsters(); i++) 
    {
        string tempMonster = monsters[i];
        split(tempMonster,',',tempArr,2);
        if (stoi(tempArr[1])==level)
         {
            if (!checkIfDefeated(tempArr[0], monstersDefeated, getNumMonsters()))
             {
                myMonsterName = tempArr[0];
            }
        }
    }

    cout << "Trying to fight the monster: " << myMonsterName << endl;

    if (prob > 0) 
    {
        cout << "Monster Defeated!" << endl;
        defeatMonster(myMonsterName);
        return true;
    } 
    else 
    {
        cout << "Unable to defeat the monster..." << endl;
        return false;
    }

}

