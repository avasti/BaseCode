#pragma once
#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "GameObject.h"

class MenuButton : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	//MenuButton(const LoaderParams* pParams, void(*callback)());
	MenuButton();
	void load(const LoaderParams* pParams);
	~MenuButton();
	void draw();
	void update();
	void clean();
	int getCallbackID() const {return m_callbackID;};
	void setCallback(void(*callback)()) {
		m_callback = callback;
	};
	static GameObject * Create() { return new MenuButton(); }
protected:
	void(*m_callback)();
	int m_callbackID;
	bool m_bReleased;
	const LoaderParams* Params;
	Vector2D* pMousePos;
};
#endif MENUBUTTON_H
