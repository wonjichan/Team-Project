#pragma once
#include <vector>
#include "Item.h"
#include "Inventory.h"

//  상점 클래스 (아이템 사고팔기)
class Shop 
{
private:
    std::vector<Item*> items; // 상점 재고
    int randomInt(int min, int max); // 랜덤 수량 생성

public:
    Shop();  // 생성자 -> 초기 재고 생성
    ~Shop(); // 소멸자 -> 메모리 정리

    void resetStock(); // 전투 후 재고 리셋
    void showItems() const;

    void buyItem(int index, Inventory& playerInv, int& gold);  //  구매
    void sellItem(int index, Inventory& playerInv, int& gold); //  판매
};
