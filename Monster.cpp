#pragma once
#include "Monster.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

Monster::Monster(const std::string& _name)
    : name(_name), isBattle(false)
{
    Character* player = Character::getInstance(name);
    srand(static_cast<unsigned int>(time(nullptr)));

    if (player->GetLevel() < 10)
    {
        health = rand() % (player->GetLevel() * 20) + (player->GetLevel() * 30);
        attack = rand() % (player->GetLevel() * 5) + (player->GetLevel() * 10);
    }
    else
    {
        health = rand() % (player->GetLevel() * 60) + (player->GetLevel() * 90);
        attack = rand() % (player->GetLevel() * 15) + (player->GetLevel() * 30);
    }
}

int Monster::getAttack() const
{
    return attack;
}

std::string Monster::getName() const
{
    return name;
}

int Monster::getHealth() const
{
    return health;
}

void Monster::setBattle(bool isplay)
{
    this->isBattle = isplay;
}

bool Monster::IsBattle() const
{
    return isBattle;
}

void Monster::takeDamage(Character* player)
{
    system("cls");

    srand(static_cast<unsigned int>(time(nullptr)));
    int Random_gold = rand() % 11 + 10;

    std::cout << player->getName() << "이(가) " << getName() << "을(를) 공격합니다!" << std::endl;
    health -= player->getAttack();

    if (health <= 0) // 몬스터가 죽었을 때
    {
        isBattle = false;
        health = 0;
        std::cout << getName() << "이(가) 쓰러졌습니다!" << std::endl;

        TryDropItem(player);
        player->setExp(50);
        player->setGold(Random_gold);

        if (player->getEXP() >= 100)
        {
            player->levelUp();
        }

        std::cout << "==================================================================================" << std::endl;
        std::cout << "전투에서 승리했습니다! 50 EXP와 " << Random_gold << " 골드를 획득했습니다. "
            << "현재 EXP: " << player->getEXP() << "/100, 골드: " << player->getGold() << std::endl;
        std::cout << "==================================================================================" << std::endl;
    }
    else // 전투 중 몬스터가 죽지 않았을 때
    {
        std::cout << getName() << "이(가) " << player->getAttack() << "의 피해를 입었습니다." << std::endl;
        std::cout << getName() << "의 현재 체력: " << health << std::endl << std::endl;
    }

    Sleep(500);
}

void Monster::TryDropItem(Character* player)
{
    Inventory* inv = player->getInventory();

    if (rand() % 100 < 60)
    {
        std::cout << "아이템을 드랍했습니다!" << std::endl;

        int r = rand() % 10;  // 0 ~ 9 사이의 숫자 생성
        if (r < 7)
        {
            inv->addItem(new HealthPotion("(Drop)Health Potion", 1, 10));
            std::cout << "체력 포션을 1개 얻었습니다." << std::endl;
        }
        else
        {
            inv->addItem(new AttackBoost("(Drop)Attack Potion", 1, 15));
            std::cout << "공격력 포션을 1개 얻었습니다." << std::endl;
        }
    }
    else
    {
        std::cout << "아이템을 드랍하지 않았습니다!" << std::endl;
    }

    std::cout << std::endl;
}
