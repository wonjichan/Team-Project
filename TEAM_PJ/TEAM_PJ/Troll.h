#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll(string name);
	void takeDamage(Character* character);
};