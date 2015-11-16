#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"
#include "StaticObjects.h"

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

class PauseState : public GameState
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
	static void s_menuToMain();
	MenuButton* mb;
	MenuButton* mb2;
	MenuButton* dummy;
	StaticObjects* so;
	StaticObjects* bg;
	std::vector<int> theMiddle(int width, int height);
	std::vector<int> m_position;
	int angle;
};
#endif PAUSESTATE_H