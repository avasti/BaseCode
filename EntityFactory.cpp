#include "EntityFactory.h"

EntityFactory * EntityFactory::instance = 0;

EntityFactory::EntityFactory() {}

void EntityFactory::Register(const string & name, CreateNewEntity creator)
{
	factoryMap[name] = creator;
}

Entity * EntityFactory::CreateEntity(const string & name)
{
	Entity * ent = factoryMap[name]();
	return ent;
}
