#include "HealthPotion.h"
#include "Character.h"   // 체력 조작을 위해 Character 필요
#include <algorithm>     // std::min 사용을 위해 포함

// 생성자: 이름은 "Health Potion", 수량과 회복량을 초기화
HealthPotion::HealthPotion(int quantity) : Item("Health Potion"), healAmount(50) {}

// 사용 시: 체력을 50 회복, 단 최대 체력을 넘지 않음
void HealthPotion::use(Character& player)
{
    int newHealth = std::min(player.getHealth() + healAmount, player.getMaxHealth());
    cout << player.getName() << "의 체력이 50 증가했습니다!" << endl;
    player.setHealth(newHealth); // 체력 반영
    reduceQuantity(1);              // 수량 1 감소
}