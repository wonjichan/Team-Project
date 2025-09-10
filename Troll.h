#pragma once
#include "Monster.h"
#include <string>

class Troll : public Monster
{
public:
    Troll(const std::string& name);
    void takeDamage(Character* character) override;
};
