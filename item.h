#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class itemInventory
{
    private:
        double priceFactor = 1.0; // for the merchant prices
        // varibales for dispalying in the inventory
        int inventoryGold; 
        int ingredients;
        int cookware[3]; //pfc
        int weapons[5];
        int armor;
        int treasures[5];
        int maxArmor;
        int maxWeapons;
        int numKeys = 0;
    public:
        itemInventory();
        int getKeys();
        void setKeys(int keys);
        int getPriceFactor();
        void setPriceFactor(double factor);
        void printMerchantMenu(); // pints merchant menu
        void printInventory();
        int getGold();
        int getIngredients();
        int getCookware(int type);
        int getWeapons(int type);
        int getArmor();
        int getTreasures(int type);
        int getMaxArmor();
        int getTotalWeapons();
        int getMaxWeapons();
        int getTotalCookware();
        void setGold(int gold);
        void setIngredients(int ingredients);
        void setCookware(int type, int amount);
        void setWeapons(int type, int amount);
        void setArmor(int armor);
        void setTreasures(int type, int amount);
        void setMaxArmor(int maxArmor);
        void setMaxWeapons(int maxWeapons);
};

#endif