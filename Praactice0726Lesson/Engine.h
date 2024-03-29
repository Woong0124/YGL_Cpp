#pragma once
#include <string>
#include "SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

class World;
class Actor;

class Engine
{
protected:
	Engine();
	static Engine* Instance;

public:
	static Engine* GetInstance();

	virtual ~Engine();

	World* MyWorld;

	void SaveMap(std::string MapFilename);
	void LoadMap(std::string MapFilename);
	void Run();
	void Stop();
	void Input();

	bool bIsRunning = true;

	static bool Compare(Actor* F, Actor* S);

	int KeyCode;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
};

#define GameEngine Engine::GetInstance()