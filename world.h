#ifndef __World__
#define __World__

#include <list>

using namespace std;

class Entity;

class World
{
public:

	World();
	~World();

private:

	list<Entity*> entities;

};

#endif //__World__