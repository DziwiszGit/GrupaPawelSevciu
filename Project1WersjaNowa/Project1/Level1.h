#pragma once

#include "GameLevel.h"
#include "SpriteSheet.h"

class Level1: public GameLevel
{
	int frame;
	static inline int temp;
	SpriteSheet* sprites;

public:
	static inline float x;
	static inline float y;
	static void change(int i)
	{
		temp = i;
	}
	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
};