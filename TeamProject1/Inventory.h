#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> items;

public:
	~Inventory();

	void addItem(Item* item);
	void useitem(int index, Character& player);
	void showItems() const;

	Item* getItem(int index);
};