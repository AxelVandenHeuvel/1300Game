#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "gameActions.h"

using namespace std;

int main()
{
    Game main = Game();
    main.randomizeMap();
    main.printMerchantMenu(); // shows intitial merchant menu.
    while (main.gameEnd() == false)
    {
        main.printStatus(); // first show the player status.
        // now show the actions menu for regular spaces
        if (main.isFreeSpace(main.getPlayerRow(), main.getPlayerCol()))
        {
            //main.actionMenu();
            if (main.actionMenu() == false)
            {
                cout << "You have decided to quit the game. Thanks for playing!" << endl;
                break;
            }
            else
            {
                continue;
            }
        }
        // now checking for NPC spaces to print the NPC menu
        else if (main.isNPCLocation(main.getPlayerRow(), main.getPlayerCol()))
        {
            if (main.npcMenu() == false)
            {
                cout << "You have decided to quit the game. Thanks for playing!" << endl;
                break;
            }
            else
            {
                continue;
            }
        }
        // now checking for spaces if on a room
        else if (main.isRoomLocation(main.getPlayerRow(), main.getPlayerCol()))
        {
            if (main.roomSpaceMenu() == false)
            {
                cout << "You have decided to quit the game. Thanks for playing!" << endl;
                break;
            }
            else
            {
                continue;
            }
        }
        else if (main.isDungeonExit(main.getPlayerRow(), main.getPlayerCol()))
        {
            int code = main.finalExit();
            if (code == 1)
            {
                continue;
            }
            else if (code == 2)
            {
                cout << "Congratulations!" << endl;
                break;
            }
            else if (code == 3)
            {
                cout << "Unlucky..." << endl;
                break;
            }
            else if (code == 4)
            {
                cout << "You have decided to quit the game. Thanks for playing!" << endl;
                break;
            }
        }
    }
    cout << "This is the end" << endl;
    cout << "outputting final stats in results.txt..." << endl;
    main.outputStats();
    return 0;
}