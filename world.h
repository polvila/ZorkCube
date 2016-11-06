#ifndef __World__
#define __World__

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