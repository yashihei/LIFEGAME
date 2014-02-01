#include "Board.h"

#include <DxLib.h>
#include "ConstParam.h"
#include "Input.h"
#include "global.h"
#include "GameManager.h"

Board::Board(GameManager* gm):
gm(gm)
{
	size = ConstParam::SCREEN_WIDTH / WIDTH;
	Init();
}

void Board::Init(void) {
	for (int i = 0; i < HEIGHT; i++) for (int j = 0; j < WIDTH; j++) map[i][j] = false;
}

void Board::Move(void) {//世代の更新
	std::array<std::array<bool, WIDTH>, HEIGHT> nextMap;
	for (int i = 0; i < HEIGHT; i++) for (int j = 0; j < WIDTH; j++) nextMap[i][j] = false;
	//nextMap = map;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int cnt = search(x, y);
			if (map[y][x]) {
				if (cnt == 2 || cnt == 3) nextMap[y][x] = true;
				if (cnt == 1 || cnt >= 4) nextMap[y][x] = false;
			} else {
				if (cnt == 3) nextMap[y][x] = true;
			}
		}
	}

	map = nextMap;
}

void Board::Input(void) {
	int x, y;
	GetMousePoint(&x, &y);

	int px = x / size;
	int py = y / size;

	if (isOut(px, py)) return;//ありぇ

	if (gm->getInput()->isMouseLeftPushed()) {
		map[py][px] = true;
	} else if (gm->getInput()->isMouseRightPushed()) {
		map[py][px] = false;
	}
}

void Board::Draw(void) {
	//良い子のみんなはこんな変数名付けちゃ駄目だよ！
	int rgb1 = GetColor(0, 217, 0);
	int rgb2 = GetColor(30, 30, 30);
	int rgb3 = GetColor(60, 60, 60);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int tx = x * size, ty = y * size;
			if (map[y][x] == true) DrawFillBox(tx, ty, tx + size + 1, ty + size + 1, rgb1);
			//DrawLineBox(tx, ty, tx + size + 1, ty + size + 1, rgb2);
		}
	}

	int t;
	for (int y = 0; y < HEIGHT; y++) {
		if (y % 10 == 0) t = rgb3;
		else t = rgb2;
		DrawLine(0, y * size, ConstParam::SCREEN_WIDTH, y * size, t);
	}
	for (int x = 0; x < WIDTH; x++) {
		if (x % 10 == 0) t = rgb3;
		else t = rgb2;
		DrawLine(x * size, 0, x * size, ConstParam::SCREEN_HEIGHT, t);
	}
}

void Board::set(int x, int y, bool flag) {
	map[y][x] = flag;
}

int Board::search(int x, int y) {
	int cnt=0;
	for (int dy = -1; dy < 2; dy++) {
		for (int dx = -1; dx < 2; dx++) {
			if (dx == 0 && dy == 0) continue;
			if (isOut(x + dx, y + dy)) continue;
			if (map[y + dy][x + dx]) cnt++;
		}
	}
	return cnt;
}

bool Board::isOut(int x, int y) {
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return true;
	return false;
}