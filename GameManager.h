#pragma once
#include <iostream>
#include <vector>
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
class Item;

class GameManager
{
private:
	Monster* monster;
public:
	GameManager();
	//몬스터 랜덤 스폰 
	Monster* generateMonster();
	//인벤토리 출력 
	//vector<Item*> inventory / 요소 = new HealthPotion , new AttackPotion ... 
	void disPlayInventory(vector<Item*>& item);
	void Battle(Character* player);//
};