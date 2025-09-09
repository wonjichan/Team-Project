#pragma once  // 이 헤더는 여러번 추가해도 한번만 포함되어 문제가 없도록 해주는 지시문
#include <string>
#include <iostream>
using namespace std;

class Monster;   // 전방선언 (Monster 클래스를 Player 클래스 안에서 포인터로 사용하기위함)

class Player {
public:
    Player(string nickname);

    virtual void attack() = 0;
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
    void setNickname(string nickname);
    bool setHP(int HP);
    bool setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected: // 파생클래스에서 사용할 수 있도록 private를 쓰지 않는다.
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};

