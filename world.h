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

//template<class T>
//typedef bool(Player::*DoFunc1)();
//typedef map<string, *DoFunc1> CommandMap1;

//typedef bool(Player::*DoFunc2)(const string&);
//template<typename T>
//typedef map<string, bool(T::*)(const string&)> CommandMap2;

//typedef bool(Player::*DoFunc3)(const string&, const string&);
//template<typename T>
//typedef map<string, bool(T::*)(const string&, const string&)> CommandMap3;


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
	void CreateItems();
	void AssignItems();
	void FillRoomChanges();
	void SaveExitsAllRooms() const;
	void FillCommandMaps();
	vector<Entity*> GetEntities() const;


	map<string, Entity*> entities;
	//vector<Entity*> entities;
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