#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> items; // 아이템 저장소 (포인터)

public:
	~Inventory(); // 소멸자에서 아이템 정리
	
	void addItem(Item* item); // 아이템 추가
	void useitem(int index, Character& player); // 특정 아이템 사용
	void showItems() const; // 인벤토리 출력

	Item* getItem(int index); // 특정 아이템 가져오기
};