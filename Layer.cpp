#include "Layer.h"

using namespace std;

Layer::Layer(vector<Tileset> tilesets) {
	this->tilesets = tilesets;
}


Tileset * Layer::GetTileset(int ts)
{
	int f = 0;
	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
		if (tilesets.at(i).firstGridID <= ts)
			f = i;
		else
			break;
	}
	return &tilesets.at(f);
}