#pragma once

#include <tinyxml2.h>
#include <vector>

#define PATH "assets/xml/"

using namespace std;
using namespace tinyxml2;
class Entity;

class StateParser
{
private:
	static void parseObjects(XMLElement * stateRoot, vector<Entity *> * entities);
	static void parseTextures(XMLElement * stateRoot, vector<string> * textures);
public:
	static bool ParseState(const char * stateFile, string stateID,
		vector<Entity *> * entitats, vector<string> * textures);
};