#pragma once
#include "Monster.h"
#include <string>


class Orc : public Monster
{

public:
	Orc(const std::string& n, int level);

	void takeDamage(int damage) override;

};

