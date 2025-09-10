#pragma once
#include "Troll.h"


Troll::Troll(string name) : Monster(name) {};
void Troll::takeDamage(Character* player) {
	Monster::takeDamage(player);
}
