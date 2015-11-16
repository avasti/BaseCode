#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : m_callback(callback) {
	MenuButton::Params = pParams;

	m_bReleased = false;
	if (TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender())) {
		TextureManager::Instance()->setSizeFrames(pParams->getTextureID(), pParams->getWidth(), pParams->getHeight());
	}
};

MenuButton::~MenuButton(){};
void MenuButton::load(const LoaderParams* pParam) {};

void MenuButton::draw() {
	TextureManager::Instance()->drawFrame(Params->getTextureID(), Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), 0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void MenuButton::update() {
	InputHandler::Instance()->update();
	
	pMousePos = InputHandler::Instance()->getMousePosition();
	printf("x: %f - y: %f\n", pMousePos->getX(), pMousePos->getY());

	if (pMousePos->getX() < (Params->getX() + Params->getWidth())
		&& pMousePos->getX() > Params->getX()
		&& pMousePos->getY() < (Params->getY() + Params->getHeight())
		&& pMousePos->getY() > Params->getY())
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