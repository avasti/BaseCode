#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, const char* textureID, int numSprites, int spriteSpeed) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_num = numSprites;
		if (spriteSpeed > 20) {
			spriteSpeed = 20;
		}
		m_speed = spriteSpeed;
	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	const char* getTextureID() const { return m_textureID; }
	int getNum() const { return m_num; }
	int getSpeed() const { return m_speed; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_num;
	int m_speed;
	const char* m_textureID;
};

#endif LOADERPARAMS_H