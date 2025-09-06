#pragma once
#include "Monster.h"
#include <string>


class Goblin : public Monster
{

public:
	Goblin(const std::string& n, int level);

	void takeDamage(int damage) override;

};

