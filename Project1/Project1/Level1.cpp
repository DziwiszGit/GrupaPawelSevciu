#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load() 
{
	x = 0.0f;
	y = 300.0f;
	frame = 0;
	sprites = new SpriteSheet(L"test.png", gfx, 64, 64);
}

void Level1::Unload() 
{
	delete sprites;
}

void Level1::Update()
{
	if (temp == 1)
	{
		x += 15.0f;

		if (x >= 800)
		{
			x = 0;
		}
	}
	if (temp == 2)
	{
		x -= 15.0f;

		if (x <= 0)
		{
			x = 750;
		}
	}
	if (temp == 3)
	{
		y -= 150.0f;
		if (y < 100)
		{
			y = 300.0f;
		}
	}
	frame++;
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	sprites->Draw((frame / 10) % 1, x, y);
}

