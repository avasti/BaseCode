#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"

#ifndef MENUSTATE_H
#define MENUSTATE_H

class MenuState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	MenuButton* mb;
	MenuButton* mb2;
	std::vector<int> theMiddle(int width, int height);
	std::vector<int> m_position;
	StaticObjects* so;
};
#endif MENUSTATE_H