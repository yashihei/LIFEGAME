#include "GameManager.h"

#include <DxLib.h>
#include "global.h"
#include "Fps.h"
#include "Board.h"
#include "Input.h"

GameManager::GameManager(void) {
	state = State::PAUSE;//‚Æ‚è‚ ‚¦‚¸‚Í
	fps = std::make_shared<Fps>();
	board = std::make_shared<Board>(this);
	input = std::make_shared<Input>();
	cnt = 0;
}

void GameManager::Move(void) {
	switch (state) {
	case State::IN_GAME:
		if (cnt % 3 == 0) board->Move();
		if (input->isKeyCliked(KEY_INPUT_SPACE)) state = State::PAUSE;
		break;
	case State::PAUSE:
		board->Input();
		if (input->isKeyCliked(KEY_INPUT_SPACE)) state = State::IN_GAME;
		if (input->isKeyCliked(KEY_INPUT_N)) board->Move();//1¢‘ã‚¾‚¯i‚ß‚é
		break;
	}
	if (input->isKeyCliked(KEY_INPUT_R)) board->Init();
	fps->Move();
	input->move();
	//fps->Wait();
	cnt++;
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
