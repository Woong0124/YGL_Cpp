#include "Player.h"
#include "World.h"

void Player::Tick()
{
	ElapsedTime += GameEngine->MyWorld->DeltaSeconds;

	if (GameEngine->MyEvent.type != SDL_KEYDOWN)
	{
		return;
	}

	SDL_Keysym KeyCode = GameEngine->MyEvent.key.keysym;
	PlayerActivity(KeyCode);
	PlayerMove(KeyCode);
}

void Player::Render()
{
	int SpriteWidth = MyTexture->MySurface->w / 5;
	int SpriteHeight = MyTexture->MySurface->h / 5;

	SDL_Rect SourceRect = { SpriteWidth * SpriteIndexX, SpriteHeight * SpriteIndexY, SpriteWidth, SpriteHeight };
	SDL_Rect DestinationRect = { Location.X * Width, Location.Y * Height, Width, Height };
	SDL_RenderCopy(GameEngine->MyRenderer, MyTexture->MyTexture, &SourceRect, &DestinationRect);

	if (ElapsedTime / 100 >= 1)
	{
		++SpriteIndexX;
		ElapsedTime = 0;
	}
	SpriteIndexX %= 5;
}

void Player::PlayerActivity(SDL_Keysym KeyCode)
{
	if (KeyCode.sym == SDLK_ESCAPE)
	{
		GameEngine->Stop();
	}
	else if (KeyCode.sym == SDLK_t)
	{
		GameEngine->SaveMap("level2.txt");
	}
}

void Player::PlayerMove(SDL_Keysym KeyCode)
{
	if (KeyCode.sym == SDLK_w)
	{
		if (CheckCollision(Location.X, Location.Y - 1))
		{
			--Location.Y;
			SpriteIndexY = 2;
		}
	}
	else if (KeyCode.sym == SDLK_s)
	{
		if (CheckCollision(Location.X, Location.Y + 1))
		{
			++Location.Y;
			SpriteIndexY = 3;
		}
	}
	else if (KeyCode.sym == SDLK_a)
	{
		if (CheckCollision(Location.X - 1, Location.Y))
		{
			--Location.X;
			SpriteIndexY = 0;
		}
	}
	else if (KeyCode.sym == SDLK_d)
	{
		if (CheckCollision(Location.X + 1, Location.Y))
		{
			++Location.X;
			SpriteIndexY = 1;
		}
	}
}

bool Player::CheckCollision(int NewX, int NewY)
{
	bool bActorCheckCollision = Actor::CheckCollision(NewX, NewY);

	for (Actor* CurrentActor : GameEngine->MyWorld->ActorList)
	{
		if (CurrentActor->Location.X == NewX &&
			CurrentActor->Location.Y == NewY &&
			CurrentActor->Shape == 'M')
		{
			GameEngine->Stop();
		}
	}
	return bActorCheckCollision;
}
