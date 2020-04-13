#include <Windows.h>
#include "Graphics.h"
#include "Level1.h"
#include "GameController.h"

Graphics* graphics;
//Level1* level_test;



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_KEYDOWN:
		{
			switch (wParam) 
			{
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

					for (int i = 0; i < 2; i++)
					{
						GameController::Update();

						graphics->BeginDraw();

						GameController::Render();

						graphics->EndDraw();
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
	//
	///window create
	
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
	///window create
	///
	////////////////////////////////////
	////////////////////////////////////
	////////////////////////////////////
	///

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

			

		}
	}
	/*MSG msssage;
	while (GetMessage(&msssage, NULL, 0, 0))
	{
		
		TranslateMessage(&msssage);
		DispatchMessage(&msssage);
		
	}*/


	delete graphics;

	return 1;
}