#include "Level.h"

using namespace std;

Level::Level(vector<Tileset> tilesets, vector<Layer *> layers) {
	this->tilesets = tilesets;
	this->layers = layers;
}

void Level::Update() {
	for each (Layer * ly in layers) {
		ly->Update();
	}
}

void Level::Render() {
	for each (Layer * ly in layers) {
		ly->Render();
	}
}