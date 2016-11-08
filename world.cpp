#include "world.h"

World::World()
{

}

World::~World()
{
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}