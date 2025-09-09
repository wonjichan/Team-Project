#include "HealthPotion.h"
#include "Character.h"
#include <algorithm>

// 생성자 : 이름, 가격, 회복량
HealthPotion::HealthPotion(int quantity)
	: Item("Health Potion", quantity, 10), healAmount(50) {
}

void HealthPotion::use(Character& character) 
{
	// 현재 체력 + 회복량, 단 최대 체력을 넘지 않음
	int newHealth = std::min(character.getHealth() + healAmount, character.getMaxHealth());
	character.setHealth(newHealth); // 체력 반영
	reduceQuantity(1); // 수량 1 감소
}