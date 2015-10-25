#include "game.h"
#include "TextureManager.h"

//Nom de la clase::Constructor a implementar
Game::Game() {

g_pWindow = 0;
g_pRenderer = 0;
Running = true;
Tancar = true;
};

Game::~Game()
{
};

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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

			if (!TextureManager::Instance()->load("sonic.bmp", "A", g_pRenderer)) {
				return false;
			}
		}
	}
	else
	{
		return false; // sdl could not initialize
	}
};

void Game::EventHandler()
{
	if (SDL_PollEvent(&closeWindows) == 1) {
		if ((closeWindows.type == SDL_QUIT || closeWindows.key.keysym.sym == SDLK_ESCAPE)) {
			Tancar = false;
		}
	}

};

void Game::Clear()
{

	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_Quit();
};

bool Game::IsRunning()
{

	return Tancar;
	return Running;
};

void Game::Render() 
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
	spriteNum = (int)((SDL_GetTicks() / 100) % 6);
	TextureManager::Instance()->drawFrame("A", 300, 200, 104, 151, 0, spriteNum, g_pRenderer, SDL_FLIP_NONE);
};

void Game::Update()
{

	SDL_RenderPresent(g_pRenderer);
};