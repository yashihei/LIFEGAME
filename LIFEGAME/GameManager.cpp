#include <DxLib.h>
#include "GameManager.h"
#include "global.h"
#include "Fps.h"
#include "Board.h"

GameManager::GameManager(void) {
	state = State::PAUSE;//‚Æ‚è‚ ‚¦‚¸‚Í
	fps = std::make_shared<Fps>();
	board = std::make_shared<Board>();
}

void GameManager::Move(void) {
	switch (state) {
	case State::IN_GAME:
		board->Move();
		if (GetKey(KEY_INPUT_SPACE) == 1) state = State::PAUSE;
		break;
	case State::PAUSE:
		board->Input();
		if (GetKey(KEY_INPUT_SPACE) == 1) state = State::IN_GAME;
		if (GetKey(KEY_INPUT_N) == 1) board->Move();//1¢‘ã‚¾‚¯i‚ß‚é
		break;
	}
	fps->Move();
	if (GetKey(KEY_INPUT_R) == 1) board->Init();
	//fps->Wait();
}

void GameManager::Draw(void) {
	switch(state) {
	case State::IN_GAME:
		board->Draw();
		break;
	case State::PAUSE:
		board->Draw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "STOP");
		break;
	}
#ifdef DEBUG
	fps->Draw();
#endif
}
