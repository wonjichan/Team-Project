#pragma once
#include "Goblin.h"

Goblin::Goblin(string name) : Monster(name) {}
void Goblin::takeDamage(Character* player) {
	Monster::takeDamage(player);
}