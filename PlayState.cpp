#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"
#include "StateParser.h"
#include "TextureManager.h"

void PlayState::update() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
	}

	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE) || InputHandler::Instance()->isExitRequired()) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	InputHandler::Instance()->clean();
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++){
		m_gobjects[i]->draw();
	}
};

bool PlayState::onEnter() {
	StateParser::parseState("assets/myxml.xml", "PLAYSTATE", &m_gobjects, &m_textureIDList);

	return true;
};

const std::string PlayState::s_menuID = "Play";

bool PlayState::onExit() {
	m_gobjects.clear();
	InputHandler::Instance()->clean();
	for (int i = 0; i < m_textureIDList.size(); i++) {
		TextureManager::Instance()->clean(m_textureIDList[i]);
	}
	Game::Instance()->getGameStateMachine()->popState();
	m_textureIDList.clear();
	return true;
};

std::string PlayState::getStateID() const {
	return PlayState::s_menuID;
};

