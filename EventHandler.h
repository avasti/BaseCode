#pragma once
#include <iostream>
#include <map>
#include <SDL.h>
#include <string>
#include "Tools.h"

#define UP 1
#define DOWN -1
#define NULL 0

#define BigHandle EventHandler::GetInstance()

using namespace std;

class EventHandler
{
private:
	EventHandler();
	static EventHandler * instance;
	map<int, int> keys;
	int x, y;
	bool mouse1, mouse2;
public:
	~EventHandler();
	static EventHandler * GetInstance()
	{
		if (instance == NULL)
		{
			instance = new EventHandler();
		}
		return instance;
	}

	void UpdateKeys();
	map<int, int> GetKeyEvents();
	pair<int, int> GetMousePosition();
	pair<bool, bool> GetMouseButtons();
	void ClearKeys();
};