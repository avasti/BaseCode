#include "MenuButton.h"
#include "Game.h"
#include "TextureManager.h"

MenuButton::MenuButton(){};
MenuButton::~MenuButton(){};
void MenuButton::load(const LoaderParams* pParam) {
	m_bReleased = false;
	m_callbackID = pParam->getCallbackID();
	m_width = pParam->getWidth();
	m_height = pParam->getHeight();
	m_position.setX(pParam->getX());
	m_position.setY(pParam->getY());
	m_textureID = pParam->getTextureID();
	m_spriteNum = pParam->getNum();
};

void MenuButton::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, 0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void MenuButton::update() {
	InputHandler::Instance()->update();
	
	pMousePos = InputHandler::Instance()->getMousePosition();
	printf("x: %f - y: %f\n", pMousePos->getX(), pMousePos->getY());

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(0)) {
			m_currentFrame = CLICKED;
			if (m_bReleased) {
				m_bReleased = false;
			}
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0)) {
			if (!m_bReleased && m_currentFrame == CLICKED) { m_callback(); };
			m_bReleased = true;      
			m_currentFrame = MOUSE_OVER; 
		}
	}
	else { 
		m_currentFrame = MOUSE_OUT; 
	}
};

void MenuButton::clean() {
	InputHandler::Instance()->clean();
};

