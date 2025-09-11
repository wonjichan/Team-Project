#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <random>


Shop::Shop()
{
	Shop_Items = {};
}

Shop::~Shop()
{
	for (auto item : Shop_Items) delete item;
}

int Shop::randomInt(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

void Shop::resetStock()
{
	for (auto item : Shop_Items) {
		delete item; 
	}
	Shop_Items.clear();

	int hpStock = randomInt(10, 20);
	int atkStock = randomInt(5, 10);

	Shop_Items.push_back(new HealthPotion("Health Potion",hpStock,10));
	Shop_Items.push_back(new AttackBoost("Attack Boost",atkStock,15));
	
	cout << "【Health Potion: 10 Gold " << "】 【"<<R"(Attack Boost: 15 Gold 】)" << endl;
	for (int i = 0; i < Shop_Items.size(); i++) {
		cout <<"[" << i + 1 <<"] " << Shop_Items[i]->getName() << ", " << Shop_Items[i]->getQuantity() << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	Inventory* playerInv = player->getInventory(); 
	if (index < 0 || index >= (int)Shop_Items.size())
	{
		cout << "잘못된 선택입니다.\n";
		return;
	}

	Item* item = Shop_Items[index];
	if (item->getQuantity() <= 0)
	{
		cout << "품절된 상품입니다.\n";
		return;
	}

	cout << "몇 개를 구매 하시겠습니까?\n>>> ";
	int count;
	cin >> count;

	if (count <= 0 || count > Shop_Items[index]->getQuantity())
	{
		cout << "구매 수량이 잘못 되었습니다.\n";
		return;
	}

	int cost = item->getPrice() * count;
	if (player->getGold() < cost)
	{
		cout << "골드가 부족합니다.\n";
		return;
	}
	player->desetGold(cost);

	if (item->getName() == "Health Potion")
	{
		playerInv->addItem(new HealthPotion("Health Potion", count,10));
	}
	else if (item->getName() == "Attack Boost")
	{
		playerInv->addItem(new AttackBoost("Attack Boost",count,15));
	}

	item->reduceQuantity(count);
	cout << item->getName() << "을(를) " << count << "개 구매했습니다.\n";
}

void Shop::sellItem(int index, Character* player)
{
	Inventory* inv = player->getInventory(); 
	vector<Item*> items = inv->getItem(); 
	cout << "몇 개를 판매하시겠습니까?\n>>> ";
	int count;
	cin >> count;
	//할당되지 않은 요소에 접근할 때 
	if (index < 0 || index >= items.size() ||
		items[index]->getQuantity() <= 0 || items[index] == nullptr) {
		cout << "판매할 아이템이 없습니다." << endl; 
		return;
	}
	if (count <= 0 || count > items[index]->getQuantity())
	{
		cout << "판매 수량이 잘못되었습니다.\n";
		return;
	}

	int sellPrice = (items[index]->getPrice() / 2) * count;
	player->setGold(sellPrice);

	items[index]->reduceQuantity(count);
	cout << items[index]->getName() << "을(를) " << count << "개 판매했습니다. +" << sellPrice << " Gold\n";
}
void Shop::show_ShopItems() const
{
	std::cout << "===== 상점 아이템 목록 =====\n";
	// 상점에 아이템 목록 출력
	for (size_t i = 0; i < Shop_Items.size(); i++)
	{
		std::cout << i + 1 << ": " << Shop_Items[i]->getName()   // 아이템 이름 출력
			<< " (x" << Shop_Items[i]->getQuantity()   // 아이템 수량 출력
			<< ")\n";
	}
}