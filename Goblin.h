#pragma once
#include "Monster.h"
#include <string>

class Goblin : public Monster
{
public:
    Goblin(const std::string& name);
    void takeDamage(Character* character);
};
