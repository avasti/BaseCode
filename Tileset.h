#pragma once
#include <iostream>

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int numColumns;
	std::string name;
};