#pragma once
#include <string>

class Character; // Character 클래스가 뒤에 정의될 예정이라 전방 선언만 해둠

using namespace std; 
// 모든 아이템의 공통 부모 클래스 (추상 클래스)
class Item
{
protected:
    string name;   // 아이템 이름 (예: "Health Potion")
    int quantity;       // 해당 아이템 개수
    int price; 
public:
    // 생성자: 이름과 수량을 받아 초기화
    Item(const string& name, int quantity,int price);
    virtual ~Item() = default; // 가상 소멸자 (상속받은 클래스에서 안전한 삭제 가능)

    string getName() const;   // 아이템 이름 반환
    int getQuantity() const;       // 아이템 개수 반환
    void addQuantity(int amount);  // 아이템 수량 증가
    void reduceQuantity(int amount); // 아이템 수량 감소
    int getPrice() const; 
    // 순수 가상 함수 → 상속받은 클래스에서 반드시 구현해야 함
    virtual void use(Character& character) = 0;
};