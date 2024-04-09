#include <iostream>
#include <cstdlib>
#include <ctime>
#include "finalBattle.h"

using namespace std;

void final :: displayBoard(char board[ROWS][COLS])
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

bool final :: checkWin(char board[ROWS][COLS])
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

void final :: sorcererMove(char board[ROWS][COLS])
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

void final :: userMove(char board[ROWS][COLS])
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

// bool final :: totalGame()
// {
//     char board[ROWS][COLS] =
//     {
//         {' ', ' ', ' '},
//         {' ', ' ', ' '},
//         {' ', ' ', ' '}
//     };
//     displayBoard(board);
//     while (!checkWin(board))
//     {
//         sorcererMove(board);
//         cout << endl;
//         displayBoard(board);
//         cout << endl;
//         if (checkWin(board))
//         {
//             return false;
//             break;
//         }
//         userMove(board);
//         cout << endl;
//         displayBoard(board);
//         cout << endl;
//     }
//     if (board[1][1] == 'X')
//     {
//         return false;
//     }
//     else if (board[1][1] == 'O')
//     {
//         return true;
//     }
//     else // false if the game is a tie
//     {
//         return false; 
//     }

// }