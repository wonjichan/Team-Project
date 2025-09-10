#pragma once
#include "Dragon.h"

Dragon::Dragon(string name)
    : Monster(name)
{
}

void Dragon::takeDamage(Character* player)
{
    Monster::takeDamage(player);
}
