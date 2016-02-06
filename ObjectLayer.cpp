#include "ObjectLayer.h"

using namespace std;

ObjectLayer::ObjectLayer(vector<Tileset> tilesets) : Layer(tilesets) {}

void ObjectLayer::Render() {
	for each (Entity * e in entities) {
		e->DrawFrame();
	}
}

void ObjectLayer::Update() {
	for each (Entity * e in entities) {
		e->Update();
	}
}

vector<Entity *> * ObjectLayer::getEntities() {
	return &entities;
}

void ObjectLayer::addEntity(Entity * entity) {
	entities.push_back(entity);
	int gid = entity->params->GetRow();
	Tileset * ts = GetTileset(gid);
	gid--;
	int row = (gid - (ts->firstGridID - 1)) / ts->numColumns;
	entity->params->SetRow(row);
}