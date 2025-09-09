#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <random>

int Shop::randomInt(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

Shop::~Shop()
{
	for (auto item : items) delete items;
}

void Shop::resetStock()
{
	for (auto item : items) delete item;
	items.clear();

	int hpStock = randomInt(10, 20);
	int atkStock = randomInt(5, 10);

	items.push_back(new HealthPotion(hpStock));
	items.push_back(new AttackBoost(atkStock));
}

void Shop::buyItem(int index, Inventory& playerInv, int& gold)
{
	if (index < 0 || index >= (int)items.size())
	{
		std::cout << "잘못된 선택입니다.\n";
		return;
	}

	Item* item = items[index];
	if (item->getQuantity() <= 0)
	{
		std::cout << "품절된 상품입니다.\n";
		return;
	}

	std::cout << " 몇 개를 구매 하시겠습니까? ";
	int count;
	std::cin >> count;

	if (count <= 0 || count > item => getQuantity())
	{
		std::cout << " 구매 수량이 잘못 되었습니다.\n";
		return;
	}

	int cost = item->getPrice() * count;
	if (gold < cost)
	{
		std::cout << "골드가 부족합니다.\n";
		return;
	}

	gold -= cost;

	if (item->getName() == "Health Potion")
	{
		playerInv.addItem(new HealthPotion(count));
	}
	else if (item->getName() == "Attack Boost")
	{
		playerInv.addItem(new AttackBoost(count));
	}

	item->reduceQuantity(count);
	std::cout << item->getName() << "을(를)" << count << "개 구매했습니다.\n";
}

void Shop::sellItem(index, Inventory& playerInv, int& gold)
{
	Item* item = playerInv.getItem(index);
	if (!item)
	{
		std::cout << " 판매할 아이템이 없습니다.\n";
		return;
	}

	std::cout << "몇 개를 판매하시겠습니까? ";
	int count;
	std::cin >> count;

	if (count <= 0 || count < item->getQuantity())
	{
		std::cout << "판매 수량이 잘못되었습니다.\n";
		return;
	}

int sellPrice = (item->getPrice() / 2) * count;
gold += sellPrice;

item->reduceQuantity(count);
std::cout << item->getName() << "을(를) " << count << " 개 판매했습니다. +" << sellPrice << " Glod\n";
}
