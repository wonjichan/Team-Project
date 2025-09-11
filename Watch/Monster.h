#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <vector>
class Inventory;
class Character; 
class HealthPotion; 
class AttackBoost;

using namespace std; 
class Monster
{
protected:
	string name; 
	int health; 
	int attack; 
	bool isBattle;
public:
	Monster(string _name);
	int getAttack(); 
	virtual string getName(); 
	virtual int getHealth();
	virtual void takeDamage(Character* character);
	virtual void TryDropItem(Character* player);
	void settBattle(bool isplay);
	bool IsBattle();
	virtual void printAsciiArt() const = 0;
};