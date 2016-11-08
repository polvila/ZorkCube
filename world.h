#ifndef __World__
#define __World__

#include <list>
#include <vector>

using namespace std;

class Entity;

class World
{
public:

	World();
	~World();

private:

	vector<Entity*> entities;

};

#endif //__World__