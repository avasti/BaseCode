#pragma once
#include "vector"
#include "GameObject.h"
#include "Player.h"
#include "StaticObjects.h"
#include "Enemy.h"
#include "SDL.h"
#include "InputHandler.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
	virtual std::vector<int> theMiddle(int width, int height) = 0;
};
#endif GAMESTATE_H