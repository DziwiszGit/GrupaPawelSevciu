#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load() 
{
	x = 0.0f;
	y = 300.0f;
	ySpeed = 0.0f;
	sprites = new SpriteSheet(L"test.png", gfx, 64, 64);
	frame = 1;
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

		if (x > 800)
		{
			x = -600;
		}
	}
	if (temp == 2)
	{
		x -= 15.0f;

		if (x < 100)
		{
			x = +600;
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
	/*frame++;*/
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	gfx->DrawCircle(x, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	sprites->Draw(40, x, y);
}

