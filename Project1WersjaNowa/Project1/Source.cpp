#include <Windows.h>
#include "Graphics.h"
#include "Level1.h"
#include "GameController.h"
#include "GameLevel.h"
#include "Character.h"
#include "Background.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow)
{
	
	WNDCLASSEX windowclass;
	{
		ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
		windowclass.cbSize = sizeof(WNDCLASSEX);
		windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		windowclass.hInstance = hInstance;
		windowclass.lpfnWndProc = WindowProc;
		windowclass.lpszClassName = L"MainWindow";
		windowclass.style = CS_HREDRAW | CS_VREDRAW;
	}
	RegisterClassEx(&windowclass);

	RECT rect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"DirectX Tute", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowhandle)
	{
		return -1;
	}

	graphics = new Graphics;

	if (!graphics->Init(windowhandle))
	{
		delete graphics;
		return -1;
	}

	GameLevel::Init(graphics);

	ShowWindow(windowhandle, nCmdShow);

	GameController::LoadInitialLevel(new Level1);

	MSG message;
	message.message = WM_NULL;

	Background::Backcolor(graphics);

	while (GetMessage(&message, NULL, 0, 0))
	{
		if (GetKeyState('D') & 0x8000) //A + space ParabolaJump
		{
			if (GetKeyState(0x20) & 0x800)
			{
				Character::SinJump_R(graphics);
				continue;
			}
			Character::Right(graphics);
			continue;
		}
		if (GetKeyState('A') & 0x8000) // D + Space ParabolaJump
		{
			if (GetKeyState(0x20) & 0x800)
			{
				Character::SinJump_L(graphics);
				continue;
			}
			Character::Left(graphics);
			continue;
		}
		if (GetKeyState(0x20) & 0x800) // Normal Jump
		{
			Character::Jump(graphics);
			continue;
		}
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	delete graphics;

	return 1;
}