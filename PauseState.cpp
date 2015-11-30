#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "StateParser.h"

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
};

void PauseState::render()
{	
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool PauseState::onEnter()
{
	StateParser::parseState("assets/myxml.xml", "PAUSESTATE", &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); 
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_menuToMain);
	setCallbacks(m_callbacks);

	return true;
}

bool PauseState::onExit()
{
	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++) {
		TextureManager::Instance()->clean(m_textureIDList[i]);
	}
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

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast< MenuButton* >(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
