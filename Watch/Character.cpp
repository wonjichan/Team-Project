#pragma once
#include "Character.h"
#include "Monster.h"

class Item; 
Character* Character::instance = nullptr;

Inventory* Character::getInventory()
{
	return &inv; 
}

Character::Character(string name):name(name)
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
		cout << "Level Up!!! 레벨이" << level << R"(이(가) 되었습니다!)" << endl;
	}
}

int Character::GetLevel(){ return level; }

void Character::setExp(int exp)
{
	experience += exp;
	if (experience >= 100) {
		levelUp();
	}
}
void Character::setGold(int gold)
{
	this->gold += gold; 
}
void Character::desetGold(int gold) { this->gold -= gold; }
int Character::getEXP(){return experience;}
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
		BGM::getInstance()->playBGM("C:\\BGM\\bgm_gameover.wav");
		health = 0; 
		cout << "\033[31m";
		cout << getName() << "이(가) 사망했습니다. GAME OVER!" << endl;
		cout << "\033[0m";
		isBattle = false;
		//프로그램 종료 
		Sleep(300);
		exit(0);
	}
	else {
		//string Vector의 요소를 랜덤으로 출력, 플레이어 체력 -= 스킬데미지 
		//다운캐스팅 => 상속 관계, 그 중 virtual 가상함수가 있을 때 dynamic cast => 부모 <-> 자식 캐스팅이 가능 
		Dragon* dragon = dynamic_cast<Dragon*>(monster); 
		if (dragon != nullptr && dragon->getName() == "드래곤") {
			vector<string>* skills = dragon->mvec();
			int choice = rand() % skills->size(); 
			if (choice == 0) {
				dragon->SetSkill_Dmg(70); 
			}
			else if (choice == 1) {
				dragon->SetSkill_Dmg(40);
			}
			else {
				dragon->SetSkill_Dmg(30);
			}
			cout << monster->getName() << "이(가)" << getName() << "에게 스킬 " << (*skills)[choice] << "을(를) 사용했다!" << endl;
			health -= dragon->GetSkill_Dmg();
			cout << getName() << "(이)가" << monster->getAttack()+dragon->GetSkill_Dmg() << "의 피해를 입었습니다." << endl;
			cout << getName() << "의 현재 체력: " << getHealth() << endl;
		}
		else
		{
			cout << getName() << "이(가) " << monster->getAttack() << "의 피해를 입었습니다." << endl;
			cout << getName() << "의 현재 체력: " << getHealth() << endl;
		}
		cout << "\n";
	}
}