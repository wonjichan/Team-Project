#include "Slime.h"


Slime::Slime(string name) : Monster(name) {}
void Slime::takeDamage(Character* player) {
	Monster::takeDamage(player);
}