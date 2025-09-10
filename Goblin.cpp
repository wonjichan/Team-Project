#pragma once
#include "Goblin.h"

Goblin::Goblin(std::string name)
    : Monster(name)
{
}

void Goblin::takeDamage(Character* player)
{
    Monster::takeDamage(player);
}
