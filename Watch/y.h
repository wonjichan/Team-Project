#pragma once
#include "Item.h"

// 체력을 회복하는 아이템
class HealthPotion : public Item
{
private:
    int healAmount; // 회복량 (고정: 50)
public:
    HealthPotion(string m , int quantity, int price);   // 생성자: 수량 지정 가능
    void use(Character& player) override; // 사용 시 체력 회복
};