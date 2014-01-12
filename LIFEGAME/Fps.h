#pragma once

class Fps {
	int start;
	int cnt;
	float fps;
	static const int N = 60;
	static const int FPS = 60;
public:
	Fps();
	void Move();
	void Draw();
	void Wait();
};
