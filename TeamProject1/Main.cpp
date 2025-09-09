#include "GameManager.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

// 🎵 BGM 재생 함수
void playBGM(const char* filename, bool loop = true) {
    PlaySoundA(filename, NULL, SND_FILENAME | (loop ? SND_LOOP : 0) | SND_ASYNC);
}
void stopBGM() {
    PlaySound(NULL, NULL, 0); // 음악 중지
}

// 콘솔 색상 설정 함수
void setColor(int textColor, int bgColor = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// 색상 코드 (Windows 콘솔 전용)
enum ConsoleColor {
    BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE,
    GRAY = 8, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, LIGHT_YELLOW, BRIGHT_WHITE
};

// 타이틀 출력
void showTitle()
{
    system("cls");
    std::cout << "\n\n";

    setColor(LIGHT_GREEN); // 밝은 초록색
    std::cout << "                                                     @@          @@\n";
    std::cout << "                                                  (@@              @@)\n";

    setColor(LIGHT_YELLOW); // 노란색
    std::cout << "                     @@)               @@          @:    (:@@:)    :@          @@               (@@\n";
    std::cout << "                    @                 :#            @@@@@@0@@0@@@@@@            #:                 @\n";

    setColor(LIGHT_RED); // 빨간색
    std::cout << "                   (##@@#:      (#@#<--(@@@@      _-@@            @@-_      @@@@)-->#@#)     :#@@##)\n";
    std::cout << "                        (@@@@@@@@@         @@@@@@@                    @@@@@@@         @@@@@@@@@)\n\n";

    setColor(BRIGHT_WHITE); // 흰색 강조
    std::cout << "                    ██████████    ████████     ██      ██  ██████████   ██████     ███████      ██████\n";
    std::cout << "                       ███        ██            ██   ██        ██       ██    ██   ██    ██    ██    ██\n";
    std::cout << "                       ███        ██             ██ ██         ██       ██    ██   ██    ██    ██ \n";
    std::cout << "                       ███        ████████        ███          ██       ███████    ███████     ██  █████\n";
    std::cout << "                       ███        ██              ███          ██       ████       ██          ██     ██\n";
    std::cout << "                       ███        ██             ██ ██         ██       ██  ██     ██          ██     ██\n";
    std::cout << "                       ███        ██            ██   ██        ██       ██   ██    ██          ██   ██\n";
    std::cout << "                       ███        ████████     ██     ██       ██       ██    ██   ██           █████\n\n";

    setColor(LIGHT_CYAN); // 청록색
    std::cout << "            @@)                                      * 용사의 모험 *                                     (@@\n";

    setColor(LIGHT_RED); // 빨간색
    std::cout << "           @     @@         @@@)                                                        (@@@         @@     @\n";
    std::cout << "          @    _@  @       @          @@@@@@    _____@@#<<(==)>>#@@_____    @@@@@@          @       @  @_    @\n";
    setColor(LIGHT_YELLOW); // 노란색
    std::cout << "          (#@@#@       @@@@:@@@@@@@@@@  || @@@@@  | @ << (-==-) >> @ |  @@@@@ ||  @@@@@@@@@@:@@@@       @#@@#)\n";
    std::cout << "               @@@@@@@@              @@@@@   |  @@@@ --<< (==) >>-- @@@@  |   @@@@@              @@@@@@@@\n";
    setColor(LIGHT_GREEN); // 밝은 초록색
    std::cout << "                                      @   @###@@@  @@@@_        _@@@@  @@@###@   @\n";
    std::cout << "                                                       @-  ()  -@\n";
    std::cout << "                                                        @------@\n";
    std::cout << "                                                         @@__@@\n";

    setColor(WHITE, BLACK); // 마지막에 기본 색상으로 돌려놓기
}


// 화살표 메뉴 출력
int arrowMenu()
{
    const char* menu[] = { "게임 시작하기", "게임 종료하기" };
    int menuSize = 2;
    int selected = 0;
    int key = 0;

    while (true)
    {
        showTitle();  // 타이틀 출력 (용사의 모험까지)

        // 메뉴는 용사의 모험 바로 밑에 출력됨
        for (int i = 0; i < menuSize; i++)
        {
            if (i == selected)
                cout << "   ▶ " << menu[i] << " ◀" << endl;  // 선택된 메뉴 강조
            else
                cout << "     " << menu[i] << endl;
        }

        cout << "\n ↑↓ 방향키로 이동, Enter로 선택\n";

        key = _getch();
        if (key == 224) // 방향키 입력
        {
            key = _getch();
            if (key == 72) // ↑
                selected = (selected - 1 + menuSize) % menuSize;
            else if (key == 80) // ↓
                selected = (selected + 1) % menuSize;
        }
        else if (key == 13) // Enter
        {
            return selected;
        }
    }
}

int main()
{
    // 🎵 시작하면 메뉴 브금 재생
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
        int menuChoice = arrowMenu(); // 화살표 메뉴 실행

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

                // 몬스터 생성
                Monster* monster = manager.generateMonster(player);

                // 🎵 전투 브금 (드래곤인지 확인)
                stopBGM();
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
                    stopBGM();
                    playBGM("assets/audio/bgm_shop.wav"); // 상점 브금

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
                }
                else if (answer == "N")
                {
                    cout << "전투를 계속 합니다!" << endl;
                }
                else {
                    cout << "잘못 입력하셨습니다." << endl;
                }
                system("pause");
            }

            // 캐릭터 사망 시
            stopBGM();
            playBGM("assets/audio/bgm_gameover.wav");
            cout << "당신의 캐릭터가 죽었습니다..." << endl;
            system("pause");
        }
        else if (menuChoice == 1) // 게임 종료하기
        {
            stopBGM();
            cout << "게임을 종료합니다. 안녕히 가세요!" << endl;
            break;
        }
    }

    return 0;
}
