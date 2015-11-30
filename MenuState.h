#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"

#ifndef MENUSTATE_H
#define MENUSTATE_H

typedef void (*Callback)();

class MenuState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	std::vector<int> m_position;
	std::vector<const char*> m_textureIDList;
	std::vector< Callback > m_callbacks;
};
#endif MENUSTATE_H