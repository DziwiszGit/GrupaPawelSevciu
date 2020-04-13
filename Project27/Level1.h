#pragma once

#include "GameLevel.h"
#include "SpriteSheet.h"

class Level1: public GameLevel
{
	float x;
	float y;
	float ySpeed;

	static inline int temp;

	SpriteSheet* sprites;

	int frame;

public:

	static void change(int i)
	{
		temp = i;
	}

	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
};