#pragma once
#include "GameObject.h"
#ifndef STATICOBJECTS_H
#define STATICOBJECTS_H

class StaticObjects : public GameObject
{
public:
	void load(const LoaderParams* pParams);
	void clean();
	void draw();
	void update();
	StaticObjects();
	~StaticObjects();
};
#endif STATICOBJECTS_H