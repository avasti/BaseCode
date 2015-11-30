#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "TextureManager.h"

Game* Game::static_pInstance = 0;

Game::Game() {
	g_pWindow = 0;
	Tancar= true;
	g_pRenderer = 0;
	SWidth = 900;
	SHeight = 800;
	MenuStates = new MenuState();
	GameMachine = new GameStateMachine();
	InputHandler* TheInputHandler;
	TextureManager* TheTextureManager;
	TheTextureManager = TextureManager::Instance();
	TheInputHandler = InputHandler::Instance();
	TheGameObjectFactory = GameObjectFactory::Instance();
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_GetWindowSize(g_pWindow, &width, &height);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		SWidth = width;
		SHeight = height;
		SDL_GetWindowSize(g_pWindow, &width, &height);
		
		if (g_pWindow != 0) {
			TheGameObjectFactory->Register("Sonic", &Sonic::Create);
			TheGameObjectFactory->Register("StaticObjects", &StaticObjects::Create);
			TheGameObjectFactory->Register("BotonMenu", &MenuButton::Create);

			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			GameMachine->pushState(MenuStates);
		}

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	GameMachine->render();
	SDL_RenderPresent(g_pRenderer);
}

void Game::update() {
	GameMachine->update();
}

void Game::handleEvents() {
}

void Game::clean() {
	Tancar = false;
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Tancar;
}

SDL_Renderer* Game::getRender() {
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenWidth()
{
	return SWidth;
}

int Game::getScreenHeight()
{
	return SHeight;
}

void Game::setflag(bool b){
	Tancar = b;
};

GameStateMachine* Game::getGameStateMachine() {
	return GameMachine;
};

