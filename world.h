#ifndef __World__
#define __World__

#include <vector>
#include <map>
#include <time.h>

#define ROOM_CHANGE_FREQUENCY 50.0f
#define ROOM_TRAP_FREQUENCY 15.0f
#define HUNGRY_FREQUENCY 60.0f

using namespace std;

class Entity;
class Player;
class Room;

class World
{
public:

	World();
	~World();

	bool Process(vector<string> input) const;
	bool GameLoop();

private:

	void EntryMessage() const;
	void Add(Entity* entity);
	void ChangeRoomsPosition();
	static void ShowHelp();
	static void ShowInfo();

	vector<Entity*> entities;
	Player* player;
	vector<Room*> roomsChanges;
	clock_t changeRoomTimer;
	clock_t hungryTimer;
	clock_t trapTimer;
};

#endif //__World__