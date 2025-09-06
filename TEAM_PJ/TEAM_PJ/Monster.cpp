#include "Monster.h"
#include <iostream>
#include <cstdlib>

std::string Monster::getName() const { return name; }
int Monster::getHealth() const { return health; }
int Monster::getAttack() const { return attack; }


void Monster::tryDropItem() const
{
	if (rand() % 100 < 30)
		std::cout << "아이템을 드랍했습니다!" << std::endl;
	else
		std::cout << "아이템을 드랍하지 않았습니다." << std::endl;
}