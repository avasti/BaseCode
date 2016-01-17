#pragma once
#include "Entity.h"

class InertEntity : public Entity
{
public:
	InertEntity();
	~InertEntity();
	static Entity * Create() { return new InertEntity(); }
	void Load(EntityParams * params);
	void Draw();
	void DrawFrame();
	void Update();
	void Clear();
};