#pragma once
#include "Windows.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "GameManager.h"


class BGM {
private:
	string currentBGM = "";
public:
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
};