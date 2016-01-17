#pragma once

#include <tinyxml2.h>
#include "Tileset.h"
#include "Layer.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "Level.h"
#include <iostream>
#include <vector>
#include <zlib.h>
#include "libs\base64\base64.h"

class LevelParser
{
private:	
	static void ParseTilesets(tinyxml2::XMLElement * root, vector<Tileset> * tilesets);
	static void ParseTileLayer(tinyxml2::XMLElement * root, std::vector<Layer *> * layers, std::vector<Tileset> * tilesets, int width, int height);
	static void ParseObjectLayer(tinyxml2::XMLElement * objElement, std::vector<Layer *> * layers, std::vector<Tileset> * tilesets);
public:	
	static Level * ParseLevel(std::string);
};