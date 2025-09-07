#include "GameManager.h"

int main()
{
	GameManager manager;
	string name; 
	
	cout << "캐릭터 이름을 입력하세요: "; 
	cin >> name; 
	Character* player = Character::getInstance(name);
	cout << "캐릭터 " << player->getName() << " 생성완료! " << "레벨:" << player->GetLevel() 
		<< ",체력:" << player->getHealth() << ",공격력:" << player->getAttack() << endl;
	
	while (player->getHealth() >= 0)
	{
		system("cls");
		manager.generateMonster(player);
		cout << "배틀을 시작합니다!" << endl;
		manager.Battle(player);
		system("pause");
	}


	return 0; 
}