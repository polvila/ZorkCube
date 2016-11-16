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

typedef bool(Player::*DoFunc)(const string& ... );
typedef map<string, DoFunc> CommandMap;

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
	static bool ShowHelp();
	static bool ShowInfo();

	vector<Entity*> entities;
	Player* player;
	vector<Room*> roomsChanges;
	clock_t changeRoomTimer;
	clock_t hungryTimer;
	clock_t trapTimer;
	CommandMap commandMap;
	
};

#endif //__World__