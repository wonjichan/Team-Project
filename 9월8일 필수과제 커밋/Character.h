#pragma once
#include <iostream>
#include "Inventory.h"
#include <vector>

using namespace std; 

class Monster; 

class Character
{
private:
	static Character* instance;
	string name;
	int level, health, maxHealth, attack, gold, experience;
	bool isBattle;
	Inventory inv;
	Character(string name);
	Character(const Character&);
	Character& operator=(const Character&){}

public:
	Inventory* getInventory();
	static Character* getInstance(string name);
	void levelUp();
	void useItem(int index);
	int GetLevel();
	//getter() 
	int getEXP();
	int getGold(); 
	int getAttack();
	int getHealth();
	int getMaxHealth();
	string getName();
	//setter() 
	void setExp(int exp);
	void setGold(int gold);
	void setBattle(bool isplay);
	void setHealth(int _heal);
	void setAttack(int att);

	void displayStatus();
	void takeDamage(Monster* monster);
	bool IsBattle();
};
