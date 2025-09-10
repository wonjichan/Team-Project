#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <vector>

Inventory::Inventory()
    : items{} // 초기화 리스트 사용
{
}

// 소멸자: 동적 할당한 아이템 정리
Inventory::~Inventory()
{
    for (auto& item : items)
    {
        delete item;
    }
}

std::vector<Item*> Inventory::getItem()
{
    return items;
}

// 같은 종류 아이템이 이미 있으면 수량 증가, 없으면 새로 추가
void Inventory::addItem(Item* item)
{
    for (auto& existing : items)
    {
        if (existing->getName() == item->getName())
        {
            existing->addQuantity(item->getQuantity()); // 수량만 합쳐줌
            return; // 함수 종료
        }
    }

    items.push_back(item);
}

// 아이템 사용
void Inventory::useItem(int index, Character& player)
{
    // 인덱스가 음수거나, 현재 아이템 개수보다 크거나 같으면 잘못된 접근
    if (index < 0 || index >= static_cast<int>(items.size()))
    {
        std::cout << "아이템이 없습니다.\n"; // 사용자에게 알림 메시지
        return; // 함수 종료
    }

    Item* item = items[index]; // 인벤토리에서 index번째 아이템 꺼냄
    item->use(player); // 해당 아이템을 player 캐릭터에게 사용

    if (item->getQuantity() <= 0)
    {   // 아이템을 다 써서 수량이 0 이하가 되면
        delete item; // 메모리 해제
        items.erase(items.begin() + index); // 벡터에서 제거
    }
}

// 현재 인벤토리 출력
void Inventory::showItems() const
{
    std::cout << "===== 인벤토리 =====\n";

    if (items.empty())
    {
        std::cout << "인벤토리가 비어 있습니다.\n"; // 사용자에게 알림
        return; // 출력 끝
    }

    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << "[" << i + 1 << "]"
            << ": " << items[i]->getName()
            << " (x" << items[i]->getQuantity() << ")\n"; // 아이템 수량 출력
    }
}
