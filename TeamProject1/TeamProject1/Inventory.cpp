#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Character.h"
using namespace std;

class Inventory {
private:
    vector<Item*> inventorySlot; // 아이템을 담는 vector
    Character character;

public:
    // 생성자: 슬롯 개수만큼 nullptr로 초기화
    Inventory(int size) : inventorySlot(size, nullptr) {}

    void AddItem(const string& itemName) {
        // 이미 있는 아이템이면 수량 증가
        for (auto& slot : inventorySlot) {
            if (slot != nullptr && slot->getName() == itemName) {
                slot->addQuantity(1);
                return;
            }
        }

        // 빈 칸에 새 아이템 넣기
        for (auto& slot : inventorySlot) {
            if (slot == nullptr) {
                if (itemName == "HealthPotion") {
                    slot = new HealthPotion("HealthPotion");
                }
                else if (itemName == "AttackBoost") {
                    slot = new AttackBoost("AttackBoost");
                }
                return;
            }
        }
    }

    void UseItem(int inventorySlotNumber) {
        if (inventorySlotNumber >= 0 && inventorySlotNumber < (int)inventorySlot.size()) {
            Item* item = inventorySlot[inventorySlotNumber];
            if (item != nullptr) {
                item->use(&character);
                if (item->getQuantity() <= 0) {
                    delete item; // 메모리 해제
                    inventorySlot[inventorySlotNumber] = nullptr;
                }
            }
        }
    }

    // 소멸자: vector 안에 있는 아이템 해제
    ~Inventory() {
        for (auto& slot : inventorySlot) {
            delete slot;
        }
    }
};
