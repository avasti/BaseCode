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

	const static Vector2D * NULL_VECTOR;
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

	bool operator<(const Vector2D&) const;
	bool operator>(const Vector2D&) const;
	bool operator<=(const Vector2D&) const;
	bool operator>=(const Vector2D&) const;
	bool operator==(const Vector2D&) const;

	float lenght();
	void normalize();

	std::string toString() {
		stringstream ss;
		ss << "[Vector2D: X: " << X << ", Y:" << Y << "]";
		return ss.str();
	}
};

