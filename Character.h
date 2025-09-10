#pragma once
#include <iostream>
#include <vector>
#include "Inventory.h"

using namespace std;

class Monster;

class Character
{
private:
    static Character* instance;

    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int gold;
    int experience;
    bool isBattle;

    Inventory inv;

    Character(string name);
    Character(const Character&);
    Character& operator=(const Character&) {}

public:
    static Character* getInstance(string name);

    Inventory* getInventory();

    void levelUp();
    void useItem(int index);

    // Getter
    int GetLevel();
    int getEXP();
    int getGold();
    int getAttack();
    int getHealth();
    int getMaxHealth();
    string getName();

    // Setter
    void setExp(int exp);
    void setGold(int gold);
    void desetGold(int gold);
    void setBattle(bool isplay);
    void setHealth(int heal);
    void setAttack(int att);

    void displayStatus();
    void takeDamage(Monster* monster);
    bool IsBattle();
};
