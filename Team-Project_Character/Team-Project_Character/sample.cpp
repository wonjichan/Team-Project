#include "Player.h"
#include <iostream>
using namespace std;

//생성자
Player::Player(string nickname) {
    this->nickname = nickname;
    level = 1;
    HP = 100;
    MP = 50;
    power = 10;
    defence = 10;
    accuracy = 50;
    speed = 30;
    job_name = "무직";
}

void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "직업: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}

// getter 함수
string Player::getJobName() {
    return job_name;
}

string Player::getNickname() {
    return nickname;
}

int Player::getLevel() {
    return level;
}

int Player::getHP() {
    return HP;
}

int Player::getMP() {
    return MP;
}

int Player::getPower() {
    return power;
}

int Player::getDefence() {
    return defence;
}

int Player::getAccuracy() {
    return accuracy;
}

int Player::getSpeed() {
    return speed;
}

//setter함수

void Player::setNickname(string nickname) {
    this->nickname = nickname;
}

bool Player::setHP(int HP) {
    if (HP < 0) {
        this->HP = 0;
        return false;  // 체력이 0 미만이면 0으로 설정하고 실패 반환
    }
    this->HP = HP;
    return true;
}

bool Player::setMP(int MP) {
    if (MP < 0) {
        this->MP = 0;
        return false;  // 마력이 0 미만이면 0으로 설정하고 실패 반환
    }
    this->MP = MP;
    return true;
}

void Player::setPower(int power) {
    this->power = power;
}

void Player::setDefence(int defence) {
    this->defence = defence;
}

void Player::setAccuracy(int accuracy) {
    this->accuracy = accuracy;
}

void Player::setSpeed(int speed) {
    this->speed = speed;
}