#pragma once
#include "Actor.h"
#include "Engine.h"
#include "Texture.h"

class Player : public Actor
{
public:
	Player()
	{
		Shape = 'P';
		SortOrder = 3;
		bCollision = false;
		MyColor = { 255, 255, 0 ,255 };
		Location.X = 1;
		Location.Y = 1;
		MyTexture = nullptr;
	};

	Player(int NewX, int NewY)
	{
		Shape = 'P';
		SortOrder = 3;
		bCollision = false;
		MyColor = { 255, 255, 0 ,255 };
		Location.X = NewX;
		Location.Y = NewY;
		MyTexture = new Texture("./data/player.bmp");
	}

	virtual ~Player() {};

	virtual void Tick() override;
	virtual void Render() override;

	void PlayerActivity(SDL_Keysym KeyCode);
	void PlayerMove(SDL_Keysym KeyCode);

	virtual bool CheckCollision(int NewX, int NewY) override;

	int SpriteIndexX = 0;
	int SpriteIndexY = 0;
};