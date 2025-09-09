#pragma once
#include "Monster.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h" 
#include "Inventory.h"
Monster::Monster(string _name) : name(_name)
{
	Character* player = Character::getInstance(name);
	srand(static_cast<unsigned int>(time(nullptr)));
	health = rand() % (player->GetLevel() * 20) + (player->GetLevel() * 30);
	attack = rand() % (player->GetLevel() * 5) + (player->GetLevel() * 10);
	isBattle = false;
}

int Monster::getAttack() { return attack; }
string Monster::getName() { return name; }
int Monster::getHealth() { return health; }
void Monster::settBattle(bool isplay) { this->isBattle = isplay; }
bool Monster::IsBattle() { return isBattle; }

void::Monster::takeDamage(Character* player)
{
	system("cls");
	int Random_gold = 0; 
	srand((unsigned int)time(NULL)); 
	Random_gold = rand() % 11 + 10;
	
	cout << player->getName() << "이(가) " << getName() << "을(를) 공격합니다!" << endl;
	health -= player->getAttack();
	//몬스터가 죽었을 때 
	if (health <= 0)
	{
		string answer;
		isBattle = false;
		health = 0;
		cout << getName() << "이(가) 쓰러졌습니다!" << endl;
		TryDropItem(player);
		player->setExp(50);
		player->setGold(Random_gold);
		if (player->getEXP() >= 100)
		{
			player->levelUp();
		}
		cout << "전투에서 승리했습니다!" << "50 EXP와 " << Random_gold <<" 골드를 휙득했습니다. " << 
			" 현재 EXP:" << player->getEXP() << "/100" << ", 골드:" << player->getGold() << endl;
		//상점 방문 
		cout << "상점을 방문하시겠습니까? (Y/N):";
		cin >> answer; 
		if (answer == "Y") {
			cout << "상점을 방문" << endl;
		}
		else
		{
			cout << "전투를 계속 합니다!"<<endl;
		}
	}
	//전투 중 몬스터가 죽지 않았을 때 
	else
	{
		cout << getName() << "이(가) " << player->getAttack() << "의 피해를 입었습니다." << endl;
		cout << "현재 체력: " << health << endl;
		cout << "\n";
	}
	Sleep(500);
}

void Monster::TryDropItem(Character* player)
{
	Inventory* inv = player->getInventory();
	if (rand() % 100 < 30){
		cout << "아이템을 드랍했습니다!" << endl; 
		if (rand() % 2)
		{
			inv->addItem(new HealthPotion());
		}
		else
		{
			inv->addItem(new AttackBoost());
		}
	}
	else {
		cout << "아이템을 드랍하지 않았습니다!" << endl;
	}
	cout << "\n";
}