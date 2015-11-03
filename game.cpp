#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	g_pWindow = 0;
	Tancar = true;
	g_pRenderer = 0;
	SWidth = 0;
	SHeigth = 0;
	jugador = new Player();
	objeto = new StaticObjects();
	enemigo = new Enemy();
	LoadParam = new LoaderParams(100, 50, 100, 91, "Sonic", 8, 0);
	ParamOb = new LoaderParams(450, 350, 36, 64, "Naruto", 8, 0);
	ParamEv = new LoaderParams(250, 200, 120, 70, "BolaSonic", 3, 0);
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		SDL_GetWindowSize(g_pWindow, &width, &height);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			SWidth = width;
			SHeigth = height;

			enemigo->load(ParamEv);
			m_gobjects.push_back(enemigo);
			
			objeto->load(ParamOb);
			m_gobjects.push_back(objeto);

			jugador->load(LoadParam);
			m_gobjects.push_back(jugador);

		
			if (!TextureManager::Instance()->Load("Sonic.bmp", "Sonic", g_pRenderer) || !TextureManager::Instance()->Load("Naruto.bmp", "Naruto", g_pRenderer) || !TextureManager::Instance()->Load("BolaSonic.bmp", "BolaSonic", g_pRenderer)) {
				return false;
			}
			TextureManager::Instance()->setFrames("Sonic", 40, 31);
			TextureManager::Instance()->setFrames("Naruto", 18, 32);
			TextureManager::Instance()->setFrames("BolaSonic", 26, 18);
		}

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	SDL_RenderClear(g_pRenderer);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->draw();
	}

	SDL_RenderPresent(g_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
	}
}

bool Game::isRunning() {
	return Tancar;
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) == 1) {
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
			Tancar = false;
		}
	}
}

void Game::clean() {
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_RenderClear(g_pRenderer);
	SDL_Quit();
	m_gobjects.clear();
	
}

int Game::getWidth() {
	return SWidth;
};

SDL_Renderer* Game::getRender() {
	return g_pRenderer;
};

int Game::getHeight() {
	return SWidth;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};



