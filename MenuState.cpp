#include "MenuState.h"
#include "Game.h"
#include "TextureManager.h"
#include "StateParser.h"

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
	StateParser::parseState("assets/myxml.xml", "MENUSTATE", &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); 
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);

	return true;
};

bool MenuState::onExit() {
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDList.size(); i++) {
		TextureManager::Instance()->clean(m_textureIDList[i]);
	}
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

void MenuState::setCallbacks(const std::vector<Callback>& callbacks)
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
