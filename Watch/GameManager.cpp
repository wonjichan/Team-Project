#include "GameManager.h"
#include "Inventory.h"


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
		case 4:monster = new Troll("트롤"); break;
		default:break;
		}
	}
	else
	{
		monster = new Dragon("드래곤");
		BGM::getInstance()->playBGM("C:\\BGM\\bgm_dragon.wav");
	}
	BGM::getInstance()->playBGM("C:\\BGM\\bgm_battle.wav");
	return monster;
}
//인벤토리 출력 
void GameManager::disPlayInventory(vector<Item*>& items)
{
	for (const auto& p : items)
	{
		if (p != nullptr && p->getQuantity() > 0)
		{
			cout << "====인벤토리====" << endl;
			std::cout << "이름: " << p->getName() << " 수량: " << p->getQuantity() <<"\n"<< endl;
			return;
		}
	}
	cout << "인벤토리가 비어있습니다!\n" << endl;
}
//배틀 로직 
void GameManager::Battle(Character* player)
{
//if player hp가 30%미만일 때 아이템 있다면 먹을건지 == useItem() 
	Inventory* inv = player->getInventory();
	vector<Item*> items = inv->getItem();
	int choice = 0; 
	int potion_num; 
	player->setBattle(true);
	monster->settBattle(true);

	system("cls");
	monster->printAsciiArt();
	cout << monster->getName() << " 등장! " << "체력: " << monster->getHealth() << ", 공격력: " << monster->getAttack() << endl;
	cout << "\n";
	//플레이어와 몬스터가 모두 전투가능 상태일 경우 
	while (player->IsBattle() && monster->IsBattle())
	{
		cout << "다음 행동을 입력하시오.\n1.공격한다  2.물약 사용  3.상태창 확인  4.인벤토리 확인  5.도망간다\n" << endl;
		cout << ">>> ";
		cin >> choice;
		if (choice == 1) {
			//Player가 Monster를 공격 
			monster->takeDamage(player);
		}
		else if (choice == 2){
			//getItem()반환값 => vecotr<items*> items
			vector<Item*> items = inv->getItem();
			if (!items.empty())
			{
				inv->showItems();
				cout << "어떤 아이템을 사용하시겠습니까? 번호를 입력해주세요!" << endl;
				cin >> potion_num;
				inv->useItem(potion_num - 1, *player);
				Sleep(1000);
				system("cls");
				continue;
			}
			else
			{
				cout << "사용할 수 있는 아이템이 없습니다!" <<"\n"<< endl;
				continue;  //break -> continue
			}
		}
		else if(choice == 3)
		{
			player->displayStatus(); 
			continue;   //break -> continue
		}
		else if (choice == 4)
		{
			disPlayInventory(items);
			continue;  //break -> continue 
		}
		else if (choice == 5)
		{
			cout << monster->getName() << "에게서 도망에 성공했다!" << endl;
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다\n" << endl;
			continue; //break -> continue 
		}
		//몬스터가 살아있으면 플레이어를 공격 
		if (monster->IsBattle())
		{
			player->takeDamage(monster);
		}
	}	
}
