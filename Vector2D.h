#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Vector2D
{
public:
	Vector2D();
	Vector2D(float, float);
	~Vector2D();

	float X;
	float Y;

	Vector2D operator+(const Vector2D&) const;
	Vector2D& operator+=(const Vector2D&);

	Vector2D operator-() const;
	Vector2D operator-(const Vector2D&) const;
	Vector2D& operator-=(const Vector2D&);

	Vector2D operator*(float);
	Vector2D operator*(const Vector2D&) const;
	Vector2D& operator*=(float);
	Vector2D& operator*=(const Vector2D&);

	Vector2D operator/(float);
	Vector2D& operator/=(float);

	float lenght();
	void normalize();

	std::string toString() {
		stringstream ss;
		ss << "[Vector2D: X: " << X << ", Y:" << Y << "]";
		return ss.str();
	}
};

