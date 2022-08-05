#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"
#include "World.h"

void Actor::Tick()
{
}

void Actor::Render()
{
    //COORD Cur;
    //Cur.X = Location.X;
    //Cur.Y = Location.Y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    //std::cout << Shape;

    //SDL_SetRenderDrawColor(GameEngine->MyRenderer, MyColor.R, MyColor.G, MyColor.B, MyColor.A);
    //SDL_Rect MyRect = { Location.X * Width, Location.Y * Height, Width, Height };
    //SDL_RenderFillRect(GameEngine->MyRenderer, &MyRect);

    SDL_Rect SourceRect = { 0, 0, MyTexture->MySurface->w, MyTexture->MySurface->h };
    SDL_Rect DestinationRect = { Location.X * Width, Location.Y * Height, Width, Height };
    SDL_RenderCopy(GameEngine->MyRenderer, MyTexture->MyTexture, &SourceRect, &DestinationRect);
}

bool Actor::CheckCollision(int NewX, int NewY)
{
    for (Actor* CurrentActor : GameEngine->MyWorld->ActorList)
    {
        if (CurrentActor->bCollision &&
            CurrentActor->Location.X == NewX &&
            CurrentActor->Location.Y == NewY)
        {
            return false;
        }
    }
    return true;
}
