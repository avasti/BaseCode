#include "Vector2D.h"
#include <cmath>

const Vector2D * Vector2D::NULL_VECTOR = new Vector2D();

Vector2D::Vector2D()
{
	X = 0;
	Y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	X = x;
	Y = y;
}

Vector2D::~Vector2D()
{

}

Vector2D Vector2D::operator+(const Vector2D & v2) const
{
	return Vector2D(X + v2.X, Y + v2.Y);
}

Vector2D & Vector2D::operator+=(const Vector2D & v2)
{
	X += v2.X;
	Y += v2.Y;
	return *this;
}

Vector2D Vector2D::operator-() const
{
	return Vector2D(-X, -Y);
}

Vector2D Vector2D::operator-(const Vector2D & v2) const
{
	return Vector2D(X - v2.X, Y - v2.Y);
}

Vector2D & Vector2D::operator-=(const Vector2D & v2)
{
	X -= v2.X;
	Y -= v2.Y;
	return *this;
}

Vector2D Vector2D::operator*(float f)
{
	return Vector2D(X * f, Y * f);
}

Vector2D Vector2D::operator*(const Vector2D & v2) const
{
	return Vector2D(X * v2.X, Y * v2.Y);
}

Vector2D & Vector2D::operator*=(float f)
{
	X *= f;
	Y *= f;
	return *this;
}

Vector2D & Vector2D::operator*=(const Vector2D & v2)
{
	X *= v2.X;
	Y *= v2.Y;
	return *this;
}

Vector2D Vector2D::operator/(float f)
{
	return Vector2D(X / f, Y / f);
}

Vector2D & Vector2D::operator/=(float f)
{
	X /= f;
	Y /= f;
	return *this;
}

float Vector2D::lenght()
{
	return sqrt(pow(X, 2) + pow(Y, 2));
}

void Vector2D::normalize()
{
	*this /= lenght();
}

bool Vector2D::operator<(const Vector2D& vec) const
{
	return (X < vec.X) && (Y < vec.Y);
}

bool Vector2D::operator<=(const Vector2D& vec) const
{
	return (X <= vec.X) && (Y <= vec.Y);
}

bool Vector2D::operator>(const Vector2D& vec) const
{
	return (X > vec.X) && (Y > vec.Y);
}

bool Vector2D::operator>=(const Vector2D& vec) const
{
	return (X >= vec.X) && (Y >= vec.Y);
}

bool Vector2D::operator==(const Vector2D& vec) const
{
	return (X == vec.X) && (Y == vec.Y);
}