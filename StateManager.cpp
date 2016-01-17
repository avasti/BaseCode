#include "StateManager.h"

using namespace std;

StateManager::StateManager(GameState * state)
{	
	PushState(state);
	TextureManager::GetInstance()->Load(buttonWait.c_str(), "Wait");
	TextureManager::GetInstance()->Load(buttonHover.c_str(), "Hover");
	TextureManager::GetInstance()->Load(buttonPressed.c_str(), "Pressed");
}

void StateManager::PushState(GameState * state)
{
	state->OnEnter();
	gameStates.push_back(state);
}

void StateManager::ChangeState(GameState * state)
{
	state->OnEnter();	
	gsDelete = gameStates;
	gameStates.clear();	
	gameStates.push_back(state);
}

void StateManager::PopState()
{	
	gsDelete.push_back(gameStates.back());
	gameStates.pop_back();
}

StateManager::~StateManager()
{
	gameStates.clear();
	gsDelete.clear();
}

void StateManager::HandleEvents()
{
	gameStates.back()->HandleEvents();
}

void StateManager::Update()
{
	gameStates.back()->Update();
}

void StateManager::Render()
{
	gameStates.back()->Render();
	Clean();
}

void StateManager::Clean()
{
	for each (GameState * var in gsDelete)
	{
		var->OnExit();
	}
	gsDelete.clear();
}