#pragma once
#include "Orc.h"
#include "Character.h"

Orc::Orc(const std::string& name)
    : Monster(name)
{
}

void Orc::takeDamage(Character* player)
{
    Monster::takeDamage(player);
}
