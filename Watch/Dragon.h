#pragma once
#include "Monster.h"

class Dragon : public Monster
{
private:
	vector<string> rand_skill;
	int skill_Damage;
public:
	Dragon(string name);
	void takeDamage(Character* character);
	void printAsciiArt() const override;
	vector<string>* mvec();
	int GetSkill_Dmg();
	void SetSkill_Dmg(int damage);
};
