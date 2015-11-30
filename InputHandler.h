#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include "Vector2D.h"
#include <vector>

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (static_pInstance == 0)
		{
			static_pInstance = new InputHandler();
		}
		return static_pInstance;
	}
	~InputHandler() {};
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool isExitRequired();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
private:
	InputHandler();
	static InputHandler* static_pInstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	bool m_exitClicked;

};

#endif INPUTHANDLER_H
