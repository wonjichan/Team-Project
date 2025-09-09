#include "AttackBoost.h"
#include "Character.h"

// 생성자 : 이름, 가격, 증가 수치
AttackBoost::AttackBoost(int quantity)
	: Item("Attack Boost", quantity, 15), attackIncrease(10) { }

void AttackBoost::use(Character& character) 
{
	character.addTempAttackBoost(attackIncrease); // 공격력 증가
	reduceQuantity(1); // 수량 1 감소
}