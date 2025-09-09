#include "Orc.h"

Orc::Orc(string name) : Monster(name) {}

void Orc::takeDamage(Character* player) {
    Monster::takeDamage(player);
}
