#include "ShowMainMenu.h"

void ShowMainMenu::setConsoleSize(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // 현재 콘솔 크기
    MoveWindow(console, r.left, r.top, width, height, TRUE); // 새 크기
}
void ShowMainMenu::Initialize() {
    setConsoleSize(1000, 700); // 콘솔 크기 (픽셀 단위)
    system("cls");
    cout << "\n\n";
    drawLogo();
    setColor(WHITE); // 색상 초기화
}

void ShowMainMenu::gotoXY(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(consoleHandle, pos);
}

void ShowMainMenu::setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void ShowMainMenu::drawLogo() {
    cout << "\n\n";
    cout << "\n\n";
    setColor(BRIGHT_WHITE);
    cout << "                                _______  ________   _________    _____  _____   _____  \n";
    cout << "                               |__   __| |  ____\\ \\ / /__   __|  |  __ \\|  __ \\ / ____| \n";
    cout << "                                  | |    | |__   \\ V /   | |     | |__) | |__) | |  __  \n";
    cout << "                                  | |    |  __|   > <    | |     |  _  /|  ___/| | |_ | \n";
    cout << "                                  | |    | |____ / . \\   | |     | | \\ \\| |    | |__| | \n";
    cout << "                                  |_|    |______/_/ \\_\\  |_|     |_|  \\_\\_|     \\_____| \n";

    setColor(LIGHT_CYAN);
    cout << "\n\n\n";
    
    cout << "                                                      << 용사의 모험 >>            \n";
}


void ShowMainMenu::drawMenuBox(int x, int y, int width, int height) {
    // 상단
    gotoXY(x, y); cout << "+" << string(width - 2, '-') << "+";

    // 중간
    for (int i = 1; i < height - 1; i++) {
        gotoXY(x, y + i); cout << "|";
        gotoXY(x + width - 1, y + i); cout << "|";
    }

    // 하단
    gotoXY(x, y + height - 1); cout << "+" << string(width - 2, '-') << "+";
}

int ShowMainMenu::arrowMenu() {
    vector<string> menu = { "모험 시작하기", "게임 설명", "게임 종료하기" }; // 메뉴 항목 수정
    int selected = 0;

    // 박스 위치와 크기 조정
    const int boxX = 48;
    const int boxY = 18;
    const int boxWidth = 28;
    const int boxHeight = menu.size() + 2;

    while (true) {
        Initialize();
        drawMenuBox(boxX, boxY, boxWidth, boxHeight);

        const string selector = "❯";

        for (size_t i = 0; i < menu.size(); ++i) {
            gotoXY(boxX + 2, boxY + 1 + i);
            if (i == selected) {
                setColor(LIGHT_CYAN);
                string line = selector + "  " + menu[i];
                cout << line << string(boxWidth - 4 - menu[i].length(), ' ');
            }
            else {
                setColor(GRAY);
                string line = "   " + menu[i];
                cout << line << string(boxWidth - 4 - menu[i].length(), ' ');
            }
        }

        gotoXY(boxX - 1, boxY + boxHeight + 2);
        setColor(LIGHT_YELLOW);
        cout << "↑↓ 방향키로 이동, Enter로 선택\n";
        setColor(WHITE);
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) selected = (selected - 1 + menu.size()) % menu.size();
            else if (key == 80) selected = (selected + 1) % menu.size();
        }
        else if (key == 13) {
            return selected;
        }

        Sleep(100);
    }
}
void ShowMainMenu::showGameDescription() {
    system("cls");

    setColor(LIGHT_YELLOW);
    cout << "┌────────────────────────────────────────────┐\n";
    cout << "│               📖 게임 설명 📖              │\n";
    cout << "├────────────────────────────────────────────┤\n";

    setColor(WHITE);
    cout << "│ ● 게임 개요                                │\n";
    cout << "│   이 게임은 용사가 모험을 떠나               │\n";
    cout << "│   수많은 적과 싸우며 성장하는                │\n";
    cout << "│   RPG 스타일의 텍스트 게임입니다.             │\n";
    cout << "│                                            │\n";
    cout << "│ ● 조작 방법                                │\n";
    cout << "│   ↑ ↓ 방향키  : 메뉴 이동                    │\n";
    cout << "│   Enter 키    : 선택 및 진행                 │\n";
    cout << "│   ESC 키      : 종료 또는 이전 화면 이동      │\n";
    cout << "│                                            │\n";
    cout << "│ ● 플레이 팁                                │\n";
    cout << "│   - 모험 중 다양한 아이템을 획득할 수 있음    │\n";
    cout << "│   - 전투에서는 전략적인 선택이 중요함        │\n";

    setColor(LIGHT_YELLOW);
    cout << "├────────────────────────────────────────────┤\n";

    setColor(GRAY);
    cout << "│  Press any key to return to the main menu  │\n";
    cout << "└────────────────────────────────────────────┘\n";

    int key =_getch();
}
