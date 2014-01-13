#pragma once
#include <array>

class Board
{
	static const int WIDTH = 30;
	static const int HEIGHT = 30;
	std::array<std::array<bool, WIDTH>, HEIGHT> map;
	int size;
public:
	Board(void);
	void Init(void);
	void Draw(void);
	void Move(void);
	void Input(void);
private:
	void set(int x, int y, bool flag);//なくすかも
	int search(int x, int y);//指定セルの周りの生存セルをカウント
	bool isOut(int x, int y);
};
