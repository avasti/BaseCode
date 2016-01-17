#pragma once
#include "Entity.h"
#include <iostream>
#include <map>

#define EntityCreator EntityFactory::GetInstance()

using namespace std;

typedef Entity* (*CreateNewEntity)();

class EntityFactory
{
private:
	EntityFactory();
	static EntityFactory * instance;
	map<string, CreateNewEntity> factoryMap;
public:
	virtual ~EntityFactory() {}
	static EntityFactory * GetInstance()
	{
		if (instance == 0)
		{
			instance = new EntityFactory();
		}
		return instance;
	}
	void Register(const string &str, CreateNewEntity creator);
	Entity * CreateEntity(const string &str);
};