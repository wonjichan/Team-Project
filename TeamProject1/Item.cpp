#include "Item.h"

// 생성자: 이름과 수량 초기화
Item::Item(const std::string & name, int quantity, int price) : name(name), quantity(quantity), price(price) {
}

// 아이템 이름 반환
std::string Item::getName() const
{
    return name;
}

// 아이템 개수 반환
int Item::getQuantity() const
{
    return quantity;
}

// 아이템 수량 증가
void Item::addQuantity(int amount)
{
    quantity += amount;
}

// 아이템 수량 감소 (단, 음수로 내려가지 않음)
void Item::reduceQuantity(int amount)
{
    if (quantity >= amount)
    {
        quantity -= amount;
    }
}
int Item::getPrice() const
{
    return price;
}