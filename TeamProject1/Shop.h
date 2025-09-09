#pragma once
#include <vector>
#include "Item.h"
#include "Inventory.h"

class Shop {
private:
	std::vector<Item*> items;
	int randomInt(int min, int max);

public:
	Shop();
	~Shop();

	void resetStock();
	void showItems() const;

	void buyItem(int index, Inventory& playerInv, int& gold);
	void sellItem(int index, Inventory& playerInv, int& gold);
};