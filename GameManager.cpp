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
	//vector<Item*> inventory / 요소 = new HealthPotion , new AttackPotion ... 

void GameManager::disPlayInventory(vector<Item*>& item)
{
	for (const auto& p : item)
	{
		cout << "===인벤토리===" << endl;
		cout << p->getName() << endl;
	}
}
void GameManager::Battle(Character* player)
{
//if player 피가 0보다 클 때
//if player hp < 30 일 때 아이템 있다면 먹을건지 == useItem() 
//몬스터 공격력 > 플레이어 남은 피 => Die //if player.level >= 100일 때  levelUp() 호출 
//플레이어 공격력 > 몬스터 남은 피 => Die
	while (player->getHealth() != 0 && monster->getHealth() != 0)
	{
		cout << monster->getName() << " 등장! " << "체력: " << monster->getHealth() << ", 공격력: " << monster->getAttack() << endl;
		/*if (player->getHealth() < 30)
		{
			player->useItem(2);
		}*/
		//스피드가 빠른순?
		cout << player->getName() << "가 " << monster->getName() << "을 공격합니다!" << endl;
		monster->takeDamage(player);
		cout << monster->getName() << " 체력:" << monster->getHealth() << endl;


		cout << monster->getName() << "가 " << player->getName() << "을 공격합니다!" << endl;
		player->takeDamage(monster);
		cout << player->getName() << " 체력:" << player->getHealth() << endl;
		//몬스터 죽으면 50경험치 + 랜덤골드(10~20) 
	}	
};
