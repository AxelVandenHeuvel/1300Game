#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "item.h"
#include "gameActions.h"
//#include "finalBattle.h"

using namespace std;

int randomNum(int start, int end) {
    srand(time(NULL)); // Generates a seed for the random generator with the current time

    int random_num = start + rand() % (end - start + 1);

    return random_num;
}

Game :: Game()
{
    sorcererAnger = 0; // starts at zero
    numRoomsPassed = 0;

}
// getters
int Game :: getRoomsCleared()
{
    return numRoomsPassed;
}
int Game :: getSorcererAnger()
{
    return sorcererAnger;
}
// setters for those functions
void Game :: setRoomsPassed(int rooms)
{
    numRoomsPassed = rooms;
}
void Game :: setSorcererAnger(int anger)
{
    sorcererAnger = anger;
}
void Game :: misfortune100()
{
    int mis = rand() % 100 + 1;
    if (mis >= 1 && mis < 30)
    {
        robbed();
    }
    else if (mis >= 30 && mis < 40)
    {
        breaks();
    }
        else if (mis >= 40 && mis < 70)
    {
        foodPoisoning();
    }
    else
    {
        treasurefind();
    }
}

void Game :: movement()
{
    bool validInputM = false;
    char wasdN;
    while (!validInputM)
        {
            cout << "What direction do you want to move? (wasd)" << endl;
            cin >> wasdN;

            /*
                Switch statement for movement
            */

           switch (wasdN) {
            case 'w':
                cout << "You moved up" << endl;
                validInputM = true;
                break;
            case 'a':
                cout << "You moved left" << endl;
                validInputM = true;
                break;
            case 's':
                cout << "You moved down" << endl;
                validInputM = true;
                break;
            case 'd': 
                cout << "You moved right" << endl;
                validInputM = true;
                break;
            default:
                validInputM = false;
                cout << "Uh oh, not a valid direction. Try again.\n";
                break;
           } 



            // if (wasdN == 'w' || wasdN == 'a' || wasdN == 's' || wasdN == 'd')
            // {
            //     validInputM = true;
            // }
            // else
            // {
            //     cout << "Not a movement option. Select Again" << endl;
            //     cout << " you selected " << wasdN << endl;
            // }
        }
        move(wasdN);
        // chance every movement that each players members fullness level has a 20% chance to decrease. 
        for (int i = 0; i < getNumPlayers(); i++)
        {
            if (chance(0, 20))
            {
                reducePlayerFullness(i, 1);
            }
        }
        setSorcererAnger(getSorcererAnger() + 1);
}
void Game :: printStatus()
{
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    cout << "\033[34m" << "| STATUS      |" << "\033[0m" << endl;
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    cout << "\033[34m" << "| Rooms Cleared: " << numRoomsPassed << " | Keys: " << numKeys << "| Anger Level: " << sorcererAnger << " |" << "\033[0m" << endl;
    printInventory();
    printParty();
    displayMap();
}
bool Game :: chance(int start, int end)
{
    srand(time(NULL));
    int random = rand() % 100 + 0;
    if (random >= start && random <= end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Game :: activateFightMonster()
{
    cout << "A monster has surprised you!" << endl;
    // Calculate weapons equation
    double equation = 0;
    equation += getTotalWeapons();
    equation = equation * randomNum(1,6);

    // Check if every member has a different type of weapon
    double diffType = 0;
    for (int i = 0; i < 5; i++) 
    {
        diffType += getWeapons(i);
    }
    if (diffType >= 4) 
    {
        diffType = 4;
    } 
    else 
    {
        diffType = 0;
    }

    equation += diffType;

    double equationRHS = getArmor();
    equationRHS = equationRHS * randomNum(1,6);
    equationRHS = equationRHS / (getRoomsCleared() + 1);

    equation = equation - equationRHS;

    return monsterBattle(getRoomsCleared(), equation);
}


bool Game :: actionMenu()
{
    srand(time(NULL));
    int option;
    //char wasd;
    bool validInput = false;
    while (!validInput)
    {
        cout << "Select one: " << endl;
        cout << "1. Move" << endl;
        cout << "2. Investigate" << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat" << endl;
        cout << "5. Give up" << endl;
        cin >> option;
        if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
        {
            validInput = true;
        }
        else
        {
            cout << "Not an option. Select Again" << endl;
            cout << "you selected " << option << endl;
        }
    }
    if (option == 1)
    {
        movement();
    }
    else if (option == 2)
    {
        if (isExplored(getPlayerRow(), getPlayerCol()))
        {
            cout << "This space has already been investigated" << endl;
        }
        else
        {
            exploreSpace(getPlayerRow(), getPlayerCol());
            if (chance(0, 10))
            {
                cout << "You have found a key!" << endl;
                setKeys(getKeys() + 1);
            }
            else
            {
                cout << "you hear a cry in the distance..." << endl;
            }
            if (chance(0 , 20))
            {
                int getRoomsClearedCode = getRoomsCleared();
                if (getRoomsClearedCode == 1)
                {
                    cout << "You have found a silver ring! might have some value." << endl;
                    setTreasures(0, getTreasures(0) + 1);
                }
                else if (getRoomsClearedCode == 2)
                {
                    cout << "You have found a Ruby Necklace! Shiny!" << endl;
                    setTreasures(1, getTreasures(1) + 1);
                }
                else if (getRoomsClearedCode == 3)
                {
                    cout << "You have found an emerald bracelet! Sparkly!" << endl;
                    setTreasures(2, getTreasures(2) + 1);
                }
                else if (getRoomsClearedCode == 4)
                {
                    cout << "you have found a diamond circlet! I'm sure that is worth a bit." << endl;
                    setTreasures(3, getTreasures(3) + 1);
                }
                else if (getRoomsClearedCode == 5)
                {
                    cout << "you have found a gen-encrusted goblet! Maybe try taking a sip from it?" << endl;
                    setTreasures(4, getTreasures(4) + 1);
                }
                else
                {
                    cout << "You have found a leather patch! Its probably worth nothing" << endl;
                }
            }
            else
            {
                cout << "The dungeon is cold..." << endl;
            }
            if (chance(0, 20)) // 20% chance of finding a monster
            {
                // Check match results
                if (activateFightMonster())
                {
                    cout << "You have defeated the monster!" << endl;
                    setGold(getGold() + 10);
                    setIngredients(getIngredients() + 5);
                    if (chance(0, 10))
                    {
                        cout << "The monster has dropped a key!" << endl;
                        setKeys(getKeys() + 1);
                    }
                    if (chance(0, 40))
                    {
                        misfortune100();
                    }
                }
                else 
                {
                    cout << "The monster has defeated you!" << endl;
                    setGold(getGold() - getGold()/4); // lose a quarter of the gold reserves
                    setIngredients(getIngredients() - randomNum(1, 30)); // lose between 1 and 30 ingredients
                    for (int i = 1; i < 5; i ++)
                    {
                        if (chance(0, 10)) // 10 percent chance for each party member to die. 
                        {
                            killPlayer(i);
                            cout << getPartyPlayerName(i) << " has died!" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "its too quiet..." << endl;
            }
            if (chance(0, 40)) // 40% chance of a misfortune happening
            {
                misfortune100();
            }
            else
            {
                cout << "..." << endl;
            }
        }
    }
    else if (option == 3) // pick a fight
    {
                // Check match results
        if (activateFightMonster()) 
        {
            cout << "You have defeated the monster!" << endl;
            setGold(getGold() + 10);
            setIngredients(getIngredients() + 5);
            if (chance(0, 10))
            {
                cout << "The monster has dropped a key!" << endl;
                setKeys(getKeys() + 1);
            }
            if (chance(0, 40))
            {
                misfortune100();
            }
        } 
        else 
        {
            cout << "The monster has defeated you!" << endl;
            setGold(getGold() - getGold()/4); // lose a quarter of the gold reserves
            setIngredients(getIngredients() - randomNum(1, 30)); // lose between 1 and 30 ingredients
            for (int i = 1; i < 5; i ++)
            {
                if (chance(0, 10)) // 10 percent chance for each party member to die. 
                {
                    killPlayer(i);
                    cout << getPartyPlayerName(i) << " has died!" << endl;
                }
            }
        }
    }
    else if (option == 4) // cook and eat
    {
        int ingredients;
        int cookwareOption;
        if (getIngredients() == 0)
        {
            cout << "You don't have any ingredients to cook with!" << endl;
        }
        else if (getTotalCookware() == 0)
        {
            cout << "You don't have any cookware to cook with!" << endl;
        }
        else
        {
            bool validInput2 = false;
            while (validInput2 == false)
            {
                cout << "What do you want to cook with?" << endl;
                cout << "1. Ceramic Pot" << endl;
                cout << "2. Frying Pan" << endl;
                cout << "3. Cauldron" << endl;
                cout << "4. Nevermind" << endl;
                cin >> cookwareOption;
                if (cookwareOption == 1 || cookwareOption == 2 || cookwareOption == 3)
                {
                    if (getCookware(cookwareOption - 1) == 0)
                    {
                        cout << "You don't have that cookware!" << endl;
                        continue;
                    }
                    else
                    {
                        validInput2 = true;
                        break;
                    }
                }
                else
                {
                    cout << "Not an option. Select Again" << endl;
                }
            }
            if (cookwareOption == 1)
            {
                cout << "How many ingredients do you want to cook with?" << endl;
                cin >> ingredients;
                if (ingredients % 5 != 0)
                {
                    cout << "You can only use ingredients in multiples of 5" << endl;
                }
                else if (ingredients > getIngredients())
                {
                    cout << "You don't have that many ingredients to cook with!" << endl;
                }
                else
                {
                    if (chance (0, 25)) // 25% chance the pot breaks
                    {
                        cout << "Your pot has broken. Unlucky" << endl;
                    }
                    else
                    {
                        cout << "You have succesfully cooked a meal" << endl;
                        cout << "Everyone eats!" << endl;
                        setIngredients(getIngredients() - ingredients);
                        eatFood(ingredients);
                    }
                }
            }
            else if (cookwareOption == 2)
            {
                cout << "How many ingredients do you want to cook with?" << endl;
                cin >> ingredients;
                if (ingredients % 5 != 0)
                {
                    cout << "You can only use ingredients in multiples of 5" << endl;
                }
                else if (ingredients > getIngredients())
                {
                    cout << "You don't have that many ingredients to cook with!" << endl;
                }
                else
                {
                    if (chance (0, 10)) // 10% chance the pan breaks
                    {
                        cout << "Your frying pan has broken. Unlucky" << endl;
                    }
                    else
                    {
                        cout << "You have succesfully cooked a meal" << endl;
                        cout << "Everyone eats!" << endl;
                        setIngredients(getIngredients() - ingredients);
                        eatFood(ingredients);
                    }
                }
            }
            else if (cookwareOption == 3)
            {
                cout << "How many ingredients do you want to cook with?" << endl;
                cin >> ingredients;
                if (ingredients % 5 != 0)
                {
                    cout << "You can only use ingredients in multiples of 5" << endl;
                }
                else if (ingredients > getIngredients())
                {
                    cout << "You don't have that many ingredients to cook with!" << endl;
                }
                else
                {
                    if (chance (0, 2)) // 2% chance the cauldron breaks
                    {
                        cout << "Your cauldron has broken. Unlucky" << endl;
                    }
                    else
                    {
                        cout << "You have succesfully cooked a meal" << endl;
                        cout << "Everyone eats!" << endl;
                        setIngredients(getIngredients() - ingredients);
                        eatFood(ingredients);
                    }
                }
            }
            else
            {
                cout << "Exit cook menu" << endl;
            }
            if (chance (0, 40)) // 40% chance of a misfortune happening
            {
                misfortune100();
            }
            else
            {
                cout << "..." << endl;
            }
        }
    }
    else if (option == 5)
    {
        return false; // returns false if no action was made. 
    }
    else
    {
        cout << "Not an option. Select again" << endl;
    }
    return true; // returns true if an action was made
}

bool Game :: npcMenu()
{
    bool validInput = false;
    int option;
    srand(time(NULL));
    while (validInput == false)
    {
        cout << "You have stepped on an a traveling merchant's space.. will you solve his riddle?" << endl;
        cout << "1. Move off the Merchant space" << endl;
        cout << "2. Speak to the traveling merchnat" << endl;
        cout << "3. Give up" << endl; // function will return false if chosen to give up. 
        cin >> option;
        if (option != 1 || option != 2 || option != 3)
        {
            validInput = true;
            break;
        }
        else
        {
            cout << "Not an option. Select again" << endl;
        }
    }
    if (option == 1)
    {
        movement();
    }
    else if (option == 2)
    {
        string answer;
        int puzzleNum = randomNum(1, 20);
        cout << "Here is my riddle..." << endl;
        getPuzzle(puzzleNum);
        cin >> answer;
        if (answer == getAnswer(puzzleNum))
        {
            cout << "You have solved my riddle! Here is a reward, and you may now buy from me!" << endl;
            setGold(getGold() + 15);
            if (getRoomsCleared() == 0)
            {
                setPriceFactor(1);
            }
            else
            {
                setPriceFactor(getRoomsCleared() * 0.25);
            }
            printMerchantMenu();
        }
        else
        {
            cout << "That is NOT the answer!" << endl;
        }
        removeNPC(getPlayerRow(), getPlayerCol());
        if (chance(0, 40))
        {
            misfortune100();
        }
    }
    else if (option == 3)
    {
        return false;
    }
    return true;
}

void Game :: outputStats() // output final stats at end of the game. 
{
    ofstream fout;
    fout.open("results.txt");
    fout << "Leader Name: " << getPartyPlayerName(0) << endl;
    fout << "Remaining Party Members: " << endl;
    for (int i = 1; i < 4; i++)
    {
        fout << getPartyPlayerName(i) << endl;
    }
    fout << "Gold: " << getGold() << endl;
    fout << "Ingredients: " << getIngredients() << endl;
    fout << "# of Rooms Cleared: " << getRoomsCleared() << endl;
    fout << "Treasures collected: " << endl;
    for (int i = 0; i < 5; i++)
    {
        fout << getTreasures(i) << endl;
    }
    //close fil
    fout.close();
}

bool Game :: roomSpaceMenu()
{
    bool validInput = false;
    int option;
    while (validInput == false)
    {
        cout << "You have stepped on a room space. What would you like to do?" << endl;
        cout << "1. Move off the room space" << endl;
        cout << "2. Open the door" << endl;
        cout << "3. Give up" << endl;
        cin >> option;
        if (option != 1 || option != 2 || option != 3)
        {
            validInput = true;
            break;
        }
        else
        {
            cout << "Not an option. Select again" << endl;
        }
    }
    if (option == 1)
    {
        movement();
    }
    else if (option == 2)
    {
        if (getKeys() == 0)
        {
            cout << "You don't have a key to open the door" << endl;
            cout << "You have fallen into a trap" << endl;
            if (doorPuzzle())
            {
                cout << "You have beat the trap and entered the room!" << endl;
                if (activateFightMonster())
                {
                    if (chance(0, 60))
                    {
                        misfortune100();
                    }
                    setRoomsPassed(getRoomsCleared() + 1);
                    removeRoom(getPlayerRow(), getPlayerCol());
                }
                else
                {
                    cout << "The monster in the room has defeated you" << endl;
                    setGold(getGold() - getGold()/4);
                    setIngredients(getIngredients() - randomNum(1, 30));
                    for (int i = 1; i < 5; i++)
                    {
                        if (chance(0, 10))
                        {
                            killPlayer(i);
                            cout << getPartyPlayerName(i) << " has died" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "You have failed the door puzzle" << endl;
                cout << "The door steals your gold and ingredients" << endl;
                setGold(getGold() - 5);
                setIngredients(getIngredients() - 5);
            }
        }
        else
        {
            cout << "You used a key to open the door" << endl;
            setKeys(getKeys() - 1);
            cout << "A monster appears" << endl;
            if(activateFightMonster())
            {
                if (chance(0, 60)) // 60% chance of a misfortune happening. 
                {
                    misfortune100();
                }
                setRoomsPassed(getRoomsCleared() + 1);
                removeRoom(getPlayerRow(), getPlayerCol()); // gets rid of the room on the map and adds to the amount of rooms passed. 
            }
            else
            {
                cout << "the monster in the room has defeated you" << endl;
                setGold(getGold() - getGold()/4); // lose a quarter of the gold reserves
                setIngredients(getIngredients() - randomNum(1, getIngredients())); // lose between 1 and 30 ingredients
                for (int i = 1; i < 5; i ++)
                {
                    if (chance(0, 10)) // 10 percent chance for each party member to die. 
                    {
                        killPlayer(i);
                        cout << getPartyPlayerName(i) << " has died!" << endl;
                    }
                }   
            }
        }
    }
    else if (option == 3)
    {
        return false;
    }
    return true;
}

bool Game :: gameEnd() // checks after every actions whether or not the game has ended. 
{
    if (getSorcererAnger() >= 100)
    {
        cout << "The sorcerer has become too angry and has killed you" << endl;
        return true;
    }
    if (getNumPlayers() <= 2)
    {
        cout << "You have lost too many party members" << endl;
        return true;
    }
    if (getPlayerFullness(0) <= 0)
    {
        cout << "Your leader has starved to death" << endl;
        return true;
    }
    return false;
}

int Game :: finalExit()
{
    bool validInput = false;
    int option;
    while (validInput == false)
    {
        cout << "You have come by what appears to be the exit..." << endl;
        cout << "What would you like to do?" << endl;
        cout <<" 1. Move off the exit space" << endl;
        cout << "2. Attempt to exit the dungeon" << endl;
        cout << "3. Give up" << endl;
        cin >> option;
        if (option != 1 || option != 2 || option != 3)
        {
            validInput = true;
            break;
        }
        else
        {
            cout << "Not an option. Select again" << endl;
        }
    }
    if (option == 1)
    {
        movement();
        return 1;
    }
    else if (option == 2)
    {
        if (getRoomsCleared() < 5)
        {
            cout << "You have not cleared enough rooms to exit the dungeon" << endl;
            return 1;
        }
        else
        {
            cout << "You attempt to leave the dungeon but the sorcerer appears in front of you..." << endl;
            cout << "He says that you must defeat him in a game of tic tac toe to leave the dungeon..." << endl;
            bool outcome;
            outcome = totalGame();
            if (outcome == true)
            {
                cout << "You've beaten the sorcerer!" << endl;
                return 2;
            }
            else if (outcome == false)
            {
                cout << "THe sorcerer has defeated you" << endl;
                return 3;
            }
            else
            {
                return 3;
            }
        }
    }
    else if (option == 3)
    {
        return 4;
    }
    else
    {
        return 4;
    }
}

void Game :: displayBoard(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (board[i][j] == ' ') 
            {
                cout << "[ ] ";
            }
            else 
            {
                cout << "[" << board[i][j] << "] ";
            }
        }
        cout << endl;
    }
}

bool Game :: checkWin(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) //checks all the rows
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }
    for (int j = 0; j < COLS; j++) // checks all the cols
    {
        if (board[0][j] == board[1][j] && board [1][j] == board[2][j] && board[0][j] != ' ')
        {
            return true;
        }
    }
    // now need to check diagonal wins.
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }
    if (board[0][2] == board [1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; i++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void Game :: sorcererMove(char board[ROWS][COLS])
{
    srand(time(NULL));
    int row, col;
    do 
    {
        row = rand() % ROWS;
        col = rand() % COLS;
    } 
    while (board[row][col] != ' ');
    board[row][col] = 'X';
}

void Game :: userMove(char board[ROWS][COLS])
{
    int num;
    cout << "Enter a number between 1 and 9 to place your move: ";
    cin >> num;
    int row = (num - 1) / ROWS;
    int col = (num - 1) % COLS;
    if (board[row][col] == ' ') 
    {
        board[row][col] = 'O';
    } 
    else 
    {
        cout << "That space is already occupied. Please try again." << endl;
        userMove(board);
    }
}

bool Game :: totalGame()
{
    char board[ROWS][COLS] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    displayBoard(board);
    while (!checkWin(board))
    {
        sorcererMove(board);
        cout << endl;
        displayBoard(board);
        cout << endl;
        if (checkWin(board))
        {
            return false;
            break;
        }
        userMove(board);
        cout << endl;
        displayBoard(board);
        cout << endl;
    }
    if (board[1][1] == 'X')
    {
        return false;
    }
    else if (board[1][1] == 'O')
    {
        return true;
    }
    else // false if the game is a tie
    {
        return false; 
    }

}