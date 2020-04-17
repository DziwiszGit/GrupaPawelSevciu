#pragma once

#include "Graphics.h"
#include "SpriteSheet.h"

using namespace std;

class GameLevel
{
protected:
	static inline Graphics* gfx;
public:

	static void Init(Graphics* graphics)
	{
		gfx = graphics;
	}

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};
