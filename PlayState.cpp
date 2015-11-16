#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"

void PlayState::update() {
	
	player->update(Game::Instance()->getScreenWidth(), Game::Instance()->getScreenHeight());
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
	}

	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE) || InputHandler::Instance()->isExitRequired()) {
		//Game::Instance()->setflag(false);
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		player->incrementAccelerationX();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		player->decrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		player->decrementAccelerationY();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		player->incrementAccelerationY();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		player->impulseLeft();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
		player->impulseRight();
	}
	InputHandler::Instance()->clean();
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++){
		m_gobjects[i]->draw();
	}
};

bool PlayState::onEnter() {
	player = new Player();
	statico = new StaticObjects();
	ParamsPlayer = new LoaderParams(100, 400, 70, 61, "Sonic",  8, 0, 0, 30, 0.1);
	ParamStatico = new LoaderParams(200, 400, 36, 64, "Naruto",  8, 0, 0, 0, 0.1);
	player->load(ParamsPlayer);
	m_gobjects.push_back(player);
	statico->load(ParamStatico);
	m_gobjects.push_back(statico);
	
	if (!TextureManager::Instance()->load("sonic.bmp", "Sonic", Game::Instance()->getRender()) || !TextureManager::Instance()->load("Naruto.bmp", "Naruto", Game::Instance()->getRender())) {
		return false;
	}
	TextureManager::Instance()->setSizeFrames("Sonic", 40, 31);
	TextureManager::Instance()->setSizeFrames("Naruto", 18, 32);
	return true;
};

const std::string PlayState::s_menuID = "Play";

bool PlayState::onExit() {
	m_gobjects.clear();
	InputHandler::Instance()->clean();
	TextureManager::Instance()->clean("Player");
	TextureManager::Instance()->clean("Naruto");
	Game::Instance()->getGameStateMachine()->popState();
	return true;
};

std::string PlayState::getStateID() const {
	return PlayState::s_menuID;
};

std::vector<int> PlayState::theMiddle(int width, int height) {
	m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};

