#pragma once
#include "Monster.h"
#include <string>
#include "Character.h"

class Orc : public Monster
{
public:
    Orc(const std::string& name);

    void takeDamage(Character* character) override;
};
