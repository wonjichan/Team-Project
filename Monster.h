#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <Windows.h>

class Inventory;
class Character;
class HealthPotion;
class AttackBoost;

using namespace std;

// 몬스터 클래스
class Monster
{
protected:
    std::string name;
    int health;
    int attack;
    bool isBattle;

public:
    Monster(const std::string& name);

    int getAttack() const;
    virtual std::string getName() const;
    virtual int getHealth() const;

    virtual void takeDamage(Character* character);
    virtual void TryDropItem(Character* player);

    void setBattle(bool isplay);
    bool IsBattle() const;
};
