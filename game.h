#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "StaticObjects.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameObjectFactory.h"

class Game
{
private:
	Game();
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool Tancar;
	int SWidth;
	int SHeight;
	static Game* static_pInstance;
	GameStateMachine* GameMachine;
	GameState* PlayState;
	GameState* MenuStates;
	GameObjectFactory* TheGameObjectFactory;
public:
	static Game* Instance()
	{
		if (static_pInstance == 0)
		{
			static_pInstance = new Game();
		}
		return static_pInstance;
	}
	~Game();
	
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	SDL_Renderer* getRender();
	int getTicks();
	std::vector<GameObject*> m_gobjects;
	int getScreenWidth();
	int getScreenHeight();
	void setflag(bool b);
	GameStateMachine* getGameStateMachine();
};

#endif
