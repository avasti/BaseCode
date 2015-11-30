#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* PlayState) {
	m_gameStates.push_back(PlayState);  
	m_gameStates.back()->onEnter();
};

void GameStateMachine::changeState(GameState* PlayState) {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->getStateID() == PlayState->getStateID()) {
			return;  
		}
		if (m_gameStates.back()->onExit()) {
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back(); 
		}
	}

	m_gameStates.push_back(PlayState);
	m_gameStates.back()->onEnter(); 
};

void GameStateMachine::popState() {
	if (!m_gameStates.empty()) { 
		if (m_gameStates.back()->onExit()) { 
			m_statesToDelete.push_back(m_gameStates.back());    
			m_gameStates.pop_back(); 
		} 
	}
};

void GameStateMachine::update() { 
	if (!m_gameStates.empty()) { 
		m_gameStates.back()->update(); 
	} 
};

void GameStateMachine::render() { 
	if (!m_gameStates.empty()) { 
		m_gameStates.back()->render(); 
	} 
};

void GameStateMachine::voidAllOldStates() {
	m_statesToDelete.clear();
};