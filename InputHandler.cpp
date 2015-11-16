#include "InputHandler.h"


InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update()
{
	m_keystates = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.button.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[0] = true;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[1] = true;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[2] = true;
			}
		}
		else if (event.button.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[0] = false;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[1] = false;

			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[2] = false;
			}
		}
		else if (event.button.type == SDL_MOUSEMOTION) {
			m_mousePosition->setX(event.button.x);
			m_mousePosition->setY(event.button.y);
		}
		else if (event.type == SDL_QUIT) {
			m_exitClicked = true;
		}
	}
}

void InputHandler::clean()
{
	m_mouseButtonStates[0] = false;
	m_mouseButtonStates[1] = false;
	m_mouseButtonStates[2] = false;
	m_mousePosition->setX(0);
	m_mousePosition->setY(0);
	m_exitClicked = false;
	m_keystates = NULL;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	return m_keystates[key];
}

bool InputHandler::isExitRequired()
{
	return m_exitClicked;
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}

InputHandler::InputHandler()
{
	m_mouseButtonStates = std::vector<bool>(3, false);
	m_mousePosition = new Vector2D();
	m_mousePosition->setX(0);
	m_mousePosition->setY(0);
	m_exitClicked = false;
	m_keystates = NULL;
}

