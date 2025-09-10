#include "HealthPotion.h"
#include "Character.h"   // 체력 조작을 위해 Character 필요
#include <algorithm>     // std::min 사용을 위해 포함
#include <iostream>      // std::cout 사용을 위해 포함
#include <string>

HealthPotion::HealthPotion(const std::string& name, int quantity, int price)
    : Item(name, quantity, price), healAmount(50)
{
}

void HealthPotion::use(Character& player)
{
    int newHealth = std::min(player.getHealth() + healAmount, player.getMaxHealth());

    if (player.getHealth() == player.getMaxHealth())
    {
        std::cout << "이미 체력이 완전 회복된 상태입니다!" << std::endl;
    }
    else
    {
        std::cout << player.getName() << "의 체력이 50 증가했습니다!\n" << std::endl;
        player.setHealth(newHealth);  // 체력 반영
        reduceQuantity(1);            // 수량 1 감소
    }
}
