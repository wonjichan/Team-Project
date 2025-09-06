#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"
#include "Slime.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 초기화

    int level = rand() % 5 + 1; // 1~5레벨 랜덤

    // 랜덤 몬스터 생성
    Monster* monster = nullptr;
    int choice = rand() % 4; // 0~3 랜덤
    switch (choice)
    {
    case 0:
        monster = new Orc("Orc", level);
        break;
    case 1:
        monster = new Goblin("Goblin", level);
        break;
    case 2:
        monster = new Troll("Troll", level);
        break;
    case 3:
        monster = new Slime("Slime", level);
        break;
    }

    // 등장
    std::cout << monster->getName() << " 등장! 체력: "
        << monster->getHealth() << ", 공격력: "
        << monster->getAttack() << std::endl;

    std::cout << "\n--- 전투 시작! ---\n" << std::endl;

    // 전투: 몬스터 체력이 0이 될 때까지 피해 주기
    while (monster->getHealth() > 0)
    {
        int damage = rand() % 15 + 5; // 5~19 피해 랜덤
        monster->takeDamage(damage);
    }

    std::cout << "\n--- 전투 종료! ---" << std::endl;

    delete monster; // 동적 할당 해제
    return 0;
}
