#include <Windows.h>

#include "Engine/Window.h"
#include "Engine/Engine.h"
#include "Engine/Input.h"
#include "Engine/Graphics.h"
#include "Engine/Texture.h"
#include "Engine/Sound.h"

int APIENTRY WinMain(
	HINSTANCE	hInstance_,		// �C���X�^���X�n���h��
	HINSTANCE	hPrevInstance_,	// ���d�l(NULL����ɓ����Ă���̂Ŗ���)
	LPSTR		lpCmpLine_,		// �R�}���h���C��
	INT			nCmdShow_		// �\�����
)
{
	Window window;
	Engine engine;
	HWND window_handle = window.MakeWindow(hInstance_, WINDOW_WIDTH, WINDOW_HEIGHT, "�|�`�|�`�Q�[��");
	engine.InitEngine(hInstance_, window_handle);
	Input* p_input = Input::GetInstance();

	// ���C�����[�v
	while (true)
	{
		// ���b�Z�[�W�\����
		MSG msg;

		// ���b�Z�[�W��M
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// WM_QUIT�ŏI��
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else {
				// ���b�Z�[�W�|��
				TranslateMessage(&msg);
				// �v���V�[�W���Ƀ��b�Z�[�W���M
				DispatchMessage(&msg);
			}
		}
		else {
			// Input�̏��� //
			// esc�L�[�ŏI��
			p_input->Update();
			if (p_input->GetKey(KEY_TYPE::ESCAPE_KEY))
			{
				break;
			}

			// game����

		}
	}

	// �G���W���I��
	engine.EndEngine();

	//return msg.wParam;
	return 0;
}