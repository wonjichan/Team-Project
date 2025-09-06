#include "Slime.h"
#include <iostream>
#include <cstdlib>  //랜덤



Slime::Slime(const std::string& n, int level)
{
	name = n;
	health = rand() % (level * 11) + (level * 20);
	attack = rand() % (level * 6) + (level * 5);
}

void Slime::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		std::cout << "이(가) 쓰러졌습니다!";
		tryDropItem();

		//메인에서 데미지를 호출 캐릭터의 데미지를 가져오는 작업 (일단불가능) 

	}
	else
	{
		std::cout << name << "이(가)" << damage
			<< "의 피해를 입었습니다. 현재 체력: "
			<< health << std::endl;

	}



}