#pragma once
#include "Monster.h"

class Slime : public Monster 
{
public:
	Slime(string name);
	void takeDamage(Character* character);
};