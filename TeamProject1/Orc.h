#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc(string name);
	void takeDamage(Character* character);
};