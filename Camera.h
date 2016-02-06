#pragma once

#include "Vector2D.h"
#include "Player.h"

#define TheCam Camera::GetInstance()

class Camera 
{
private:
	Vector2D posicio;
	Camera() {}
	Player * target;
	static Camera * instancia;
	int maxPosition;
public:
	static Camera * GetInstance()
	{
		if (instancia == NULL)
		{
			instancia = new Camera();
		}
		return instancia;
	}

	void SetTarget(Player * thePlayer);
	void SetPosition(const Vector2D * position);
	void SetMaxPosition(int maxPos);
	const Vector2D * GetPosition();
};