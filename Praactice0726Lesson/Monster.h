#pragma once
#include "Actor.h"
#include "Engine.h"
#include "Texture.h"

class Monster : public Actor
{
public:
	Monster()
	{
		Shape = 'M';
		SortOrder = 2;
		bCollision = false;
		MyColor = { 250, 10, 10, 255 };
		Location.X = 5;
		Location.Y = 5;
		MyTexture = nullptr;
	};

	Monster(int NewX, int NewY)
	{
		Shape = 'M';
		SortOrder = 2;
		bCollision = false;
		MyColor = { 250, 10, 10, 255 };
		Location.X = NewX;
		Location.Y = NewY;
		MyTexture = new Texture("./data/slime.bmp", 255, 255, 255);
	}

	virtual ~Monster() {};

	virtual void Tick() override;

	void MonsterMove();

	virtual bool CheckCollision(int NewX, int NewY) override;
};