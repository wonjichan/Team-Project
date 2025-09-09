#pragma once
#include <string>

class Character;

class Item {
protected:
	std::string name;
	int quantity;
	int price;

public:
	Item(const std::string& name, int quantity = 1, int price = 0);

	virtual ~Item() = default;

	std::string getName() const;
	int getQuantity() const;
	int getPrice() const;

	void addQuantity(int amount);
	void reduceQuantity(int amount);

	virtual void use(Character& character) = 0;
};