#include "Troll.h"

Troll::Troll(const std::string& name) : Monster(name) {}

void Troll::takeDamage(Character* player) {
    Monster::takeDamage(player);
}
