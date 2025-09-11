#pragma once
#include "Goblin.h"

Goblin::Goblin(string name) : Monster(name) {}
void Goblin::takeDamage(Character* player) {
	Monster::takeDamage(player);
}
void Goblin::printAsciiArt() const {
    cout << "\033[32m"; // 초록색 시작
	cout << u8R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀      ,      ,
     /(.-""-.)\
 |\  \/      \/  /|
 | \ / =.  .= \ / |
 \( \   o\/o   / )/
  \_, '-/  \-' ,_/
    /   \__/   \
    \ \__/\__/ /
  ___\ \|--|/ /___
/`    \      /    `\⠀⠀⠀⠀⠀⠀⠀⠀

)" << endl;
    cout << "\033[0m";  // 색상 리셋
}
