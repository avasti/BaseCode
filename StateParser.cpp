#include "StateParser.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Game.h"
#include <string>

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<const char *>* pTextureIDs)
{
		TiXmlDocument xmlDoc;
		if (!xmlDoc.LoadFile(stateFile)) {
			printf(">>>>%s\n", xmlDoc.ErrorDesc());
			return false;
		}
		TiXmlElement* pRoot = xmlDoc.RootElement();
		TiXmlElement* pStateRoot = 0;

		for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == stateID)
			{
				pStateRoot = e;
			}
		}

		TiXmlElement* pTextureRoot = 0;
		for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("TEXTURES"))
			{
				pTextureRoot = e;
			}
		}
		parseTextures(pTextureRoot, pTextureIDs);

		TiXmlElement* pObjectRoot = 0;

		for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=
			NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("OBJECTS"))
			{
				pObjectRoot = e;
			}
		}
		parseObjects(pObjectRoot, pObjects);

		return true;
}


void StateParser::parseObjects(TiXmlElement * pStateRoot, std::vector<GameObject*> *pObjects)
{
	int i = 100;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, numSprites, callbackId;
		double speedX, speedY, maxSpeed, friction;

		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		const size_t len = strlen(e->Attribute("textureID"));
		char * textureID = new char[len + 1];
		strncpy(textureID, e->Attribute("textureID"), len);
		textureID[len] = '\0';
		e->Attribute("numSprites", &numSprites);
		e->Attribute("speedX", &speedX);	
		e->Attribute("speedY", &speedY);
		e->Attribute("maxSpeed", &maxSpeed);
		e->Attribute("friction", &friction);
		e->Attribute("callbackId", &callbackId);
		
		GameObject* go = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		if (strcmp(e->Attribute("type"), "BotonMenu") == 0 || strcmp(e->Attribute("type"), "StaticObjects") == 0 ) {
			go->load(new LoaderParams(theMiddle(width, height)[0], theMiddle(width, height)[1] -200 + i, width, height, textureID, numSprites, speedX, speedY, maxSpeed, friction, callbackId));
			i += 100;
		}
		else {
			go->load(new LoaderParams(x, y, width, height, textureID, numSprites, speedX, speedY, maxSpeed, friction, callbackId));
		}
		pObjects->push_back(go);
	}
}

void StateParser::parseTextures(TiXmlElement * pStateRoot, std::vector<const char*>* pTextureIDs)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		const char* filename, *ID;
		int width, height, sizeX, sizeY;

		filename = e->Attribute("filename");
		ID = e->Attribute("ID");
		width = atoi(e->Attribute("width"));
		height = atoi(e->Attribute("height"));
		sizeX = atoi(e->Attribute("sizeX"));
		sizeY = atoi(e->Attribute("sizeY"));

		TextureManager::Instance()->load(filename, ID, Game::Instance()->getRender());
		TextureManager::Instance()->setSizeFrames(ID, sizeX, sizeY);

		pTextureIDs->push_back(ID);
	}
}

std::vector<int> StateParser::theMiddle(int width, int height) {
	std::vector<int> m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};


