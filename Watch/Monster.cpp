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
		health = rand() % (player->GetLevel() * 60) + (player->GetLevel() * 80);
		attack = rand() % (player->GetLevel() * 15) + (player->GetLevel() * 25);
	}
	//불 브레스, 꼬리 휘두르기, 발톱으로 찍기
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
		//다운캐스팅, 부모 참조/포인터 -> 자식 참조/포인터 
		Dragon* dragon = dynamic_cast<Dragon*>(this);
		//dragon != nullptr일 떄 
		if (dragon) {
			Random_gold *= 4;
		}
		player->setGold(Random_gold);
		if (player->getEXP() >= 100)
		{
			player->levelUp();
		}
		cout << "\033[1;33m"; // 노란색(밝은) 텍스트
		cout << "==================================================================================" << endl;
		cout << "전투에서 승리했습니다!" << " 50 EXP와 " << Random_gold <<" 골드를 휙득했습니다. " << 
			" 현재 EXP:" << player->getEXP() << "/100" << ", 골드:" << player->getGold() << endl;
		cout << "==================================================================================" << endl;
		cout << "\033[0m"; // 색상 리셋
		if (dragon) {
			cout << "당신은 마침내 마지막 드래곤을 쓰러뜨렸다!" << endl;
			cout << "세상은 다시 평화를 되찾았고, 영웅의 전설은 오랫동안 기억될 것이다..." << endl;
			exit(0);
		}
	}
	//전투 중 몬스터가 죽지 않았을 때 
	else
	{
		cout << getName() << "이(가) " << player->getAttack() << "의 피해를 입었습니다." << endl;
		cout << getName() << "의 현재 체력: " << health << endl;
		cout << "\n";
	}
	Sleep(500);
}

void Monster::TryDropItem(Character* player)
{
	Inventory* inv = player->getInventory();
	vector<Item*> item = inv->getItem(); 
	if (rand() % 100 < 30){
		cout << "아이템을 드랍했습니다!" << endl; 
		int r = rand() % 10;  // 0 ~ 9 사이의 숫자 생성
		if (r < 7) {
			inv->addItem(new HealthPotion("(Drop)Health Potion",1,10));
			cout << "체력 포션을 1개 얻었습니다." << endl;
		}
		else {
			inv->addItem(new AttackBoost("(Drop)Attack Boost",1,15));
			cout << "공격력 포션을 1개 얻었습니다." << endl;
		}
	}
	else {
		cout << "아이템을 드랍하지 않았습니다!" << endl;
	}
	cout << "\n";
}