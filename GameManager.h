#pragma once
#include <iostream>
#include <vector>
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Dragon.h"
class Item;

class GameManager
{
private:
	Monster* monster;
public:
	GameManager();
	Monster* generateMonster(Character* player);
	void disPlayInventory(vector<Item*>& item);
	void Battle(Character* player);
};