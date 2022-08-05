#include "Monster.h"
#include "World.h"
#include <random>

void Monster::Tick()
{
	MonsterMove();
}

void Monster::MonsterMove()
{
	ElapsedTime += GameEngine->MyWorld->DeltaSeconds;
	std::random_device Rd;
	std::mt19937 gen(Rd());
	std::uniform_int_distribution<int> dis(0, 3);

	if (ElapsedTime / 300 >= 1)
	{
		ElapsedTime = 0;
		if (dis(gen) == 0)
		{
			if (CheckCollision(Location.X, Location.Y + 1))
			{
				++Location.Y;
			}
		}
		else if (dis(gen) == 1)
		{
			if (CheckCollision(Location.X, Location.Y - 1))
			{
				--Location.Y;
			}
		}
		else if (dis(gen) == 2)
		{
			if (CheckCollision(Location.X + 1, Location.Y))
			{
				++Location.X;
			}
		}
		else if (dis(gen) == 3)
		{
			if (CheckCollision(Location.X - 1, Location.Y))
			{
				--Location.X;
			}
		}
	}
}

bool Monster::CheckCollision(int NewX, int NewY)
{
	bool bActorCheckCollision = Actor::CheckCollision(NewX, NewY);

	for (Actor* CurrentActor : GameEngine->MyWorld->ActorList)
	{
		if (CurrentActor->Location.X == NewX &&
			CurrentActor->Location.Y == NewY &&
			CurrentActor->Shape == 'P')
		{
			GameEngine->Stop();
		}
	}
	return bActorCheckCollision;
}
