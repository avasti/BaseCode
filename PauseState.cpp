#include "PauseState.h"
#include "Game.h"

void PauseState::update()
{
	angle += 1;
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
};

void PauseState::render()
{	
	bg->drawRotation(angle);
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool PauseState::onEnter()
{
	angle = 0;
	so = new StaticObjects;
	bg = new StaticObjects; 

	if (so == NULL) {
		return false;
	}

	bg->load(new LoaderParams(theMiddle(2000, 1996)[0], theMiddle(2000, 1996)[1], 2000, 1996, "background.bmp", 1, 0, 0, 0, 0));
	if (!TextureManager::Instance()->load("background.bmp", "background.bmp", Game::Instance()->getRender())) {
		return false;
	}
	TextureManager::Instance()->setSizeFrames("background.bmp", 2000, 1996);

	so->load(new LoaderParams(theMiddle(450, 75)[0], theMiddle(450, 75)[1] - 200, 450, 75, "pausa.bmp", 1, 0, 0, 0, 0));
	if(!TextureManager::Instance()->load("pausa.bmp", "pausa.bmp", Game::Instance()->getRender())) {
		return false;
	}
	TextureManager::Instance()->setSizeFrames("pausa.bmp", 250, 40);
	m_gameObjects.push_back(so);

	mb = new MenuButton(new LoaderParams(theMiddle(237, 75)[0], theMiddle(236, 75)[1] - 50, 237, 75, "volver.bmp", 3, 0, 0, 0, 0), s_menuToPlay);
	if (mb == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb);
	mb2 = new MenuButton(new LoaderParams(theMiddle(236, 76)[0], theMiddle(236, 76)[1] + 50, 236, 76, "main.bmp", 3, 0, 0, 0, 0), s_menuToMain);
	if (mb2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb2);

	dummy = new MenuButton(new LoaderParams(0, 0, 0, 0, "background.bmp", 0, 0, 0, 0, 0), s_menuToPlay);
	m_gameObjects.push_back(dummy);
	return true;
}

bool PauseState::onExit()
{
	m_gameObjects.clear();
	mb->clean();
	mb2->clean();
	TextureManager::Instance()->clean("volver.bmp");
	TextureManager::Instance()->clean("main.bmp");
	return true;
}

const std::string PauseState::s_menuID = "Pause";

std::string PauseState::getStateID() const {

	return PauseState::s_menuID;
};

void PauseState::s_menuToMain()
{
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_menuToPlay()
{
	Game::Instance()->getGameStateMachine()->popState();
}

std::vector<int> PauseState::theMiddle(int width, int height) {
	m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};
