#include "game.h"

//Nom de la clase::Constructor a implementar
Game::Game() {

g_pWindow = 0;
g_pRenderer = 0;
Running = true;
r = 0;
g = 0;
b = 0;

};

Game::~Game()
{
};

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return false; // sdl could not initialize
	}
};

void Game::EventHandler()
{
};

void Game::Clear()
{

	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_Quit();
};

bool Game::IsRunning()
{

	return Running;
};

void Game::Render() 
{

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);
};

void Game::Update()
{

	while (true) {
		if (r < 255) {
			r = r + 1;
		}
		else if (g < 255) {
			g = g + 1;
		}
		else if (b < 255) {
			b = b + 1;
		}

		SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

		SDL_Delay(50);

		SDL_RenderClear(g_pRenderer);

		SDL_RenderPresent(g_pRenderer);
	}
};
