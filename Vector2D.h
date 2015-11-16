#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D(void);

	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

	Vector2D operator+(const Vector2D& v) const;
	Vector2D& operator+=(const Vector2D& v);
	Vector2D operator*(float scalar) const;
	Vector2D& operator*=(float scalar);
	Vector2D operator-(const Vector2D& v) const;
	Vector2D& operator-=(const Vector2D& v);
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);
	Vector2D& operator=(const Vector2D& v);
	float length();
	Vector2D normalize();

private:
	float m_x;
	float m_y;
};

#endif VECTOR2D_H

