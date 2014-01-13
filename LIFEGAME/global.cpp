#include <Dxlib.h>
#include <string>
#include <sstream>
#include <map>
using namespace std;

const int KEY_NUM = 256;
int keyState[KEY_NUM];
int leftMouseState;
int rightMouseState;

void InputUpdate() {
	char tKeyState[KEY_NUM];
	GetHitKeyStateAll(tKeyState);
	for (int i=0; i<KEY_NUM; i++) {
		if (tKeyState[i] == 0) {
			keyState[i] = 0;
		} else {
			keyState[i]++;
		}
	}

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		leftMouseState++;
	} else {
		leftMouseState = 0;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		rightMouseState++;
	} else {
		rightMouseState = 0;
	}
}

int GetKey(int keyCode) {
	return keyState[keyCode];
}

int GetLeftMouse() {
	return leftMouseState;
}

int GetRightMouse() {
	return rightMouseState;
}

map<string, int> dataTbl;

void Load(string fn, string n) {
	auto pos = fn.find(".");
	auto type = fn.substr(pos+1);//拡張子を取得
	int t = -1;
	if (type == "png" || type == "jpg") {
		t = LoadGraph(fn.c_str());
	} else if (type == "wav" || type == "mp3") {
		t = LoadSoundMem(fn.c_str());
	}
	if (t != -1) {
		dataTbl[n] = t;
	} else {
		printfDx("データないです:%s", fn.c_str());
	}
}

int GetHandle(string n) {
	return dataTbl[n];
}

string IntToString(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}
