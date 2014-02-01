#pragma once
#include <array>

class Input {
public:
	static const int KEY_NUM = 256;
	Input();
	void move();
	bool isKeyCliked(int keyCode);
	bool isKeyPushed(int keyCode);
	
	//‚Ü‚Æ‚ß‚½‚¢
	bool isMouseLeftCliked();
	bool isMouseLeftPushed();
	bool isMouseRightClicked();
	bool isMouseRightPushed();
private:
	std::array<int, KEY_NUM> keyState;
	int leftMouseState;
	int rightMouseState;
};
