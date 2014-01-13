#include <Dxlib.h>
#include <memory>
#include "global.h"
#include "ConstParam.h"
#include "GameManager.h"
#pragma warning(disable:4996)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ) {
	SetGraphMode(ConstParam::SCREEN_WIDTH, ConstParam::SCREEN_HEIGHT, 32);//画面サイズ任意
	//if (MessageBox(NULL,"フルスクリーンで起動しますか？","起動オプション",MB_YESNO) == IDYES) {
	//	ChangeWindowMode(FALSE);
	//} else {
	//	ChangeWindowMode(TRUE);
	//}

	SetOutApplicationLogValidFlag(FALSE);
	SetMainWindowText("LIFEGAME");
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//フォント読み込み
	const char* font_path = "dat/BMmini.TTF";
	AddFontResourceEx(font_path, FR_PRIVATE, NULL);
	ChangeFont("BM mini", DX_CHARSET_DEFAULT);//多分これしか使わない
	SetFontSize(18);

#ifdef DEBUG
	//デバグ用にコンソール出してやる
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
#endif

	auto gm = std::make_shared<GameManager>();

	while (ProcessMessage() == 0) {
		InputUpdate();

		gm->Move();
		
		ClearDrawScreen();
		gm->Draw();
		ScreenFlip();
		if (GetKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	//RemoveFontResourceEx(font_path, FR_PRIVATE, NULL);
	FreeConsole();
	DxLib_End();
	return 0;
}
