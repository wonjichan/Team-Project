#include "Slime.h"

Slime::Slime(std::string name) : Monster(name) {}

void Slime::takeDamage(Character* player) {
    Monster::takeDamage(player);
}
