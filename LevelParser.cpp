#include "LevelParser.h"
#include "TextureManager.h"
#include "Tools.h"
#include "EntityFactory.h"

using namespace std;
using namespace tinyxml2;

void LevelParser::ParseTilesets(XMLElement * root, vector<Tileset> * tileset)
{
	for (auto e = root->FirstChildElement("tileset"); e != NULL; e = e->NextSiblingElement("tileset"))
	{
		Tileset * ts = new Tileset();
		ts->firstGridID = e->IntAttribute("firstgid");
		ts->margin = e->IntAttribute("margin");
		ts->name = e->Attribute("name");
		ts->spacing = e->IntAttribute("spacing");
		ts->tileHeight = e->IntAttribute("tileheight");
		ts->tileWidth = e->IntAttribute("tilewidth");
		ts->spacing = e->IntAttribute("spaing");
		string file = e->FirstChildElement("image")->Attribute("source");
		ts->numColumns = e->FirstChildElement("image")->IntAttribute("width") / (ts->tileWidth + ts->spacing);
		Manager->Load(file.c_str(), ts->name);
		tileset->push_back(*ts);
	}
}

void LevelParser::ParseTileLayer(XMLElement * root, vector<Layer *> * layers, vector<Tileset> * tilesets, int tileWidth, int tileHeight)
{
	for (auto e = root->FirstChildElement("layer"); e != NULL; e = e->NextSiblingElement("layer"))
	{
		int width = e->IntAttribute("width");
		int height = e->IntAttribute("height");
		string data = e->FirstChildElement("data")->FirstChild()->Value();
		data = Tools::Clear(data);
		data = base64_decode(data);

		uLongf size = width * height * sizeof(int);
		vector<int> ids(size);
		uncompress((Bytef *)&ids[0], &size, (const Bytef *)data.c_str(), data.size());

		vector<vector<int>> layer;
		for (int row = 0; row < width; row++)
		{
			vector<int> fila;
			for (int cell = 0; cell < width; cell++)
			{
				fila.push_back(ids[row * width + cell]);
			}
			layer.push_back(fila);
		}

		TileLayer * tl = new TileLayer(width, height, tileWidth, tileHeight, *tilesets);
		tl->SetTileIDs(layer);
		layers->push_back(tl);
	}
}

void LevelParser::ParseObjectLayer(XMLElement * root, vector<Layer *> * layers, vector<Tileset> * tilesets)
{
	for (auto o = root->FirstChildElement("objectgroup"); o != NULL; o = o->NextSiblingElement("objectlayer")) {
		ObjectLayer * objLayer = new ObjectLayer(*tilesets);
		for (auto e = o->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
		{
			string typeof = e->Attribute("type");
			string id = e->Attribute("name");

			Entity * entity = EntityFactory::GetInstance()->CreateEntity(typeof);
			int x = e->IntAttribute("x");
			int y = 2912 - e->IntAttribute("y");
			int width = e->IntAttribute("width");
			int height = e->IntAttribute("height");
			int gid = e->IntAttribute("gid");

			entity->Load(new EntityParams(id, x, y, width, height, 3, gid));
			entity->gid = gid;
			entity->texture = objLayer->GetTileset(gid)->name;

			objLayer->addEntity(entity);
		}
		layers->push_back(objLayer);
	}
}

Level * LevelParser::ParseLevel(string xml) {	
	XMLDocument doc;
	doc.LoadFile(xml.c_str());
	if (doc.Error()) {
		cout << "Error XML: " << doc.ErrorName() << endl;
	}
	XMLElement * map = doc.FirstChildElement("map");
	int mapWidth = map->IntAttribute("width");
	int mapHeight = map->IntAttribute("height");
	int tileWidth = map->IntAttribute("tilewidth");
	int tileHeight = map->IntAttribute("tileheight");

	vector<Tileset> tilesets;
	vector<Layer *> layers;

	ParseTilesets(map, &tilesets);
	ParseTileLayer(map, &layers, &tilesets, tileWidth, tileHeight);
	ParseObjectLayer(map, &layers, &tilesets);

	Level * lvl = new Level(tilesets, layers);
	return lvl;
}