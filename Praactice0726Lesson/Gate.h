#pragma once
#include "Actor.h"
#include "Texture.h"

class Gate : public Actor
{
public:
	Gate()
	{
		Shape = 'G';
		SortOrder = 2;
		bCollision = false;
		MyColor = { 140, 80, 50, 255 };
		MyTexture = nullptr;
	};

	Gate(int NewX, int NewY)
	{
		Shape = 'G';
		SortOrder = 2;
		bCollision = false;
		MyColor = { 140, 80, 50, 255 };
		Location.X = NewX;
		Location.Y = NewY;
		MyTexture = new Texture("./data/coin.bmp", 255, 255 ,255);
	}

	virtual ~Gate() {};
};