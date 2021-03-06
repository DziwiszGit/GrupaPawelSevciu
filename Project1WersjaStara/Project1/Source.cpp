#include <Windows.h>
#include "Graphics.h"
#include "Level1.h"
#include "GameController.h"
#include "GameLevel.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		/*case((VK_LEFT && VK_UP)||(VK_UP&&VK_LEFT)):
		{
			Level1::y = Level1::x + 500.f;
			GameController::Update();

			graphics->BeginDraw();

			GameController::Render();

			graphics->EndDraw();
			break;
		}*/
		case VK_RIGHT:
		{
			Level1::change(1);
			GameController::Update();

			graphics->BeginDraw();

			GameController::Render();

			graphics->EndDraw();

			break;
		}

		case VK_LEFT:
		{

			Level1::change(2);

			GameController::Update();

			graphics->BeginDraw();

			GameController::Render();

			graphics->EndDraw();


			break;
		}

		case VK_UP:
		{
			Level1::change(3);

			while(Level1::y!=150)
			{

				Level1::y -= 10;
			
				graphics->BeginDraw();

				GameController::Render();

				graphics->EndDraw();

			}
			if (Level1::y == 150)
			{
				while (Level1::y != 300)
				{
					Level1::y += 10;

					graphics->BeginDraw();

					GameController::Render();

					graphics->EndDraw();
				}
			}
			
			break;
		}
		case 0x5A:
		{
			Level1::change(3);

			while (Level1::y != 150)
			{

				Level1::y -= 10;
				if (VK_RIGHT)
				{
					Level1::x -= 15.0f;

					if (Level1::x >= 800)
					{
						Level1::x = 0;
					}
				}
				graphics->BeginDraw();

				GameController::Render();

				graphics->EndDraw();

			}
			if (Level1::y == 150)
			{
				while (Level1::y != 300)
				{
					Level1::y += 10;

					graphics->BeginDraw();

					GameController::Render();

					graphics->EndDraw();
				}
			}

			break;
		}
		case 0x58:
		{
			Level1::change(3);

			while (Level1::y != 150)
			{

				Level1::y -= 10;
				if (VK_RIGHT)
				{
					Level1::x += 15.0f;

					if (Level1::x >= 800)
					{
						Level1::x = 0;
					}
				}
				graphics->BeginDraw();

				GameController::Render();

				graphics->EndDraw();

			}
			if (Level1::y == 150)
			{
				while (Level1::y != 300)
				{
					Level1::y += 10;

					graphics->BeginDraw();

					GameController::Render();

					graphics->EndDraw();
				}
			}

			break;
		}
		
		}
	}
	}
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

	graphics->BeginDraw();

	graphics->ClearScreen(0.0f, 0.0f, 0.5f);

	graphics->EndDraw();

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&message);
		}
		else
		{
			//cos
		}
	}

	//while (GetMessage(&msssage, NULL, 0, 0))
	//{
	//	
	//	TranslateMessage(&msssage);
	//	DispatchMessage(&msssage);
	//	
	//}

	delete graphics;

	return 1;
}