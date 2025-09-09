#pragma once
#include <iostream>
#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include <vector>
class GameManager
{
private:
	Monster* monster;
	vector<Item*> inventory;
	int capacity;
	int size;
public:
	GameManager(int _capacity = 10)
	{
		monster = nullptr;
		capacity = _capacity;
	}
	//몬스터 랜덤 스폰 
	Monster* generateMonster(int level)
	{
		srand((unsigned int)time(NULL));
		int randNum = rand() % 4 + 1;
		switch (randNum)
		{
		case 1:
			monster = new Slime("슬라임");
			break;
		case 2:
			monster = new Goblin("고블린");
			break;
		case 3:
			monster = new Orc("오크");
			break;
		case 4:
			monster = new Troll("트롤");
		default:
			break;
		}
		return monster;
	}
	//인벤토리 출력 
	//vector<Item*> inventory 
	void disPlayInventory(Item* item)
	{


	}
	void Battle(Character* player)
	{
	

	}
};