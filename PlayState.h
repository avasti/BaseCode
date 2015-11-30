#pragma once
#include "string"
#include "GameState.h"

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

class PlayState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
private:
	static const std::string s_menuID;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	std::vector<GameObject*> m_gobjects;
	std::vector<const char*> m_textureIDList;
};

#endif PLAYSTATE_H
