#pragma once
#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;


class Character
{
public:

	// 싱글톤 객체 호출
	static Character* getInstance(string nickname)
	{
		if (instance == nullptr)
		{
			instance = new Character(nickname);
		}
		return instance;
	}


	// getter 함수
	string getName();
	int getLevel();	
	int getHealth();		
	int getMaxHealth();  
	int getAttack();		
	int getExperience();	
	int getGold();		


	// setter 함수

	void setLevel(int lev);
	void setHealth(int hp);
	void setMaxHealth(int maxHp);
	void setAttack(int atk);
	void setExperience(int exp);
	void setGold(int gold);

	// 상태 조회 함수
	void displayStatus();

	// 레벨업 함수
	void levelUp();


	// 아이템 사용 함수
	void useItem();

	// 데미지 함수
	void takeDamage(Monster* monster);


private:
	
	// 생성자 (싱글톤)
	Character(string nickname);
	static Character* instance;

	// Status
	string name;	// 이름
	int level;		// 레벨
	int health;		// 체력
	int maxHealth;  // 최대체력
	int attack;		// 공격력
	int experience;	// 경험치
	int gold;		// 골드

	// inventory


};

