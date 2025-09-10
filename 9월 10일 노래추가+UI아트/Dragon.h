#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
	Dragon(string name);
	void takeDamage(Character* character);
	void printAsciiArt() const override;
};
