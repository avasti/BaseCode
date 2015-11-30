#pragma once
#include "GameObject.h"
#ifndef STATICOBJECTS_H
#define STATICOBJECTS_H

class StaticObjects : public GameObject
{
public:
	StaticObjects();
	~StaticObjects();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void drawRotation(int angle);
	static GameObject * Create() { return new StaticObjects(); }
};

#endif STATICOBJECTS_H