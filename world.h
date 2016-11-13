#ifndef __World__
#define __World__

#include <list>
#include <vector>
#include <map>
#include <time.h>

#define ROOM_CHANGE_FREQUENCY 60.0f
#define ROOM_TRAP_FREQUENCY 15.0f

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
	bool GameLoop();

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