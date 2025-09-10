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
	if (player->GetLevel() < 10)
	{
		health = rand() % (player->GetLevel() * 20) + (player->GetLevel() * 30);
		attack = rand() % (player->GetLevel() * 5) + (player->GetLevel() * 10);
	}
	else
	{
		health = rand() % (player->GetLevel() * 60) + (player->GetLevel() * 90);
		attack = rand() % (player->GetLevel() * 15) + (player->GetLevel() * 30);
	}
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
	
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); //늦게출력
	cout << player->getName() << "이(가) " << getName() << "을(를) 공격합니다!" << endl;
	health -= player->getAttack();
	//몬스터가 죽었을 때 
	if (health <= 0)
	{
		string answer;
		isBattle = false;
		health = 0;

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //늦게출력
		cout << getName() << "이(가) 쓰러졌습니다!" << endl;
		TryDropItem(player);
		player->setExp(50);
		player->setGold(Random_gold);
		if (player->getEXP() >= 100)
		{
			player->levelUp();
		}
		cout << "==================================================================================" << endl;
		cout << "" << endl; //공백 
		cout << "전투에서 승리했습니다!" << " 50 EXP와 " << Random_gold <<" 골드를 휙득했습니다. " << 
			" 현재 EXP:" << player->getEXP() << "/100" << ", 골드:" << player->getGold() << endl;
		cout << "" << endl; //공백
		cout << "==================================================================================" << endl;
	}
	//전투 중 몬스터가 죽지 않았을 때 
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //늦게출력
		cout << getName() << "이(가) " << player->getAttack() << "의 피해를 입었습니다." << endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //늦게출력
		cout <<getName()<<"의 현재 체력: " << health << endl;
		cout << "\n";
	}
	Sleep(500);
}

void Monster::TryDropItem(Character* player)
{
	Inventory* inv = player->getInventory();
	vector<Item*> item = inv->getItem(); 
	if (rand() % 100 < 60){

		cout << "아이템을 드랍했습니다!" << endl; 
		int r = rand() % 10;  // 0 ~ 9 사이의 숫자 생성
		if (r < 7) {
			inv->addItem(new HealthPotion("(Drop)Health Potion",1,10));
			cout << "체력 포션을 1개 얻었습니다." << endl;
		}
		else {
			inv->addItem(new AttackBoost("(Drop)Attack Potion",1,15));
			cout << "공격력 포션을 1개 얻었습니다." << endl;
		}
	}
	else {
		cout << "아이템을 드랍하지 않았습니다!" << endl;
	}
	cout << "\n";
}