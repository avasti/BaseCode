#include "Game.h"
#include "StateManager.h"
#include "EntityFactory.h"
#include "AllEntities.hpp"

Game * Game::joc = 0;

Game::Game()
{
	Game::window = 0;
	Game::renderer = 0;
	Game::Running = true;
	Game::takeScreenshot = false;
}

void Game::ToggleFullscreen()
{
	Fullscreen = !Fullscreen;
	if (Fullscreen)
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(window, SDL_WINDOW_BORDERLESS);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	Running = NULL;
	takeScreenshot = NULL;
}

bool Game::Init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	this->width = width;
	this->height = height;
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
	
		if (window != 0) 
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);		
		if (fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
			Fullscreen = true;
		}
		else {
			Fullscreen = false;
		}
	}
	if (window == 0 || renderer == 0)
	{		
		return false;
	}	
	SDL_SetRenderDrawColor(renderer, 51, 153, 153, 255);
	
	int initFlags = IMG_INIT_PNG;
	if (!(IMG_Init(initFlags) & initFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());		
	}
	
	EntityCreator->Register("Button", &Button::Create);
	EntityCreator->Register("Inert", &InertEntity::Create);
	EntityCreator->Register("Player", &Player::Create);
	EntityCreator->Register("Enemy", &Enemy::Create);

	manager = new StateManager(new StateMenu());
	
	return true;
}

bool Game::IsRunning()
{
	return Running;
}

void Game::Clear()
{	
	EntityCreator->~EntityFactory();

	Game::~Game();
}

void Game::EventHandler()
{
	BigHandle->UpdateKeys();
	delta = Tools::GetDeltaTime();
	manager->HandleEvents();
}

void Game::Update()
{
	manager->Update();
	if (takeScreenshot)
	{
		Tools::takeScreenShot(width, height);
		takeScreenshot = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	manager->Render();
	SDL_RenderPresent(renderer);
}

void Game::Close()
{
	Running = false;
}
