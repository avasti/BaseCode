#pragma once
#include "vector"
#include "GameState.h"

#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

class GameStateMachine
{
public:
	void pushState(GameState* PlayState);
	void changeState(GameState* PlayState);
	void popState();
	void update();
	void render();
	void voidAllOldStates();
private:
	std::vector< GameState* > m_gameStates;
	std::vector< GameState* > m_statesToDelete;
};

#endif GAMESTATEMACHINE_H

