#pragma once
#include "Character.h"
#include "Monster.h"
class Item;
Character* Character::instance = nullptr;

Inventory* Character::getInventory()
{
	return &inv;
}

Character::Character(string name) :name(name)
{
	level = 1; health = 200; attack = 30; experience = 0;
	maxHealth = 200; gold = 0;
	isBattle = false;
}

Character* Character::getInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}
	return instance;
}
void Character::levelUp()
{
	if (level < 10)
	{
		experience = 0;
		level += 1;
		maxHealth += level * 20;
		health = maxHealth;
		attack += level * 5;
		cout << "Level Up!!! 레벨이" << level << "이(가) 되었습니다!" << endl;
	}
}
void Character::useItem(int index)
{

}
int Character::GetLevel() { return level; }

void Character::setExp(int exp)
{
	experience += exp;
	if (exp >= 100) {
		levelUp();
	}
}
void Character::setGold(int gold)
{
	this->gold += gold;
}
void Character::desetGold(int gold) { this->gold -= gold; }
int Character::getEXP() { return experience; }
int Character::getGold() { return gold; }
int Character::getAttack() { return attack; }
int Character::getHealth() { return health; }
string Character::getName() { return name; }
int Character::getMaxHealth() { return maxHealth; }
void Character::setBattle(bool isplay) { this->isBattle = isplay; }
void Character::setHealth(int heal) { health = heal; }
void Character::setAttack(int att) { attack += att; }
bool Character::IsBattle() { return isBattle; }

void Character::displayStatus()
{
	cout << "========= 캐릭터 상태 정보 =========" << endl;
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "체력 : " << health << " / " << maxHealth << endl;
	cout << "공격력 : " << attack << endl;
	cout << "경험치 : " << experience << endl;
	cout << "골드 : " << gold << endl;
	cout << "====================================" << endl;

}
void Character::takeDamage(Monster* monster)
{
	cout << monster->getName() << "이(가) " << getName() << "을(를) 공격합니다!" << endl;
	health -= monster->getAttack();
	if (health <= 0) {
		health = 0;
		cout << getName() << "이 사망했습니다. Game Over!" << endl;
		isBattle = false;
		return;
	}
	else {
		cout << getName() << "이(가) " << monster->getAttack() << "의 피해를 입었습니다." << endl;
		cout << getName() << "의 현재 체력: " << health << endl;
		cout << "\n";
	}
}