#include "GameManager.h"
#include <io.h>
#include <fcntl.h>
#include "ShowMainMenu.h"


void playGame();
void EnterShop(Character* player);

int main() {
	SetConsoleOutputCP(CP_UTF8);  // 출력 코드페이지 UTF-8 설정
	SetConsoleCP(CP_UTF8);        // 입력 코드페이지 UTF-8 설정
	wcout.imbue(locale(".UTF8"));
	BGM::getInstance()->playBGM("C:\\BGM\\bgm_menu.wav");
	srand((unsigned int)time(NULL));
	ShowMainMenu menu;
	
	while (true) {
		system("cls");
		int selected = menu.arrowMenu();
		switch (selected) {
		case 0:  // 모험 시작하기
			playGame();
			break;
		case 1:  // 게임 설명
			system("cls");
			menu.showGameDescription();
			break;
		case 2:  
			system("cls");
			BGM::getInstance()->stopBGM();
			cout << "게임을 종료합니다!" << endl;
			return 0;
		default:
			cout << "잘못된 선택입니다." << endl;
			system("pause");
			break;
		}
	}
}
#pragma region MyRegion
void playGame() {
	GameManager manager;
	Shop shop;
	string name;
	string answer;
	cout << "캐릭터 이름을 입력하세요\n>> ";
	cin >> name;

	Character* player = Character::getInstance(name);
	cout << "캐릭터 " << player->getName() << " 생성완료! "
		<< "레벨:" << player->GetLevel()
		<< ", 체력:" << player->getHealth()
		<< ", 공격력:" << player->getAttack() << endl;

	Inventory* inv = player->getInventory();

	while (player->getHealth() > 0) {
		system("cls");
		manager.generateMonster(player);
		cout << "배틀을 시작합니다!" << endl;
		manager.Battle(player);
		
		cout << "상점을 방문하시겠습니까? (Y/N)\n>>> ";
		cin >> answer;
		if (answer == "Y" || answer == "y") {
			EnterShop(player);
		}
		else if (answer == "N" || answer == "n") {
			cout << "새로운 몬스터와 전투를 하겠습니다!" << endl;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
			Sleep(300);
			continue; 
		}
		system("pause");
	}
}
void EnterShop(Character* player) {
	Shop shop;
	string answer;
	int choice,buy_num,sell_num;
	Inventory* inv = player->getInventory();
	BGM::getInstance()->playBGM("C:\\BGM\\bgm_shop.wav");
	cout << "==== 상점에 오신것을 환영합니다! ====" << endl;
	while (true)
	{
		Sleep(300);
		system("cls");
		cout << "1.아이템 구매  2.아이템 판매  3.상점 나가기\n>>> ";
		cin >> choice;
		if (choice == 1) {
			shop.resetStock();
			cout << "구매하시려는 아이템 번호를 입력해주세요.\n>>> ";
			cin >> buy_num;
			shop.buyItem(buy_num - 1, player);
		}
		else if (choice == 2) {
			inv->showItems();
			cout << "판매하시려는 아이템 번호를 입력해주세요.\n>>> ";
			cin >> sell_num;
			shop.sellItem(sell_num - 1, player);
		}
		else if (choice == 3) {
			cout << "====다음에 또 이용해주세요====\n" << endl;
			cout << "새로운 몬스터와 싸우러 갑니다!" << endl;
			break;
		}
		else { cout << "잘못 눌렀습니다. 다시 입력해주세요.\n" << endl;; }
		Sleep(1000);
		system("pause");
	}
}
#pragma endregion

