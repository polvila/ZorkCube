#ifndef __World__
#define __World__

#include <list>
#include <vector>
#include <map>
#include <time.h>

#define TICK_FREQUENCY 60.0f

using namespace std;

class Entity;
class Player;
class Room;

class World
{
public:

	World();
	~World();

	bool Process(vector<string> input);
	void GameLoop();

private:

	void EntryMessage() const;
	void Add(Entity* entity);
	void ChangeRoomsPosition();

	vector<Entity*> entities;
	Player* player;
	vector<Room*> roomsChanges;
	clock_t timer;

};

#endif //__World__