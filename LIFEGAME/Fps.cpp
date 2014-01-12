#include "Fps.h"
#include <DxLib.h>
#include <math.h>

Fps::Fps() {
	start = 0;
	cnt = 0;
	fps = 0;
}

void Fps::Move() {
	if (cnt == 0) {
		start = GetNowCount();
	}
	if (cnt == N) {
		int end = GetNowCount();
		fps = 1000.f / ((end - start) / (float)N);
		cnt = 0;
		start = end;
	}
	cnt++;
}

void Fps::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
}

void Fps::Wait() {
	int took = GetNowCount() - start;
	int wait = cnt * 1000 / FPS - took;
	if (wait > 0) Sleep(wait);
}
