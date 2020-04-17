#include "Background.h"

void Background::Backcolor(Graphics* graphics)
{
	graphics->BeginDraw();

	graphics->ClearScreen(0.0f, 0.0f, 0.5f);

	graphics->EndDraw();
}