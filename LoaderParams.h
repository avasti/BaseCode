#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, const char* textureID, int numSprites, float speedX, float speedY, float maxSpeed, float friction, int callbackId = 0) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_num = numSprites;
		m_speedX = speedX;
		m_speedY = speedY;
		m_maxSpeed = maxSpeed;
		m_friction = friction;
		m_callbackId = callbackId;
	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getCallbackID() const { return m_callbackId; }
	const char* getTextureID() const { return m_textureID; }
	int getNum() const { return m_num; }
	float getSpeedX() const { return m_speedX; }
	float getSpeedY() const { return m_speedY; }
	float getMaxSpeed() const { return m_maxSpeed; }
	float getFrictionCoeficient() const { return m_friction; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_num;
	int m_callbackId;
	float m_speedX;
	float m_speedY;
	float m_maxSpeed;
	float m_friction;
	const char* m_textureID;
};

#endif LOADERPARAMS_H