#pragma once
#include "Monster.h"
#include <string>


class Slime : public Monster
{

public:
	Slime(const std::string& n, int level);

	void takeDamage(int damage) override;

};

