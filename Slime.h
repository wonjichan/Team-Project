#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster
{
public:
    Slime(const std::string& name);

    void takeDamage(Character* character) override;
};
