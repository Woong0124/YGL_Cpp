#include <iostream>
#include <fstream>
#include <algorithm>
#include "Engine.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Gate.h"
#include "Floor.h"
#include <Windows.h>

Engine* Engine::Instance = nullptr;

Engine::Engine()
{
	MyWorld = nullptr;

	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("Game", 100, 100, 500, 500, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

Engine* Engine::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Engine();
	}
	return Instance;
}

Engine::~Engine()
{
	delete MyWorld;

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void Engine::SaveMap(std::string MapFilename)
{
	std::ofstream OutputFileStream(MapFilename);
	if (!OutputFileStream.is_open())
	{
		return;
	}

	for (int Y = 0; Y < 10; ++Y)
	{
		std::string OutputLine = "          ";
		for (int X = 0; X < 10; ++X)
		{
			for (Actor* CurrentActor : MyWorld->ActorList)
			{
				if (CurrentActor->Location.X == X && CurrentActor->Location.Y == Y)
				{
					//COORD Cur;
					//Cur.X = CurrentActor->Location.X;
					//Cur.Y = CurrentActor->Location.Y;
					//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
					//std::cout << CurrentActor->Shape;

					OutputLine[X] = CurrentActor->Shape;
				}
			}
		}
		OutputFileStream << OutputLine << '\n';
	}
	OutputFileStream.close();
}

void Engine::LoadMap(std::string MapFilename)
{
	MyWorld = new World();

	std::ifstream ReadFileStream;
	ReadFileStream.open(MapFilename);
	if (ReadFileStream.is_open())
	{
		int Y = 0;
		while (!ReadFileStream.eof())
		{
			char Temp[256];
			ReadFileStream.getline(Temp, 256);

			unsigned int X = 0;
			while (X < strlen(Temp))
			{
				if (Temp[X] == '*')
				{
					MyWorld->SpawnActor(new Wall(X, Y));
				}
				else if (Temp[X] == 'P')
				{
					MyWorld->SpawnActor(new Player(X, Y));
				}
				else if (Temp[X] == 'M')
				{
					MyWorld->SpawnActor(new Monster(X, Y));
				}
				else if (Temp[X] == 'G')
				{
					MyWorld->SpawnActor(new Gate(X, Y));
				}
				MyWorld->SpawnActor(new Floor(X, Y));
				++X;
			}
			++Y;
		}
	}
	ReadFileStream.close();

	for (unsigned int i = 0; i < MyWorld->ActorList.size(); ++i)
	{
		for (unsigned int j = i + 1; j < MyWorld->ActorList.size(); ++j)
		{
			if (MyWorld->ActorList[i]->SortOrder > MyWorld->ActorList[j]->SortOrder)
			{
				Actor* Temp = MyWorld->ActorList[i];
				MyWorld->ActorList[i] = MyWorld->ActorList[j];
				MyWorld->ActorList[j] = Temp;
			}
		}
	}

	//std::sort(MyWorld->ActorList.begin(), MyWorld->ActorList.end(), Engine::Compare);
}

void Engine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			Stop();
			break;
		}

		MyWorld->Tick();
		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255);
		SDL_RenderClear(MyRenderer);

		MyWorld->Render();
		SDL_RenderPresent(MyRenderer);
	}
}

void Engine::Stop()
{
	bIsRunning = false;
}

void Engine::Input()
{
	//KeyCode = _getch();
}

bool Engine::Compare(Actor* F, Actor* S)
{
	return F->SortOrder > S->SortOrder;
}
