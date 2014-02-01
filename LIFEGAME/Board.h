#pragma once
#include <array>

class GameManager;

class Board
{
public:
	static const int WIDTH = 50;
	static const int HEIGHT = 50;
	Board(GameManager* gm);
	void Init(void);
	void Draw(void);
	void Move(void);
	void Input(void);
private:
	GameManager* gm;
	std::array<std::array<bool, WIDTH>, HEIGHT> map;
	int size;

	void set(int x, int y, bool flag);//なくすかも
	int search(int x, int y);//指定セルの周りの生存セルをカウント
	bool isOut(int x, int y);
};
