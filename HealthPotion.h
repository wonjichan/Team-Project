#pragma once
#include "Item.h"
#include <string>   // std::string 사용
#include "Character.h" // Character 참조 필요

class HealthPotion : public Item
{
private:
    int healAmount; // 회복량 (고정: 50)

public:
    HealthPotion(const std::string& name, int quantity, int price); // 생성자: 수량 지정 가능
    void use(Character& player) override; // 사용 시 체력 회복
};
