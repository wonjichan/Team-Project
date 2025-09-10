#pragma once
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Dragon.h"
#include "Character.h"
#include "Shop.h"
#include "BGM.h"

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