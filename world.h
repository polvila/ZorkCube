#ifndef __World__
#define __World__

#include <list>
#include <vector>

using namespace std;

class Entity;
class Player;

class World
{
public:

	World();
	~World();

	static string EntryMessage();
	bool Process(vector<string> input) const;


private:

	void Add(Entity* entity);

	vector<Entity*> entities;
	Player* player;

};

#endif //__World__