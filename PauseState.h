#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"
#include "StaticObjects.h"

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

typedef void(*Callback)();

class PauseState : public GameState
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
	static void s_menuToMain();
	std::vector<int> m_position;
	std::vector< Callback > m_callbacks;
	std::vector<const char*> m_textureIDList;
	int angle;
};
#endif PAUSESTATE_H