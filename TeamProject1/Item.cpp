#include "Item.h"

Item::Item(const std::string& name, int quantity, int price) : name(name), quantity(quantity), price(price) { } // 생성자 : 이름, 수량, 가격 초기화

std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
int Item::getPrice() const { return price; }

void Item::addQuantity(int amount) { quantity += amount; }
void Item::reduceQuantity(int amount) {
	if (quantity >= amount) 
	{
		quantity -= amount;
	}
}