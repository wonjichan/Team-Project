#pragma once
#include "Monster.h"

class Goblin : public Monster 
{
public:
	Goblin(string name);
	void takeDamage(Character* character);
};