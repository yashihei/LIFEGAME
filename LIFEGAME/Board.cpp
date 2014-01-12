#include <DxLib.h>
#include "Board.h"
#include "ConstParam.h"
#include "global.h"

Board::Board(void) {
	for (int i = 0; i < HEIGHT; i++) for (int j = 0; j < WIDTH; j++) map[i][j] = false;
	size = ConstParam::SCREEN_WIDTH / WIDTH;
}

void Board::Init(void) {
}

void Board::Move(void) {
	int x, y;
	if (GetMouse() == 1) {
		GetMousePoint(&x, &y);

		int px = x / size;
		int py = y / size;
		
		map[py][px] = true;
	}

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			//map[y][x] 
		}
	}
}

void Board::Draw(void) {
	//良い子のみんなはこんな変数名付けちゃ駄目だよ！
	int rgb1 = GetColor(0, 217, 0);
	int rgb2 = GetColor(50, 50, 50);
	int rgb3 = GetColor(30, 30, 30);

	//5セルごとに濃い線を
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int tx = x * size, ty = y * size;
			if (map[y][x] == true) DrawFillBox(tx, ty, tx + size + 1, ty + size + 1, rgb1);
			DrawLineBox(tx, ty, tx + size + 1, ty + size + 1, rgb2);
		}
	}
}
