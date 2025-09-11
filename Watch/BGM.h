#pragma once
#include "Windows.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "GameManager.h"


class BGM {
private:
	string currentBGM;
	//여러 소스파일에서 배경음악을 넣기위해 BGM 객체를 사용할 것이고, 매번 BGM bgm;처럼 객체를 선언하지 않고, 
	//싱글톤 => static 멤버 함수를 통해 단일 객체를 반환한다. 
	static BGM* instance;
	BGM();
	BGM(const BGM&) = delete;
	BGM& operator=(const BGM&) = delete;
public:
	void playBGM(const char* filename, bool loop = true);
	// ================================================
	// 🎵 BGM 중지 함수 (상태 초기화)
	// ================================================
	void stopBGM();
	static BGM* getInstance();
	
};