#pragma once
#include <iostream>
#include "GameStates.h"

class StateManager
{
	std::string buttonWait = "Wait.png",
				buttonHover = "Hover.png",
				buttonPressed = "Pressed.png";
private:
	std::vector<GameState *> gameStates;
	std::vector<GameState *> gsDelete;
public:
	StateManager(GameState *);

	void PushState(GameState * state);
	void ChangeState(GameState * state);
	void PopState();
	
	~StateManager();

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
};