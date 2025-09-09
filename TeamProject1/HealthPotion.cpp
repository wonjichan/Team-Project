#include "HealthPotion.h"
#include "Character.h"
#include <algorithm>

HealthPotion::HealthPotion(int quantity)
	: Item("Health Potion", quantity, 10), healAmount(50) {
}

void HealthPotion::use(Character& character) {
	int newHealth = std::min(character.getHealth() + healAmount, character.getMaxHealth());
	character.setHealth(newHealth);
	reduceQuantity(1);
}