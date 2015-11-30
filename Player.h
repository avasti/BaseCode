#pragma once
#include "GameObject.h"
#include "SDL.h"
#ifndef PLAYER_H
#define PLAYER_H

class Sonic : public GameObject
{
private:
	void stopX(int);
	void stopY(int);
	Vector2D m_lastStop;
	SDL_RendererFlip m_lastTimeOrientation;
public:
	Sonic();
	~Sonic();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void update(int width, int height);
	void incrementAccelerationY();
	void decrementAccelerationY();
	void incrementAccelerationX();
	void decrementAccelerationX();
	void impulseRight();
	void impulseLeft();
	static GameObject * Create() { return new Sonic(); }
};

#endif PLAYER_H