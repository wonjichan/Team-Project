#include "GameManager.h"
#include "Item.h"

GameManager::GameManager()
{
	monster = nullptr;
}
//몬스터 랜덤 스폰 
Monster* GameManager::generateMonster()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 4 + 1;
	switch (randNum)
	{
	case 1:monster = new Slime("슬라임");break;
	case 2:monster = new Goblin("고블린");break;
	case 3:monster = new Orc("오크");break;
	case 4:monster = new Troll("트롤");
	default:break;
	}
	return monster;
}
//인벤토리 출력 
void GameManager::disPlayInventory(vector<Item*>& item)
{
	for (const auto& p : item)
	{
		cout << "===인벤토리===" << endl;
		cout << p->getName() << endl;
	}
}
//배틀 로직 
void GameManager::Battle(Character* player)
{
//if player hp < 30 일 때 아이템 있다면 먹을건지 == useItem() 
	player->setBattle(true);
	monster->settBattle(true);
	int choice = 0; 
	cout << monster->getName() << " 등장! " << "체력: " << monster->getHealth() << ", 공격력: " << monster->getAttack() << endl;
	while (player->IsBattle() && monster->IsBattle())
	{
		cout << "다음 행동을 입력하시오. 1. 공격한다 2. 도망간다" << endl;
		cin >> choice;
		if (choice == 1) {
			monster->takeDamage(player);
		}
		else if (choice == 2){
			cout << monster->getName() << "으로부터 도망에 성공했다!" << endl;
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl; 
		}
		if (monster->IsBattle())
		{
			player->takeDamage(monster);
		}
	}	
};
