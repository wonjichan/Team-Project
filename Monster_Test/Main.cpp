#include "GameManager.h"

int main()
{
	GameManager manager;
	Shop shop; 
	string name; 
	string answer; 
	int buy_num = 0;
	int sell_num = 0;
	int choice; 
	cout << "캐릭터 이름을 입력하세요: "; 
	cin >> name; 
	if (name.empty())
	{
		cout << "올바르지 못한 입력입니다. 다시 입력하세요" << endl; 
	}
	Character* player = Character::getInstance(name);
	cout << "캐릭터 " << player->getName() << " 생성완료! " << "레벨:" << player->GetLevel() 
		<< ",체력:" << player->getHealth() << ",공격력:" << player->getAttack() << endl;
	Inventory* inv = player->getInventory(); 
	while (player->getHealth() >= 0)
	{
		system("cls");
		manager.generateMonster(player);
		cout << "배틀을 시작합니다!" << endl;
		manager.Battle(player);
		cout << "상점을 방문하시겠습니까? (Y/N):";
		cin >> answer;
		if (answer == "Y") {

			
			cout << "====상점에 오신것을 환영합니다!====" << endl;
			cout << "1. 아이템 구매 2. 아이템 판매" << endl;
			cin >> choice; 
			if (choice == 1) {
				shop.resetStock();
				cout << "구매하시려는 아이템 번호를 입력해주세요: ";
				cin >> buy_num;
				shop.buyItem(buy_num-1, player);
			}
			else if (choice == 2) {
				shop.show_ShopItems();
				inv->showItems();
				cout << "판매하시려는 아이템 번호를 입력해주세요: ";
				cin >> sell_num;
				shop.sellItem(sell_num-1, player);
			}
		}
		else if (answer == "N")
		{
			cout << "전투를 계속 합니다!" << endl;
		}
		else { cout << "잘못 입력하셨습니다." << endl; }
		system("pause");
	}
	return 0; 
}