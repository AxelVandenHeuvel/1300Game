#include <iostream>
#include <fstream>
#include <string>
#include "puzzle.h"

using namespace std;

int p_split(string inputString, char separator, string arr[], int arrSize)
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

Puzzle :: Puzzle()
{
    string line;
    ifstream fin("riddles.txt");
    if (fin.fail())
    {
        cout << "File could not be opened" << endl;
    } 
    else
    {
        int i = 0;
        while (getline(fin, line))
        {
            // Split the line into the question and answer
            string tempArr[2];
            p_split(line, '~', tempArr, 2);
            // Store the question and answer in the array
            questions[i] = tempArr[0];
            answers[i] = tempArr[1];
            i++;
            setNumPuzzles(i);
        }
    }
}
string Puzzle :: getPuzzle(int index)
{
    return questions[index];
}
string Puzzle :: getAnswer(int index)
{
    return answers[index];
}
int Puzzle :: getNumPuzzles()
{
    return numPuzzles;
}
void Puzzle :: setNumPuzzles(int newNumPuzzles)
{
    numPuzzles = newNumPuzzles;
}
bool Puzzle :: doorPuzzle()
{
    cout << "You will now have to play a game of boulder, parchment, shears against me!!! (the door)" << endl;
    cout <<"If we tie 3 times, I kill one of your party members." << endl;
    char choice;
    int counter = 0;
    bool validInputP = false;
    bool gameWon = false;
    while (gameWon == false)
    {
        while (validInputP == false)
        {
            choice = 'a';
            cout << "Choose one:" << endl;
            cout << "B. (boulder)" << endl;
            cout << "P. (parchment)" << endl;
            cout << "S. (shears)" << endl;
            cin >> choice;
            if (choice == 'B' || choice == 'P' || choice == 'S')
            {
                validInputP = true;
            }
            else
            {
                cout << "Invalid input. Please try again." << endl;
            }
        }
        int doorChoice = rand() % 3 + 1;
        if (choice == 'B')
        {
            if (doorChoice == 1)
            {
                cout << "Door chooses boulder, its a tie!" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (doorChoice == 2)
            {
                cout << "Door chooses parchment, you lose!" << endl;
                cout << "Try again" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (doorChoice == 3)
            {
                cout << "Door chooses shears, you win!" << endl;
                gameWon = true;
                return true;
                break;
            }
        }
        else if (choice == 'P')
        {
            if (doorChoice == 1)
            {
                cout << "Door chooses boulder, you win!" << endl;
                gameWon = true;
                return true;
                break;
            }
            else if (doorChoice == 2)
            {
                cout << "Door chooses parchment, its a tie!" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (doorChoice == 3)
            {
                cout << "Door chooses shears, you lose!" << endl;
                cout << "Try again" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        else if (choice == 'S')
        {
            if (doorChoice == 1)
            {
                cout << "Door chooses boulder, you lose!" << endl;
                cout << "Try again" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (doorChoice == 2)
            {
                cout << "Door chooses parchment, you win!" << endl;
                gameWon = true;
                return true;
                break;
            }
            else if (doorChoice == 3)
            {
                cout << "Door chooses shears, its a tie!" << endl;
                counter++;
                validInputP = false;
                if (counter == 3)
                {
                    cout << "You have used up all of your tries" << endl;
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}