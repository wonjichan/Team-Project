#include "GameManager.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

// ================================================
// 🎵 현재 브금 파일명을 저장 (중복 재생 방지용)
// ================================================
string currentBGM = "";

// ================================================
// 🎵 BGM 재생 함수 (같은 곡은 다시 안 틂)
// ================================================
void playBGM(const char* filename, bool loop = true) {
    if (currentBGM == filename) return; // 이미 같은 곡이면 return (다시 안 틂)
    currentBGM = filename;              // 현재 브금 갱신
    PlaySoundA(filename, NULL, SND_FILENAME | (loop ? SND_LOOP : 0) | SND_ASYNC);
}

// ================================================
// 🎵 BGM 중지 함수 (상태 초기화)
// ================================================
void stopBGM() {
    PlaySound(NULL, NULL, 0);
    currentBGM = ""; // 현재 브금 상태 리셋
}

// ================================================
// 콘솔 색상 설정 함수 (텍스트 + 배경)
// ================================================
void setColor(int textColor, int bgColor = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// ================================================
// 색상 코드 (Windows 콘솔 전용)
// ================================================
enum ConsoleColor {
    BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE,
    GRAY = 8, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, LIGHT_YELLOW, BRIGHT_WHITE
};

// ================================================
// 타이틀 출력 (색상 + ASCII 아트)
// ================================================
void showTitle()
{
    system("cls");
    std::cout << "\n\n";

    setColor(LIGHT_GREEN);
    std::cout << "                                                     @@          @@\n";
    std::cout << "                                                  (@@              @@)\n";

    setColor(LIGHT_YELLOW);
    std::cout << "                     @@)               @@          @:    (:@@:)    :@          @@               (@@\n";
    std::cout << "                    @                 :#            @@@@@@0@@0@@@@@@            #:                 @\n";

    setColor(LIGHT_RED);
    std::cout << "                   (##@@#:      (#@#<--(@@@@      _-@@            @@-_      @@@@)-->#@#)     :#@@##)\n";
    std::cout << "                        (@@@@@@@@@         @@@@@@@                    @@@@@@@         @@@@@@@@@)\n\n";

    setColor(BRIGHT_WHITE);
    std::cout << "                    ██████████    ████████     ██      ██  ██████████   ██████     ███████      ██████\n";
    std::cout << "                       ███        ██            ██   ██        ██       ██    ██   ██    ██    ██    ██\n";
    std::cout << "                       ███        ██             ██ ██         ██       ██    ██   ██    ██    ██ \n";
    std::cout << "                       ███        ████████        ███          ██       ███████    ███████     ██  █████\n";
    std::cout << "                       ███        ██              ███          ██       ████       ██          ██     ██\n";
    std::cout << "                       ███        ██             ██ ██         ██       ██  ██     ██          ██     ██\n";
    std::cout << "                       ███        ██            ██   ██        ██       ██   ██    ██          ██   ██\n";
    std::cout << "                       ███        ████████     ██     ██       ██       ██    ██   ██           █████\n\n";

    setColor(LIGHT_CYAN);
    std::cout << "            @@)                                      * 용사의 모험 *                                     (@@\n";

    setColor(LIGHT_RED);
    std::cout << "           @     @@         @@@)                                                        (@@@         @@     @\n";
    std::cout << "          @    _@  @       @          @@@@@@    _____@@#<<(==)>>#@@_____    @@@@@@          @       @  @_    @\n";
    setColor(LIGHT_YELLOW);
    std::cout << "          (#@@#@       @@@@:@@@@@@@@@@  || @@@@@  | @ << (-==-) >> @ |  @@@@@ ||  @@@@@@@@@@:@@@@       @#@@#)\n";
    std::cout << "               @@@@@@@@              @@@@@   |  @@@@ --<< (==) >>-- @@@@  |   @@@@@              @@@@@@@@\n";
    setColor(LIGHT_GREEN);
    std::cout << "                                      @   @###@@@  @@@@_        _@@@@  @@@###@   @\n";
    std::cout << "                                                       @-  ()  -@\n";
    std::cout << "                                                        @------@\n";
    std::cout << "                                                         @@__@@\n";

    setColor(WHITE, BLACK);
}

// ================================================
// 화살표 메뉴 출력
// ↑↓로 이동, Enter로 선택 가능
// ================================================
int arrowMenu()
{
    const char* menu[] = { "게임 시작하기", "게임 종료하기" };
    int menuSize = 2;
    int selected = 0;
    int key = 0;

    while (true)
    {
        showTitle();

        for (int i = 0; i < menuSize; i++)
        {
            if (i == selected)
                cout << "   ▶ " << menu[i] << " ◀" << endl;
            else
                cout << "     " << menu[i] << endl;
        }

        cout << "\n ↑↓ 방향키로 이동, Enter로 선택\n";

        key = _getch();
        if (key == 224) { // 방향키 입력
            key = _getch();
            if (key == 72) // ↑
                selected = (selected - 1 + menuSize) % menuSize;
            else if (key == 80) // ↓
                selected = (selected + 1) % menuSize;
        }
        else if (key == 13) { // Enter
            return selected;
        }
    }
}

// ================================================
// 메인 실행
// ================================================
int main()
{
    // 🎵 시작 시 → 메뉴 브금 실행
    playBGM("assets/audio/bgm_menu.wav");

    GameManager manager;
    Shop shop;
    string name;
    string answer;
    int buy_num = 0;
    int sell_num = 0;
    int choice;

    while (true)
    {
        int menuChoice = arrowMenu();

        if (menuChoice == 0) // 게임 시작하기
        {
            system("cls");
            cout << "캐릭터 이름을 입력하세요: ";
            cin >> name;
            if (name.empty())
            {
                cout << "올바르지 못한 입력입니다. 다시 입력하세요" << endl;
                continue;
            }

            Character* player = Character::getInstance(name);
            cout << "캐릭터 " << player->getName() << " 생성완료! "
                << "레벨:" << player->GetLevel()
                << ", 체력:" << player->getHealth()
                << ", 공격력:" << player->getAttack() << endl;

            Inventory* inv = player->getInventory();
            while (player->getHealth() > 0)
            {
                system("cls");

                // ================================================
                // 몬스터 생성 및 전투 브금 실행
                // 드래곤일 경우 웅장한 bgm_dragon.wav 재생
                // 아닐 경우 bgm_battle.wav 재생
                // 같은 브금이면 다시 재생 안 함 (이어짐)
                // ================================================
                Monster* monster = manager.generateMonster(player);
                if (monster->getName() == "드래곤") {
                    playBGM("assets/audio/bgm_dragon.wav");
                }
                else {
                    playBGM("assets/audio/bgm_battle.wav");
                }

                cout << "배틀을 시작합니다!" << endl;
                manager.Battle(player);

                cout << "상점을 방문하시겠습니까? (Y/N):";
                cin >> answer;
                if (answer == "Y") {
                    // ================================================
                    // 상점에 들어가면 bgm_shop.wav 재생
                    // ================================================
                    playBGM("assets/audio/bgm_shop.wav");

                    cout << "====상점에 오신것을 환영합니다!====" << endl;
                    cout << "1. 아이템 구매 2. 아이템 판매" << endl;
                    cin >> choice;
                    if (choice == 1) {
                        shop.resetStock();
                        cout << "구매하시려는 아이템 번호를 입력해주세요: ";
                        cin >> buy_num;
                        shop.buyItem(buy_num - 1, player);
                    }
                    else if (choice == 2) {
                        shop.show_ShopItems();
                        inv->showItems();
                        cout << "판매하시려는 아이템 번호를 입력해주세요: ";
                        cin >> sell_num;
                        shop.sellItem(sell_num - 1, player);
                    }

                    // ================================================
                    // 상점에서 나온 뒤 다시 전투 브금 복귀
                    // ================================================
                    if (monster->getName() == "드래곤") {
                        playBGM("assets/audio/bgm_dragon.wav");
                    }
                    else {
                        playBGM("assets/audio/bgm_battle.wav");
                    }
                }
                else if (answer == "N")
                {
                    cout << "전투를 계속 합니다!" << endl;
                    // 브금은 건드리지 않음 → 계속 이어짐
                }
                else {
                    cout << "잘못 입력하셨습니다." << endl;
                }
                system("pause");
            }

            // ================================================
            // 캐릭터 사망 시 → gameover 브금 실행
            // ================================================
            playBGM("assets/audio/bgm_gameover.wav");
            cout << "당신의 캐릭터가 죽었습니다..." << endl;
            system("pause");
        }
        else if (menuChoice == 1) // 게임 종료하기
        {
            stopBGM(); // 모든 브금 정지
            cout << "게임을 종료합니다. 안녕히 가세요!" << endl;
            break;
        }
    }

    return 0;
}
