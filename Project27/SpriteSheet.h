#pragma once

//#include <wincodec.h>
//#include "Graphics.h"
//
//class SpriteSheet
//{
//	Graphics* gfx;
//	ID2D1Bitmap* bmp;
//public:
//	SpriteSheet(wchar_t* wpisz, Graphics* gfx);
//	
//	~SpriteSheet();
//
//	void Draw();
//};

#pragma once
#include <wincodec.h>		// decoding image from file
#include "Graphics.h"


class SpriteSheet {
public:
	SpriteSheet(LPCWSTR filename, Graphics* gfx);
	SpriteSheet(LPCWSTR filename, Graphics* gfx, int spriteWidth, int spriteHeight);

	~SpriteSheet();
	//draw bitmap to the render target
	void Draw(int x, int y);
	void Draw(int index, int x, int y);
private:

	Graphics* gfx;
	ID2D1Bitmap* bmp;		//Bitmap loaded file and converted to Direct2D format
	int spriteWidth, spriteHeight;
	int spritesAccross;
};
