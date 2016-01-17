#pragma once
#include "Entity.h"
#include "Vector2D.h"

#define NEGATIVE -1
#define POSITIVE 1
#define NULL 0

class LivingEntity :
	public Entity
{
public:
	Vector2D position, velocity, maxVel, acceleration, friction;	

	LivingEntity();
	~LivingEntity();

	int xAccel = 0, yAccel = 0;
	static LivingEntity * Create() { return new LivingEntity(); }
	void Move(float, float);

	void Accelerate(int, int);

	void Load(EntityParams *);
	void Draw();
	virtual void DrawFrame();
	virtual void Update();
	void Clear();

	std::string GetId() { return params->GetId(); }
	float GetXPos() { return position.X; }
	float GetYPos() { return position.Y; }
	void SetYPos(float yPos) { this->position.Y = yPos; }
	int GetWidth() { return params->GetWidth(); }
	int GetHeight() { return params->GetHeight(); }
	
	bool HaveAnimation() { return params->GetMaxFrame() > 1; }
	int GetFrame() { return params->GetFrame(); }
	int GetRow() { return params->GetRow(); }
};

