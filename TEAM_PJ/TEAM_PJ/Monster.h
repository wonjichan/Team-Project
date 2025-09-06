#pragma once
#include <string>

class Monster 

{
protected:
	std::string name;
	int health;
	int attack;

	void tryDropItem() const; //공통 아이템 드랍 함수


public:
	virtual ~Monster(){}

	std::string getName() const;  //상속받는 public 
	int getHealth() const;  // 일반 public
	int getAttack() const;  // 일반 public

	virtual void takeDamage(int damage) = 0; //가상함수
};