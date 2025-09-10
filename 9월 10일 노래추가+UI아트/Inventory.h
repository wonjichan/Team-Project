#pragma once
#include <vector>
#include "Item.h"

// 인벤토리: 여러 아이템을 관리하는 클래스
class Inventory
{
private:
    vector<Item*> items; // 아이템을 담는 컨테이너 (포인터로 관리)
public:
    Inventory();
    ~Inventory(); // 소멸자에서 아이템 정리

    vector<Item*> getItem();
    void addItem(Item* item);                   // 아이템 추가
    void useItem(int index, Character& player); // 특정 슬롯의 아이템 사용
    void showItems() const;                     // 아이템 목록 출력
};