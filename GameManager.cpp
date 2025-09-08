#include "GameManager.h"
#include "Item.h"

GameManager::GameManager()
{
	monster = nullptr;
}
//몬스터 랜덤 스폰 
Monster* GameManager::generateMonster(Character* player)
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 4 + 1;
	if (player->GetLevel() < 10)
	{
		switch (randNum)
		{
		case 1:monster = new Slime("슬라임"); break;
		case 2:monster = new Goblin("고블린"); break;
		case 3:monster = new Orc("오크"); break;
		case 4:monster = new Troll("트롤");
		default:break;
		}
	}
	else
	{
		monster = new Dragon("드래곤");
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
//if player hp가 30%미만일 때 아이템 있다면 먹을건지 == useItem() 
	int choice = 0; 
	player->setBattle(true);
	monster->settBattle(true);
	cout << monster->getName() << " 등장! " << "체력: " << monster->getHealth() << ", 공격력: " << monster->getAttack() << endl;
	while (player->IsBattle() && monster->IsBattle())
	{
		cout << "다음 행동을 입력하시오. 1. 공격한다 2. 도망간다" << endl;
		cin >> choice;
		if (choice == 1) {
			//Player가 Monster를 공격 
			monster->takeDamage(player);
		}
		else if (choice == 2){
			cout << monster->getName() << "에게서 도망에 성공했다!" << endl;
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl; 
			break; 
		}
		//몬스터가 살아있으면 플레이어를 공격 
		if (monster->IsBattle())
		{
			player->takeDamage(monster);
		}
	}	
};
