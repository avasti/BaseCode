#pragma once
#include "GameObject.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
};

#endif ENEMY_H