#include "AttackBoost.h"
#include "Character.h"

// 생성자: 이름은 "Attack Boost", 증가 수치 10으로 초기화
AttackBoost::AttackBoost(int quantity)
    : Item("Attack Boost", quantity), attackIncrease(10) {
}

// 사용 시: 캐릭터의 tempAttackBoost 값을 10 증가
// → 전투 종료 시 clearTempBoost()로 초기화해야 함
void AttackBoost::use(Character& character) 
{
    character.addTempAttackBoost(attackIncrease);
    reduceQuantity(1); // 수량 1 감소
}
