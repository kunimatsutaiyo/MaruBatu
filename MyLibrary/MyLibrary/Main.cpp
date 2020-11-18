#include <Windows.h>

#include "Engine/Window.h"
#include "Engine/Engine.h"
#include "Engine/Input.h"
#include "Engine/Graphics.h"
#include "Engine/Texture.h"
#include "Engine/Sound.h"

int APIENTRY WinMain(
	HINSTANCE	hInstance_,		// インスタンスハンドル
	HINSTANCE	hPrevInstance_,	// 旧仕様(NULLが常に入っているので無視)
	LPSTR		lpCmpLine_,		// コマンドライン
	INT			nCmdShow_		// 表示状態
)
{
	Window window;
	Engine engine;
	HWND window_handle = window.MakeWindow(hInstance_, WINDOW_WIDTH, WINDOW_HEIGHT, "ポチポチゲーム");
	engine.InitEngine(hInstance_, window_handle);
	Input* p_input = Input::GetInstance();

	// メインループ
	while (true)
	{
		// メッセージ構造体
		MSG msg;

		// メッセージ受信
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// WM_QUITで終了
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else {
				// メッセージ翻訳
				TranslateMessage(&msg);
				// プロシージャにメッセージ送信
				DispatchMessage(&msg);
			}
		}
		else {
			// Inputの処理 //
			// escキーで終了
			p_input->Update();
			if (p_input->GetKey(KEY_TYPE::ESCAPE_KEY))
			{
				break;
			}

			// game処理

		}
	}

	// エンジン終了
	engine.EndEngine();

	//return msg.wParam;
	return 0;
}