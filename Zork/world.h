#ifndef __World__
#define __World__

#include <vector>
#include <map>
#include <time.h>
#include <functional>

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
	void GameLoop();
	bool IsOver() const;

private:

	void EntryMessage() const;
	void ChangeRoomsPosition() const;
	void TryIfItsTimeToChangeRooms(clock_t now);
	void TryIfItsTimeToIncreaseHungry(clock_t now);
	void TryIfItsTimeToActivateTraps(clock_t now);
	void InitializeClocks();
	void CreateRooms();
	void CreateTraps();
	void AssignTraps();
	void SetNextPositionsRooms();
	void CreateAndAssignExitsRoomA();
	void CreateAndAssignExitsRoomB();
	void CreateAndAssignExitsRoomC();
	void CreateAndAssignExitsRoomD();
	void CreateAndAssignExitsRoomE();
	void CreateAndAssignExitsRoomF();
	void CreateAndAssignExitsRoomG();
	void CreateAndAssignExitsRoomH();
	void CreateAndAssignExitsRoomI();
	void AddExitsToRooms();
	void CreatePlayer();
	void CreateItems();
	void AssignItems();
	void FillRoomChanges();
	void SaveExitsAllRooms() const;
	void FillCommandMaps();
	vector<Entity*> GetEntities() const;

	map<string, Entity*> entities;
	Player* player;
	vector<Room*> roomsChanges;
	clock_t changeRoomTimer;
	clock_t hungryTimer;
	clock_t trapTimer;
	
	map<string, bool(Player::*)() const> commandMap1;
	map<string, bool(Player::*)(const string&)> commandMap2;
	map<string, bool(Player::*)(const string&, const string&)> commandMap3;
};

#endif //__World__