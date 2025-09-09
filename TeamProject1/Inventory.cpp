#include "Inventory.h"
#include "Character.h"
#include <iostream>

// 소멸자 : 동적 할당된 아이템 해제
Inventory::~Inventory() {
	for (auto item : items) delete item;
}

// 아이템 추가(같은 종류면 수량만 증가)
void Inventory::addItem(Item* item) {
	for (auto existing : items) {
		if (existing->getName() == item->getName()) {
			existing->addQuantity(item->getQuantity());
			delete item; // 중복 아이템 메모리 해제
			return;
		}
	}
	items.push_back(item); // 새로운 종류 아이템은 추가
}

void Inventory::useitem(int index, Character& player) {
	if (index < 0 || index >= (int)items.size()) {
		std::cout << "아이템이 없습니다.\n";
		return;
	}
	Item* item = items[index];
	item->use(player);
	if (item->getQuantity() <= 0) {
		delete item;
		items.erase(items.begin() + index);
	}
}

void Inventory::showItems() const {
	std::cout << "======= 인벤토리 ======\n";
	if (items.empty()) {
		std::cout << "인벤토리가 비어 있습니다.\n";
		return;
	}
	for (size_t i = 0; i < items.size(); i++) {
		std::cout << i << ": " << items[i]->getName() << " (x" << items[i]->getQuantity() << ")\n";
	}
}

Item* Inventory::getItem(int index)
{
	if (index < 0 || index >= (int)items.size()) return nullptr;
	return items[index];
}