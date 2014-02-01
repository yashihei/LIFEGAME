#include "data.h"

#include <DxLib.h>

void Data::load(std::string fn, std::string n) {
	auto pos = fn.find(".");
	auto type = fn.substr(pos+1);//拡張子を取得
	int t = -1;
	if (type == "png" || type == "jpg") {
		t = LoadGraph(fn.c_str());
	} else if (type == "wav" || type == "mp3") {
		t = LoadSoundMem(fn.c_str());
	}
	if (t != -1) {
		dataMap[n] = t;
	} else {
		printfDx("データないです:%s", fn.c_str());
	}
}

int Data::getHandle(std::string n) {
	return dataMap[n];
}

