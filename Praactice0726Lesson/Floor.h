#pragma once
#include "Actor.h"
#include "Texture.h"

class Floor : public Actor
{
public:
	Floor()
	{
		Shape = ' ';
		SortOrder = 1;
		bCollision = false;
		MyColor = { 10, 220, 10, 255 };
		MyTexture = nullptr;
	};

	Floor(int NewX, int NewY)
	{
		Shape = ' ';
		SortOrder = 1;
		bCollision = false;
		MyColor = { 10, 220, 10, 255 };
		Location.X = NewX;
		Location.Y = NewY;
		MyTexture = new Texture("./data/floor.bmp");
	}

	virtual ~Floor() {};
};