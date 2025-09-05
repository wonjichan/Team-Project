#include "Character.h"
class Item


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

}

// 데미지 함수
void Character::takeDamage(Monster* monster)
{
	health -= monster->getAttack();
}

// 


