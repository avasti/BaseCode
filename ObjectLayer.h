#pragma once
#include <vector>
#include "Layer.h"
#include "Entity.h"
#include "Tileset.h"

class ObjectLayer : public Layer
{
private:
	std::vector<Entity *> entities;
	std::vector<Tileset> tilesets;
public:
	ObjectLayer(std::vector<Tileset> tilesets);

	virtual void Render();
	virtual void Update();

	std::vector<Entity *> * getEntities();
	void addEntity(Entity *);
};