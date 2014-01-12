#pragma once
#include <memory>

class Fps;
class Board;

class GameManager
{
	enum class State {
		TITLE,
		IN_GAME,
		GAMEOVER,
		PAUSE,
	};

	State state;
	std::shared_ptr<Fps> fps;
	std::shared_ptr<Board> board;

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
