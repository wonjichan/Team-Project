#pragma once
#include <vector>
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
class Shop {
private:
	vector<Item*> Shop_Items;
	int randomInt(int min, int max);
public:
	Shop();
	~Shop();

	void resetStock();
	void showItems() const;

	void buyItem(int index , Character* player);
	void sellItem(int index, Character* player);
	void show_ShopItems() const;
};