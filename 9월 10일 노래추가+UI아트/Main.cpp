#include "GameManager.h"
#include <io.h>
#include <fcntl.h>
#include "ShowMainMenu.h"

void playGame();

int main() {
	SetConsoleOutputCP(CP_UTF8);  // 출력 코드페이지 UTF-8 설정
	SetConsoleCP(CP_UTF8);        // 입력 코드페이지 UTF-8 설정
	wcout.imbue(locale(".UTF8"));
	BGM bgm; 
	bgm.playBGM("C:\\BGM\\bgm_menu.wav");
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
			bgm.stopBGM();
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
	int buy_num = 0;
	int sell_num = 0;
	int choice;
	BGM bgm; 
	cout << "캐릭터 이름을 입력하세요: ";
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

		cout << "상점을 방문하시겠습니까? (Y/N): ";
		cin >> answer;
		if (answer == "Y" || answer == "y") {
			bgm.playBGM("C:\\BGM\\bgm_shop.wav");
			cout << "==== 상점에 오신것을 환영합니다! ====" << endl;
			cout << "1. 아이템 구매  2. 아이템 판매" << endl;
			cin >> choice;

			if (choice == 1) {
				shop.resetStock();
				cout << "구매하시려는 아이템 번호를 입력해주세요: ";
				cin >> buy_num;
				shop.buyItem(buy_num - 1, player);
			}
			else if (choice == 2) {
				shop.show_ShopItems();
				inv->showItems();
				cout << "판매하시려는 아이템 번호를 입력해주세요: ";
				cin >> sell_num;
				shop.sellItem(sell_num - 1, player);
			}
		}
		else if (answer == "N" || answer == "n") {
			cout << "전투를 계속 합니다!" << endl;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
		}
		system("pause");
	}
}
#pragma endregion

