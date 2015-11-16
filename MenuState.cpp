#include "MenuState.h"
#include "Game.h"

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
};

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuState::onEnter() {
	so = new StaticObjects;
	if (so == NULL) {
		return false;
	}
	so->load(new LoaderParams(theMiddle(375, 75)[0], theMiddle(375, 75)[1] - 200, 375, 75, "titulo.bmp", 1, 0, 0, 0, 0));
	if (!TextureManager::Instance()->load("titulo.bmp", "titulo.bmp", Game::Instance()->getRender())) {
		return false;
	}
	TextureManager::Instance()->setSizeFrames("pausa.bmp", 250, 50);
	m_gameObjects.push_back(so);
	mb = new MenuButton(new LoaderParams(theMiddle(236, 75)[0], theMiddle(236, 75)[1] - 50, 236, 75, "play.bmp", 3, 0, 0, 0, 0), s_menuToPlay);
	if (mb == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb);
	mb2 = new MenuButton(new LoaderParams(theMiddle(236, 75)[0], theMiddle(236, 75)[1] + 50, 236, 75, "salir.bmp", 3, 0, 0, 0, 0), s_exitFromMenu);
	if (mb2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb2);

	return true;
};

bool MenuState::onExit() {
	m_gameObjects.clear();
	mb->clean();
	mb2->clean();
	so->clean();
	TextureManager::Instance()->clean("play.bmp");
	TextureManager::Instance()->clean("salir.bmp");
	return true;
};

const std::string MenuState::s_menuID = "Menu";

std::string MenuState::getStateID() const{

	return MenuState::s_menuID;
};

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
};

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->voidAllOldStates();
	Game::Instance()->setflag(false);
}; 

std::vector<int> MenuState::theMiddle(int width, int height) {
	m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};
