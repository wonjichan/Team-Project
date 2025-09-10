#include "GameManager.h"
#include "Shop.h"
#include "Character.h"
#include <iostream>
#include <string>

int main()
{
    GameManager manager;
    Shop shop;
    std::string name;
    std::string answer;
    int buy_num = 0;
    int sell_num = 0;
    int choice;

    std::cout << "캐릭터 이름을 입력하세요: ";
    std::cin >> name;

    if (name.empty())
    {
        std::cout << "올바르지 못한 입력입니다. 다시 입력하세요" << std::endl;
        return 0; // 이름이 없으면 프로그램 종료
    }

    Character* player = Character::getInstance(name);

    std::cout << "캐릭터 " << player->getName() << " 생성완료! "
        << "레벨: " << player->GetLevel()
        << ", 체력: " << player->getHealth()
        << ", 공격력: " << player->getAttack() << std::endl;

    Inventory* inv = player->getInventory();

    while (player->getHealth() > 0)  // 체력 0 이하이면 게임 종료
    {
        system("cls");

        manager.generateMonster(player);
        std::cout << "배틀을 시작합니다!" << std::endl;
        manager.Battle(player);

        std::cout << "상점을 방문하시겠습니까? (Y/N): ";
        std::cin >> answer;

        if (answer == "Y" || answer == "y")
        {
            std::cout << "==== 상점에 오신 것을 환영합니다! ====" << std::endl;
            std::cout << "1. 아이템 구매  2. 아이템 판매" << std::endl;
            std::cin >> choice;

            if (choice == 1)
            {
                shop.resetStock();
                std::cout << "구매하시려는 아이템 번호를 입력해주세요: ";
                std::cin >> buy_num;
                shop.buyItem(buy_num - 1, player);
            }
            else if (choice == 2)
            {
                shop.show_ShopItems();
                inv->showItems();
                std::cout << "판매하시려는 아이템 번호를 입력해주세요: ";
                std::cin >> sell_num;
                shop.sellItem(sell_num - 1, player);
            }
            else
            {
                std::cout << "잘못된 선택입니다." << std::endl;
            }
        }
        else if (answer == "N" || answer == "n")
        {
            std::cout << "전투를 계속 합니다!" << std::endl;
        }
        else
        {
            std::cout << "잘못 입력하셨습니다." << std::endl;
        }

        system("pause");
    }

    return 0;
}
