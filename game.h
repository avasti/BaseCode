#pragma once
#include "SDL.h"

class Game
{

private:

	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event closeWindows;
	bool Running;
	bool Tancar;
	int spriteNum;

public:

	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void Render();
	void Update();
	void EventHandler();
	void Clear();
	bool IsRunning();


};

