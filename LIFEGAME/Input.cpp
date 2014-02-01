#include "Input.h"

#include <DxLib.h>

Input::Input() {
	keyState.fill(0);
	leftMouseState = 0;
	rightMouseState = 0;
}

void Input::move()
{
	char tKeyState[KEY_NUM];
	GetHitKeyStateAll(tKeyState);
	for (int i=0; i<KEY_NUM; i++) {
		if (tKeyState[i] == 0) {
			keyState[i] = 0;
		} else {
			keyState[i]++;
		}
	}

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		leftMouseState++;
	} else {
		leftMouseState = 0;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		rightMouseState++;
	} else {
		rightMouseState = 0;
	}
}

bool Input::isKeyCliked(int keyCode)
{
	if (keyState[keyCode] == 1) return true;
	return false;
}

bool Input::isKeyPushed(int keyCode)
{
	if (keyState[keyCode] > 0) return true;
	return false;
}

bool Input::isMouseLeftCliked()
{
	if (leftMouseState == 1) return true;
	return false;
}

bool Input::isMouseLeftPushed()
{
	if (leftMouseState > 0) return true;
	return false;
}

bool Input::isMouseRightClicked()
{
	if (rightMouseState == 1) return true;
	return false;
}

bool Input::isMouseRightPushed()
{
	if (rightMouseState > 0) return true;
	return false;
}
