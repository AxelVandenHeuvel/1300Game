#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "item.h"

using namespace std;


itemInventory :: itemInventory()
{
    inventoryGold = 100;
    ingredients = 0;
    for (int i = 0; i < 3; i++)
    {
        cookware[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        weapons[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        treasures[i] = 0;
    }
    armor = 0;
    maxWeapons = 5; // can change in party memebrs die etc. 
    maxArmor = 5;
    numKeys = 0;
}
int itemInventory :: getKeys()
{
    return numKeys;
}
void itemInventory :: setKeys(int keys)
{
    keys = numKeys;
}
int itemInventory :: getPriceFactor()
{
    return priceFactor;
}
void itemInventory :: setPriceFactor(double factor)
{
    priceFactor = factor;
}
int itemInventory :: getGold()
{
    return inventoryGold;
}
void itemInventory :: setGold(int gold)
{
    inventoryGold = gold;
}
int itemInventory :: getIngredients()
{
    return ingredients;
}
void itemInventory :: setIngredients(int ing)
{
    ingredients = ing;
}
int itemInventory :: getCookware(int i)
{
    return cookware[i];
}
void itemInventory :: setCookware(int num, int i)
{
    cookware[i] = num;
}
int itemInventory :: getWeapons(int i)
{
    return weapons[i];
}
void itemInventory :: setWeapons(int num, int i)
{
    weapons[i] = num;
}
int itemInventory :: getTotalWeapons() // needed for comparing to max weapons
{
    int t = 0;
    for (int i = 0; i < 5; i++)
    {
        t += weapons[i];
    }
    return t;
}
int itemInventory :: getTotalCookware()
{
    int t = 0;
    for (int i = 0; i < 3; i++)
    {
        t += cookware[i];
    }
    return t;
}
int itemInventory :: getMaxWeapons()
{
    return maxWeapons;
}
void itemInventory :: setMaxWeapons(int max)
{
    maxWeapons = max;
}
int itemInventory :: getArmor()
{
    return armor;
}
void itemInventory :: setArmor(int arm)
{
    armor = arm;
}
int itemInventory :: getMaxArmor()
{
    return maxArmor;
}
void itemInventory :: setMaxArmor(int max)
{
    maxArmor = max;
}
int itemInventory :: getTreasures(int i)
{
    return treasures[i];
}
void itemInventory :: setTreasures(int num, int i)
{
    treasures[i] = num;
}
void itemInventory :: printInventory()
{
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    cout << "\033[34m" << "| INVENTORY   |" << "\033[0m" << endl;
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
    cout << "\033[34m" << "| GOLD        | " <<  getGold() << "\033[0m" << endl;
    cout << "\033[34m" << "| Ingredients | " << getIngredients() << "\033[0m" << endl;
    cout << "\033[34m" << "| Cookware    | P: " << getCookware(0) << " | F: " << getCookware(1) << " | C: " << getCookware(2) << "\033[0m" << endl;
    cout << "\033[34m" << "| Weapons     | C: " << getWeapons(0) << " | S: " << getWeapons(1) << " | R: " << getWeapons(2) << " | B: " << getWeapons(3) << " | L: " << getWeapons(4) << "\033[0m" << endl;
    cout << "\033[34m" << "| Armor       | " << getArmor() << endl;
    cout << "\033[34m" << "| Treasures   | R: " << getTreasures(0) << " | N: " << getTreasures(1) << " | B: " << getTreasures(2) << " | C: " << getTreasures(3) << " | G: " << getTreasures(4) << "\033[0m" << endl;
    cout << "\033[34m" << "+-------------+" << "\033[0m" << endl;
}
void itemInventory :: printMerchantMenu()
{
    // first define all the varibles/ items and ingredients needed for the merchants menu. 
    // all the prices are standered to the guthub and then multipled by the price factor when it changes during the game. 
    int weapons, clubPrice = 2*priceFactor, spearPrice = 2*priceFactor, rapierPrice = 5*priceFactor, axePrice = 15*priceFactor, longswordPrice = 50*priceFactor;
    int menuChoice, number, gold, price, cookwareChoice, weaponChoice, numTreasures;
    char YN;
    int potPrice = 2*priceFactor, panPrice = 10*priceFactor, cauldronPrice = 20*priceFactor, ingredients = priceFactor;
    int ringPrice = 10*priceFactor, necklacePrice = 20*priceFactor, braceletPrice = 30*priceFactor, circletPrice = 40*priceFactor, gobletPrice = 50*priceFactor;
    // now displayig the startin menu when the game starts for the merchant
    cout << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items:" << endl;
    cout << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
    bool loop = true;
    while (loop == true)
    {
        printInventory(); // show the player what they have
        cout << endl;
        cout << endl;
        cout << "Choose one of the following:" << endl;
        cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
        cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl; 
        cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> menuChoice;
        if (menuChoice != 1 && menuChoice !=2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6)
        {
            cout << "That is not a valid option, choose again." << endl;
        }
        else if (menuChoice == 1)
        {
            cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
            cout << "I reccomend buying at least 10 kg of ingredients per player." << endl;
            cin >> number;
            if (number == 0)
            {
                cout << "You have chosen to cancel this purchase." << endl;
                continue;
            }
            else if (number % 5 != 0 || number < 0)
            {
                cout << "That is not a valid number, choose again." << endl;
                continue;
            }
            else
            {
                if (getGold() < ingredients*number) // if they don't have enough gold to afford it. price for ingredients. 
                {
                    cout << "You don't have enough gold to buy that many ingredients." << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << " kg of ingredients for " << ingredients*number << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n') // checking for valid input. 
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - ingredients*number); // subtracting the gold from the player.
                        setIngredients(getIngredients() + number); // adding the ingredients to the player.
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
        }
        else if (menuChoice == 2)
        {
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << "1. (25%) Ceramic Pot [" << potPrice << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << panPrice << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << cauldronPrice << " Gold]" << endl;
            cout << "4. Cancel" << endl;
            cin >> cookwareChoice;
            if (cookwareChoice != 1 && cookwareChoice != 2 && cookwareChoice != 3 && cookwareChoice != 4)
            {
                cout << "That is not a valid option, choose again." << endl;
            }
            else if (cookwareChoice == 1)
            {
                cout << "How many Cermaic Pots would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase." << endl;
                    continue;
                }
                else if (getGold() < potPrice*number)
                {
                    cout << "You don't have enough gold to buy that many pots." << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << " Ceramic Pots for " << potPrice*number << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - potPrice*number);
                        setCookware(getCookware(0) + number, 0);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (cookwareChoice == 2)
            {
                cout << "How many Frying Pans would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase." << endl;
                    continue;
                }
                else if (getGold() < panPrice*number)
                {
                    cout << "You don't have enough gold to buy that many pans." << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << " Frying Pans for " << panPrice*number << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - panPrice*number);
                        setCookware(getCookware(1) + number, 1);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (cookwareChoice == 3)
            {
                cout << "How many Cauldrons would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase." << endl;
                    continue;
                }
                else if (getGold() < cauldronPrice*number)
                {
                    cout << "You don't have enough gold to buy that many cauldrons." << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << " Cauldrons for " << cauldronPrice*number << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - cauldronPrice*number);
                        setCookware(getCookware(2) + number, 2);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (cookwareChoice == 4)
            {
                cout << "You have chosen to cancel this purchase." << endl;
                continue;
            }
        }
        else if (menuChoice == 3)
        {
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << "1. Stone Club [" << clubPrice << " Gold]" << endl;
            cout << " 2. Iron Spear [" << spearPrice << " Gold]" << endl;
            cout << "3. (+1) Mythril Rapier [" << rapierPrice << " Gold]" << endl;
            cout << "4. (+2) Flaming Battle-Axe [" << axePrice << " Gold]" << endl;
            cout << " 5. (+3) Vorpal Longsword [" << longswordPrice << " Gold]" << endl;
            cout << " 6. Cancel" << endl;
            cin >> weaponChoice;
            if (weaponChoice != 1 && weaponChoice != 2 && weaponChoice !=3 && weaponChoice !=4 && weaponChoice !=5 && weaponChoice != 6)
            {
                cout << "That is not a valid option, choose again." << endl;
            }
            else if (weaponChoice == 1)
            {
                cout << "How many stone clubs would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase" << endl;
                    continue;
                }
                else if ((getTotalWeapons() + number) > getMaxWeapons())
                {
                    cout << "You have no more room for those weapons!" << endl;
                    continue;
                }
                else if (getGold() < clubPrice * number)
                {
                    cout << "You don't have enough gold to buy that many clubs" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << "Stone club(s) for" << clubPrice*number << " Gold (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - clubPrice * number);
                        setWeapons((getWeapons(0) + number), 0);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (weaponChoice == 2)
            {
                cout << "How many Iron spears would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase" << endl;
                    continue;
                }
                else if ((getTotalWeapons() + number) > getMaxWeapons())
                {
                    cout << "You have no more room for those weapons!" << endl;
                    continue;
                }
                else if (getGold() < spearPrice * number)
                {
                    cout << "You don't have enough gold to buy that many spears" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << "Iron Spear(s) for" << spearPrice*number << " Gold (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - spearPrice * number);
                        setWeapons((getWeapons(1) + number), 1);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (weaponChoice == 3)
            {
                cout << "How many Mythrial Rapiers would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase" << endl;
                    continue;
                }
                else if ((getTotalWeapons() + number) > getMaxWeapons())
                {
                    cout << "You have no more room for those weapons!" << endl;
                    continue;
                }
                else if (getGold() < rapierPrice * number)
                {
                    cout << "You don't have enough gold to buy that many rapiers" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << "Mythiral Rapier(s) for" << rapierPrice*number << " Gold (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - rapierPrice * number);
                        setWeapons((getWeapons(2) + number), 2);
                        cout << "Congratulations! You will get (+1) special bonus in combat with this!" << endl;
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (weaponChoice == 4)
            {
                cout << "How many Flaming Battle-Axes would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase" << endl;
                    continue;
                }
                else if ((getTotalWeapons() + number) > getMaxWeapons())
                {
                    cout << "You have no more room for those weapons!" << endl;
                    continue;
                }
                else if (getGold() < axePrice * number)
                {
                    cout << "You don't have enough gold to buy that many battle-axes" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << "Battle-Axe(s) for" << axePrice*number << " Gold (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - axePrice * number);
                        setWeapons((getWeapons(3) + number), 3);
                        cout << "Congratulations! You will get (+2) special bonus in combat with this!" << endl;
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (weaponChoice == 5)
            {
                cout << "How many Vorpal Longswords would you like to buy? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> number;
                if (number <= 0)
                {
                    cout << "You have chosen to cancel this purchase" << endl;
                    continue;
                }
                else if ((getTotalWeapons() + number) > getMaxWeapons())
                {
                    cout << "You have no more room for those weapons!" << endl;
                    continue;
                }
                else if (getGold() < longswordPrice * number)
                {
                    cout << "You don't have enough gold to buy that many longswords" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to buy " << number << "Longsword(s) for" << longswordPrice*number << " Gold (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() - longswordPrice * number);
                        setWeapons((getWeapons(4) + number), 4);
                        cout << "Congratulations! You will get (+3) special bonus in combat with this!" << endl;
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                }
            }
            else if (weaponChoice == 6)
            {
                cout << "Option to buy weapons is now closed." << endl;
                continue;
            }
        }
        else if (menuChoice == 4)
        {
            cout << " How many suits of armor can I get you? It will cost you 5 gold each (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> number;
            if (number <= 0)
            {
                cout << "You have chosen to cancel this purchase" << endl;
                continue;
            }
            else if ((getArmor() + number) > getMaxArmor())
            {
                cout << "You have no more room for that armor!" << endl;
                continue;
            }
            else if (getGold() < 5 * number)
            {
                cout << "You don't have enough gold to buy that much armor" << endl;
                continue;
            }
            else
            {
                cout << "You want to buy " << number << " suit(s) of armor for" << 5*number << " Gold (y/n)" << endl;
                cin >> YN;
                if (YN != 'y' && YN != 'n')
                {
                    cout << "That is not a valid input, choose again." << endl;
                    continue;
                }
                else if (YN == 'n')
                {
                    cout << "You have chosen to cancel this purchase." << endl;
                    continue;
                }
                else
                {
                    setGold(getGold() - armor * number);
                    setArmor((getArmor() + number));
                    cout << "You will be more prepared for combat with this!" << endl;
                    cout << "I can't promise it won't break however..." << endl;
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                }
            }
        }
        else if (menuChoice == 5)
        {
            cout << "What do you have to sell?" << endl;
            cout << "1. Silver Ring" << endl;
            cout << "2. Ruby Necklace" << endl;
            cout << "3. Emerlad Bracelet" << endl;
            cout << "4. Dimaond Circlet" << endl;
            cout << "5. Gem-Encrusted Goblet" << endl;
            cout << "6. Nothing" << endl;
            cin >> number;
            if (number != 1 && number != 2 && number != 3 && number != 4 && number != 5 && number != 6)
            {
                cout << "That is not a valid input, choose again." << endl;
                continue;
            }
            else if (number == 1)
            {
                cout << "I will buy your Silver Ring for 10 gold each. How many do you want to sell?" << endl;
                cin >> numTreasures;
                if (numTreasures > getTreasures(0))
                {
                    cout << "You don't have that many rings to sell!" << endl;
                    continue;
                }
                else if (numTreasures <= 0)
                {
                    cout << "You have chosen to cancel this sale" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to sell " << numTreasures << " Silver Ring(s) for" << numTreasures * 10 << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() + numTreasures * 10);
                        setTreasures((getTreasures(0) - numTreasures), 0);
                        cout << "Thanks! This will add nicely to my collection. What else can I do for you?" << endl;
                    }
                }
            }
            else if (number == 2)
            {
                cout << "I will buy your Ruby Necklace for 20 gold each. How many do you want to sell?" << endl;
                cin >> numTreasures;
                if (numTreasures > getTreasures(1))
                {
                    cout << "You don't have that many necklaces to sell!" << endl;
                    continue;
                }
                else if (numTreasures <= 0)
                {
                    cout << "You have chosen to cancel this sale" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to sell " << numTreasures << " Ruby Necklace(s) for" << numTreasures * 20 << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() + numTreasures * 20);
                        setTreasures((getTreasures(1) - numTreasures), 1);
                        cout << "Thanks! This will add nicely to my collection. What else can I do for you?" << endl;
                    }
                }
            }
            else if (number == 3)
            {
                cout << "I will buy your Emerald Bracelet for 30 gold each. How many do you want to sell?" << endl;
                cin >> numTreasures;
                if (numTreasures > getTreasures(2))
                {
                    cout << "You don't have that many bracelets to sell!" << endl;
                    continue;
                }
                else if (numTreasures <= 0)
                {
                    cout << "You have chosen to cancel this sale" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to sell " << numTreasures << " Emerald Bracelet(s) for" << numTreasures * 30 << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() + numTreasures * 30);
                        setTreasures((getTreasures(2) - numTreasures), 2);
                        cout << "Thanks! This will add nicely to my collection. What else can I do for you?" << endl;
                    }
                }
            }
            else if (number == 4)
            {
                cout << "I will buy your Diamond Circlet for 40 gold each. How many do you want to sell?" << endl;
                cin >> numTreasures;
                if (numTreasures > getTreasures(3))
                {
                    cout << "You don't have that many circlets to sell!" << endl;
                    continue;
                }
                else if (numTreasures <= 0)
                {
                    cout << "You have chosen to cancel this sale" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to sell " << numTreasures << " Diamond Circlet(s) for" << numTreasures * 40 << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() + numTreasures * 40);
                        setTreasures((getTreasures(3) - numTreasures), 3);
                        cout << "Thanks! This will add nicely to my collection. What else can I do for you?" << endl;
                    }
                }
            }
            else if (number == 5)
            {
                
                cout << "I will buy your Gem-Encrusted Goblet for 50 gold each. How many do you want to sell?" << endl;
                cin >> numTreasures;
                if (numTreasures > getTreasures(4))
                {
                    cout << "You don't have that many goblets to sell!" << endl;
                    continue;
                }
                else if (numTreasures <= 0)
                {
                    cout << "You have chosen to cancel this sale" << endl;
                    continue;
                }
                else
                {
                    cout << "You want to sell " << numTreasures << " Gem-Encrsuted Goblet(s) for" << numTreasures * 50 << " Gold? (y/n)" << endl;
                    cin >> YN;
                    if (YN != 'y' && YN != 'n')
                    {
                        cout << "That is not a valid input, choose again." << endl;
                        continue;
                    }
                    else if (YN == 'n')
                    {
                        cout << "You have chosen to cancel this purchase." << endl;
                        continue;
                    }
                    else
                    {
                        setGold(getGold() + numTreasures * 50);
                        setTreasures((getTreasures(4) - numTreasures), 4);
                        cout << "Thanks! This will add nicely to my collection. What else can I do for you?" << endl;
                    }
                }
            }
            else if (number == 6)
            {
                cout << "I don't want your nothing either!" << endl;
                continue;
            }
        }
        else
        {
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
            cin >> YN;
            if (YN != 'y' && YN != 'n')
            {
                cout << "That is not a valid input, choose again." << endl;
                continue;
            }
            else if (YN == 'n')
            {
                cout << "What else can I do for you?" << endl;
                continue;
            }
            else
            {
                cout << "Stay safe out there! Goodbye!" << endl;
                loop = false;
            }
        }
    }
}