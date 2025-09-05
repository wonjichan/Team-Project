#include "GameManager.h"
class GameManager
{
private:
	Monster* monster; 
	vector<Item*> inventory; 
	int capacity;
	int size; 
public:
	GameManager(int _capacity = 10);
	//몬스터 랜덤 스폰 
	Monster* generateMonster(int level);
	//인벤토리 출력 
	//vector<Item*> inventory 
	void disPlayInventory(Item* item);
	void Battle(Character* player);
};
int main()
{ 
	
	
	return 0; 
}
