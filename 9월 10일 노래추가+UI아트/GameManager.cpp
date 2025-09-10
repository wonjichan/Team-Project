#include "GameManager.h"
#include "Inventory.h"


GameManager::GameManager()
{
	monster = nullptr;
}
//몬스터 랜덤 스폰 
Monster* GameManager::generateMonster(Character* player)
{
	BGM bgm;
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
		bgm.playBGM("C:\\BGM\\bgm_dragon.wav");
	}
	bgm.playBGM("C:\\BGM\\bgm_battle.wav");
	return monster;
}
//인벤토리 출력 
void GameManager::disPlayInventory(vector<Item*>& items)
{
	//empty(): 요소가 없다면 True, 있다면 false 
	//단, 요소의 갯수를 기준으로 보는거지, nullptr이 들어가도 false(비어 있지않다)로 본다. 
	//items의 각 요소 == 객체의 주소(를 가리키는 포인터) 
	if (items.empty())
	{
		cout << "인벤토리가 비어있습니다!" << "\n" << endl;
		return;
	}
	else
	{
		cout << "===인벤토리===" << endl;
		for (const auto& p : items)
		{
			if (p == nullptr) {
				cout << "Value = nullptr" << endl; 
				continue; 
			}
			cout << "이름: " << p->getName() << "수량: " << p->getQuantity() << endl;
		}
	}
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
	while (player->IsBattle() && monster->IsBattle())
	{
		cout << "다음 행동을 입력하시오. 1.공격한다 2.물약 사용 3.상태창 확인 4.인벤토리 확인 5.도망간다" << endl;
		cin >> choice;
		if (choice == 1) {
			//Player가 Monster를 공격 
			monster->takeDamage(player);
		}
		else if (choice == 2){
			vector<Item*> items = inv->getItem();
			if (!items.empty())
			{
				inv->showItems();
				cout << "어떤 아이템을 사용하시겠습니까? 번호를 입력해주세요!" << endl;
				cin >> potion_num;
				inv->useItem(potion_num - 1, *player);
			}
			else
			{
				cout << "사용할 수 있는 아이템이 없습니다!" <<"\n"<< endl;
				break; 
			}
		}
		else if(choice == 3)
		{
			player->displayStatus(); 
			break;
		}
		else if (choice == 4)
		{
			disPlayInventory(items);
			break;
		}
		else if (choice == 5)
		{
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
}
