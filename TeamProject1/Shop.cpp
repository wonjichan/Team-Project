#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <random>

// 랜덤 정수 생성 함수
int Shop::randomInt(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

// 생성자 : 재고 채우기
Shop::Shop() {
	resetStock();
}

// 소멸자 : 동적 메모리 해제
Shop::~Shop()
{
	for (auto item : items) 
	{
		delete item;
	}
}


// 재고 리셋(랜덤 수량으로 다시 채움)
void Shop::resetStock()
{
	for (auto item : items) delete item;
	items.clear();

	int hpStock = randomInt(10, 20); // 힐포션 10~20개
	int atkStock = randomInt(5, 10); // 어택부스트 5~10개

	items.push_back(new HealthPotion(hpStock));
	items.push_back(new AttackBoost(atkStock));
}

// 상점 아이템 출력
void Shop::showItems() const {
	std::cout << "======= 상점 =======\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		std::cout << i << ": " << items[i]->getName() << " (x" << items[i]->getQuantity() << ") - " << items[i]->getPrice() << " Gold\n";
	}
}

// 아이템 구매
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
        std::cout << "품절된 아이템입니다.\n";
        return;
    }

    int count = 0;
    while (true) 
    {
        std::cout << "몇 개를 구매하시겠습니까? ";
        std::cin >> count;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "숫자를 입력해주세요.\n";
            continue; // 다시 입력받음
        }

        if (count <= 0 || count > item->getQuantity()) 
        {
            std::cout << "구매 수량이 잘못되었습니다. (재고: " << item->getQuantity() << ")\n";
            continue; // 다시 입력받음
        }

        break; // 정상 입력이면 루프 종료
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
    std::cout << " " << item->getName() << "을(를) "
        << count << "개 구매했습니다!\n";
}

// 아이템 판매
void Shop::sellItem(int index, Inventory& playerInv, int& gold) 
{
    Item* item = playerInv.getItem(index);
    if (!item) 
    {
        std::cout << "잘못된 선택입니다.\n";
        return;
    }

    int count = 0;
    while (true) 
    {
        std::cout << "몇 개를 판매하시겠습니까? ";
        std::cin >> count;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "숫자를 입력해주세요.\n";
            continue;
        }

        if (count <= 0 || count > item->getQuantity()) 
        {
            std::cout << "판매 수량이 잘못되었습니다. (보유: " << item->getQuantity() << ")\n";
            continue;
        }

        break; // 정상 입력 -> 루프 종료
    }

    int sellPrice = (item->getPrice() / 2) * count;
    gold += sellPrice;

    item->reduceQuantity(count);
    std::cout << " " << item->getName() << "을(를) "
        << count << "개 판매했습니다! +" << sellPrice << " Gold\n";
}
