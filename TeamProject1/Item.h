#pragma once
#include <string>

class Character; // Character 클래스 전방 선언

class Item {
protected:
	std::string name; // 아이템 이름
	int quantity; // 아이템 개수
	int price; // 아이템 가격 (추가됨)

public:
	Item(const std::string& name, int quantity = 1, int price = 0);

	virtual ~Item() = default; // 가상 소멸자 ( 상속 시 안전한 메모리 해제 가능 )

	std::string getName() const;
	int getQuantity() const;
	int getPrice() const;

	void addQuantity(int amount);
	void reduceQuantity(int amount);

	virtual void use(Character& character) = 0; // 순수 가상 함수 -> 상속 클래스에서 반드시 구현
};