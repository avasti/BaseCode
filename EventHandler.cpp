#include "EventHandler.h"

EventHandler * EventHandler::instance = 0;
EventHandler::EventHandler()
{
	mouse1 = false;
	mouse2 = false;
}
EventHandler::~EventHandler()
{

}

void EventHandler::UpdateKeys()
{
	ClearKeys();
	SDL_Event event;	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			SDL_Scancode scan = event.key.keysym.scancode;
			keys[scan] = DOWN;
		}
		else if (event.type == SDL_KEYUP)
		{
			SDL_Scancode scan = event.key.keysym.scancode;
			keys[scan] = UP;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == 1)
			{
				mouse1 = true;
			}
			else if (event.button.button == 3)
			{
				mouse2 = true;
			}			
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == 1)
			{
				mouse1 = false;
			}
			else if (event.button.button == 3)
			{
				mouse2 = false;
			}
		}
		x = event.button.x;
		y = event.button.y;
	}
}

map<int, int> EventHandler::GetKeyEvents()
{
	return keys;
}

pair<int, int> EventHandler::GetMousePosition()
{
	pair<int, int> pos;
	pos.first = x;
	pos.second = y;
	return pos;
}

pair<bool, bool> EventHandler::GetMouseButtons()
{
	pair<bool, bool> buttons;
	buttons.first = mouse1;
	buttons.second = mouse2;
	return buttons;
}

void EventHandler::ClearKeys()
{
	keys.clear();
}