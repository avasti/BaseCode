#include "Game.h"
#include "LoaderParams.h"


Game* Game::s_pInstance = 0;

Game::Game() {
	m_screenWidth = 800;
	m_screenHeight = 800;
	g_pWindow = 0;
	Tancar= true;
	g_pRenderer = 0;
	PlayStates = new PlayState();
	MenuStates = new MenuState();
	GameMachine = new GameStateMachine();
	TheTextureManager = TextureManager::Instance();
	TheInputHandler = InputHandler::Instance();
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

		m_screenWidth = width;
		m_screenHeight = height;
		SDL_GetWindowSize(g_pWindow, &width, &height);
		
		if (g_pWindow != 0) {
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
	return m_screenWidth;
}

int Game::getScreenHeight()
{
	return m_screenHeight;
}

void Game::setflag(bool b){
	Tancar = b;
};

GameStateMachine* Game::getGameStateMachine() {
	return GameMachine;
};

