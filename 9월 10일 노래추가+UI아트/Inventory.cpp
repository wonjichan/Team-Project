#include "Inventory.h"
#include "Character.h"
#include <iostream>

Inventory::Inventory()
{
    items = {};
}
// 소멸자: 동적 할당한 아이템 정리
Inventory::~Inventory() {
    for (const auto& item : items)
    {   // items 벡터에 들어있는 아이템 포인터들을 하나씩 꺼냄
        delete item;
    }
}
vector<Item*> Inventory::getItem()
{
    return items;
}
// 같은 종류 아이템이 이미 있으면 수량 증가, 없으면 새로 추가
void Inventory::addItem(Item* item)
{
    for (auto& existing : items)
    {   // 현재 인벤토리에 들어 있는 아이템들 순회
        if (existing->getName() == item->getName())
        {  // 이름이 같으면 같은 종류의 아이템
            existing->addQuantity(item->getQuantity()); // 수량만 합쳐줌
            return;        // 함수 종료
        }
    }
    items.push_back(item); 
}

// 아이템 사용
void Inventory::useItem(int index, Character& player)
{
    // 인덱스가 음수거나, 현재 아이템 개수보다 크거나 같으면 잘못된 접근
    if (index < 0 || index >= items.size())
    {
        std::cout << "아이템이 없습니다.\n";   // 사용자에게 알림 메시지
        return;   // 함수 종료
    }
    Item* item = items[index];   // 인벤토리에서 index번째 아이템 꺼냄
    item->use(player);           // 해당 아이템을 player 캐릭터에게 사용
     
    if (item->getQuantity() <= 0)
    {  // 아이템을 다 써서 수량이 0 이하가 되면
        delete item;                 // 메모리 해제
        items.erase(items.begin() + index);  // 벡터에서 제거
    }
}

// 현재 인벤토리 출력
void Inventory::showItems() const
{
    std::cout << "===== 인벤토리 =====\n";

    if (items.empty())
    {   // 인벤토리에 아무것도 없으면
        std::cout << "인벤토리가 비어 있습니다.\n";  // 사용자에게 알림
        return; // 출력 끝
    }

    // 인벤토리에 아이템이 있을 경우 목록 출력
    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout <<"["<< i + 1 <<"]" << ": " << items[i]->getName()   // 아이템 이름 출력
            << " (x" << items[i]->getQuantity()   // 아이템 수량 출력
            << ")\n";
    }
}