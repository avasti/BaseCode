#pragma once
#include <vector>
#include "Tileset.h"
#include "Layer.h"

class Level
{
private:
	friend class LevelParser;	
	std::vector<Tileset> tilesets;
	std::vector<Layer *> layers;
public:
	Level(std::vector<Tileset>, std::vector<Layer *>);
	void Update();
	void Render();

	std::vector<Tileset> * getTilesets()
	{
		return & this->tilesets;
	}

	std::vector<Layer *> * getLayers()
	{
		return &this->layers;
	}
};