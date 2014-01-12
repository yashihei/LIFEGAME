#include <DxLib.h>
#include "GameManager.h"
#include "global.h"
#include "Fps.h"
#include "Board.h"

GameManager::GameManager(void) {
	state = State::IN_GAME;//‚Æ‚è‚ ‚¦‚¸‚Í
	fps = std::make_shared<Fps>();
	board = std::make_shared<Board>();
}

void GameManager::Move(void) {
	switch (state) {
	case State::IN_GAME:
		board->Move();
		break;
	case State::PAUSE:
		break;
	}
	fps->Move();
	//fps->Wait();
}

void GameManager::Draw(void) {
	board->Draw();
#ifdef DEBUG
	fps->Draw();
#endif
}
