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

	string EntryMessage();
	void Process(string& input);


private:

	void Add(Entity* entity);
	vector<string> Split(string& command, const string& delimiter);

	vector<Entity*> entities;
	Player* player;

};

#endif //__World__