#include "Character.h"
#include "Item.h"
#include "Monster.h"


// instance 초기화
Character* Character::instance = nullptr;

// 생성자 (싱글톤)
Character::Character(string nickname)
{
	name = nickname;
	level = 1;
	health = 200;
	maxHealth = 200;
	attack = 30;
	experience = 0;
	gold = 0;
}



// getter 함수
string Character::getName() { return name; }
int Character::getLevel() { return level; }
int Character::getHealth() { return health; }
int Character::getMaxHealth() { return maxHealth; }
int Character::getAttack() { return attack; }
int Character::getExperience() { return experience; }
int Character::getGold() { return gold; }


// setter 함수

void Character::setLevel(int lev) { level = lev; }
void Character::setHealth(int hp) { health = hp; }
void Character::setMaxHealth(int maxHp) { maxHealth = maxHp; }
void Character::setAttack(int atk) { attack = atk; }
void Character::setExperience(int exp) { experience = exp; }
void Character::setGold(int gold) { this->gold = gold; }


// 상태 조회 함수
void Character::displayStatus()
{
	cout << "========= 캐릭터 상태 정보 =========" << endl;
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "체력 : " << health << " / " << maxHealth << endl;
	cout << "공격력 : " << attack << endl;
	cout << "경험치 : " << experience << endl;
	cout << "골드 : " << gold << endl;
	cout << "====================================" << endl;

}


// 레벨업 함수 , 레벨업 시 체력과 공격력 상승 구현
void Character::levelUp()
{
		level += 1;  // 레벨 상승
		experience = 0;  // 경험치 초기화
		maxHealth *= level * 20;  // 최대체력 상승
		health = maxHealth; // 체력 회복
		attack += level * 5; // 공격력 상승
		cout << "Level Up!!! 레벨이 '" << level << "' 이 되었습니다!" << endl;
}


// 아이템 사용 함수
void Character::useItem()
{
	int choiseNum;
	while (choiseNum != 3)
	{
	cout << "=======아이템 사용==============" << endl;
	cout << "어떤 아이템을 사용하시겠습니까?" << endl;
	cout << "1. 체력포션 : 체력을 50 회복한다. (현재 수량 : " << HealthPotion->getQuantity() << "개)" << endl;
	cout << "2. 어택부스트 : 공격력을 10 증가시킨다. (현재 수량 : " << AttackBoost->getQuantity() << "개)" << endl;
	cout << "3. 아이템을 사용하지 않는다." << endl;
	cout << "번호를 선택해주세요";
	cin >> choiseNum;

	switch (choiseNum)
	{
	case 1:
		if (health != maxHealth)
		{
			Item::HealthPotion();
			cout << "체력을 " << Item::newHealth << " 회복했습니다!" << endl;
				break;
		}
		else
			cout << "이미 체력이 완전 회복된 상태입니다." << endl;
		break;
	case 2:
		Item::AttackBoost();
		cout << "공격력이 10 증가했습니다!" << endl;
		break;
	default:
		cout << "잘못된 번호를 선택하셨습니다. 다시 선택해주세요." << endl;
		break;
	}
	}	
}

// 데미지 함수
void Character::takeDamage(Monster* monster)
{
	health -= monster->getAttack();
}

// 


