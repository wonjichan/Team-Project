#pragma once
#include "Monster.h"
#include <string>


class Troll : public Monster
{

public:
	Troll(const std::string& n, int level);

	void takeDamage(int damage) override;

};

