#pragma once
#include <memory>

class Fps;
class Input;
class Board;
class Data;

class GameManager
{
public:
	enum class State {
		TITLE,
		IN_GAME,
		GAMEOVER,
		PAUSE,
	};

	GameManager(void);
	void Move(void);
	void Draw(void);
	//getter
	Input* getInput() const { return input.get(); }
private:
	State state;
	std::shared_ptr<Fps> fps;
	std::shared_ptr<Input> input;
	std::shared_ptr<Board> board;
	std::shared_ptr<Data> data;

	int cnt;
};
