#pragma once
#include "Item.h"

// 공격력을 일시적으로 올려주는 아이템
class AttackBoost : public Item {
private:
    int attackIncrease; // 증가 공격력 (고정: +10)
public:
    AttackBoost(int quantity = 1);  // 생성자: 수량 지정 가능
    void use(Character& character) override; // 사용 시 공격력 강화
};