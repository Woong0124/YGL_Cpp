#pragma once
#include "Actor.h"
#include "Texture.h"

class Wall : public Actor
{
public:
	Wall()
	{
		Shape = '*';
		SortOrder = 2;
		bCollision = true;
		MyColor = { 70, 70, 70 ,255 };
		MyTexture = nullptr;
	};

	Wall(int NewX, int NewY)
	{
		Shape = '*';
		SortOrder = 2;
		bCollision = true;
		MyColor = { 70, 70, 70 ,255 };
		Location.X = NewX;
		Location.Y = NewY;
		MyTexture = new Texture("./data/wall.bmp");
	}

	virtual ~Wall() {};
};