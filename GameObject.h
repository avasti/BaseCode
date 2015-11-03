#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;

protected:
	int m_width;
	int m_spriteNum;
	int m_height;
	int m_x;
	int m_y;
	int m_currentFrame;
	int m_currentRow;
	int m_speed;
	const char* m_textureID;
};

#endif GAMEOBJECT_H