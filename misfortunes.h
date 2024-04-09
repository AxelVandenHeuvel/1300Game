#ifndef MISFORTUNE_H
#define MISFORTUNE_H

#include <iostream>
#include <cstdlib>
#include "player.h"
#include "item.h"
#include "party.h"
#include "map.h"

using namespace std;

class misfortune: public itemInventory, public Party
{
    private:
        // nothing needs to be set or got because its the same misforutnes everytime.

    public:
        misfortune();
        void robbed();
        void breaks();
        void foodPoisoning();
        void treasurefind();
};

#endif