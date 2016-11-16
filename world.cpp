#include <iostream>
#include "player.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"
#include "utils.h"
#include "trap.h"

World::World()
{
	InitializeClocks();

	CreateRooms();
	CreateTraps();
	AssignTraps();
	SetNextPositionsRooms();
	AddExitsToRooms();
	player = new Player("Human", "You do not know how you got here.", static_cast<Room*>(entities.at("roomC")));
	CreateItems();
	AssignItems();
	FillRoomChanges();
	SaveExitsAllRooms();
	FillCommandMaps();

	EntryMessage();
}

World::~World()
{
	for (map<string, Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete it->second;

	entities.clear();
}

bool World::Process(vector<string> args) const
{
	switch (args.size())
	{
	case 1:
		if (commandMap1.find(args[0]) == commandMap1.end())
			return false;
		else
			return (player->*commandMap1.at(args[0]))();
		break;
	case 2:
		if (commandMap2.find(args[0]) == commandMap2.end())
			return false;
		else
			return (player->*commandMap2.at(args[0]))(args[1]);
	case 4:
		if (commandMap3.find(args[0] + args[2]) == commandMap3.end())
			return false;
		else
			return (player->*commandMap3.at(args[0] + args[2]))(args[1], args[3]);
	default:
		return false;
	}
}

void World::GameLoop()
{
	clock_t now = clock();

	TryIfItsTimeToChangeRooms(now);
	TryIfItsTimeToIncreaseHungry(now);
	TryIfItsTimeToActivateTraps(now);
}

bool World::IsOver() const
{
	if (player->HasFoundTheExit() || !player->IsAlive())
		return true;
	return false;
}

void World::EntryMessage() const
{
	cout << "Welcome to ZORKCUBE\n\n";
	cout << "You have awakened, you can not remember what has happened or how you got here.\n----------------\n\n";
	player->Look();
}

void World::ChangeRoomsPosition() const
{
	vector<Entity*> vectorEntities = GetEntities();
	for (vector<Entity*>::const_iterator it = vectorEntities.cbegin(); it != vectorEntities.cend(); ++it)
		if ((*it)->type == ROOM && (*it)->name != "EXIT!")
			static_cast<Room*>(*it)->GoToNextPosition(roomsChanges);

	for (vector<Entity*>::const_iterator it = vectorEntities.cbegin(); it != vectorEntities.cend(); ++it)
		if ((*it)->type == ROOM && (*it)->name != "EXIT!")
			static_cast<Room*>(*it)->SaveAllExits();

	cout << "\nThe room is shaking, it seems that the exits have changed.\n\n>";
}

void World::TryIfItsTimeToChangeRooms(clock_t now)
{
	if ((now - changeRoomTimer) / CLOCKS_PER_SEC > ROOM_CHANGE_FREQUENCY)
	{
		ChangeRoomsPosition();
		changeRoomTimer = now;
	}
}

void World::TryIfItsTimeToIncreaseHungry(clock_t now)
{
	if ((now - hungryTimer) / CLOCKS_PER_SEC > HUNGRY_FREQUENCY)
	{
		player->IncreaseHungry(20);
		hungryTimer = now;
	}
}

void World::TryIfItsTimeToActivateTraps(clock_t now)
{
	if ((now - trapTimer) / CLOCKS_PER_SEC > ROOM_TRAP_FREQUENCY)
	{
		Trap* trap = static_cast<Trap*>(FindAny(player->location->container, TRAP));
		if(trap != nullptr)
			trap->MakeDamage(player);
		trapTimer = now;
	}
}

void World::InitializeClocks()
{
	changeRoomTimer = clock();
	hungryTimer = clock();
	trapTimer = clock();
}

void World::CreateRooms()
{
	entities["roomA"] = new Room("3'21 000 101'", "You are in a cubic ORANGE room.", "orange");
	entities["roomB"] = new Room("41'2' 000 21'0", "You are in a cubic GREEN room.", "green");
	entities["roomC"] = new Room("21'1 000 2'11", "You are in a cubic WHITE room.", "white");
	entities["roomD"] = new Room("201' 010 2'11", "You are in a cubic ORANGE room.", "orange");
	entities["roomE"] = new Room("31'0 41'1' 101'", "You are in a cubic RED room.", "red");
	entities["roomF"] = new Room("1'11 101 21'0", "You are in a cubic ORANGE room.", "orange");
	entities["roomG"] = new Room("21'0 201' 41'1'", "You are in a cubic GREEN room.", "green");
	entities["roomH"] = new Room("2'11 31'0 101", "You are in a cubic RED room.", "red");
	entities["roomI"] = new Room("101' 1'11 010", "You are in a cubic ORANGE room.", "orange");
	entities["roomEND"] = new Room("EXIT!", "You have found the exit of the big cube, but you do not have anything to do out there. There is only unlimited human stupidity.\n\nTHE END\n", "white");
}

void World::CreateTraps()
{
	entities["trapFire"] = new Trap("Fire", "The room is filled with fire. (Damage: -100%)", 100);
	entities["trapAcid"] = new Trap("Acid", "It is raining acid. (Damage: -20%)", 20);
	entities["trapPoison"] = new Trap("Poison", "You are breathing poison. (Damage: -20%)", 20);
	entities["trapLasers"] = new Trap("Lasers", "A grid of lasers has chopped you. (Damage: -100%)", 100);
}

void World::AssignTraps()
{
	entities.at("roomB")->Add(entities.at("trapPoison"));
	entities.at("roomE")->Add(entities.at("trapFire"));
	entities.at("roomG")->Add(entities.at("trapAcid"));
	entities.at("roomH")->Add(entities.at("trapLasers"));
}

void World::SetNextPositionsRooms()
{
	static_cast<Room*>(entities.at("roomA"))->SetNextPosition(static_cast<Room*>(entities.at("roomB")));
	static_cast<Room*>(entities.at("roomB"))->SetNextPosition(static_cast<Room*>(entities.at("roomC")));
	static_cast<Room*>(entities.at("roomC"))->SetNextPosition(static_cast<Room*>(entities.at("roomA")));

	static_cast<Room*>(entities.at("roomD"))->SetNextPosition(static_cast<Room*>(entities.at("roomE")));
	static_cast<Room*>(entities.at("roomE"))->SetNextPosition(static_cast<Room*>(entities.at("roomF")));
	static_cast<Room*>(entities.at("roomF"))->SetNextPosition(static_cast<Room*>(entities.at("roomD")));

	static_cast<Room*>(entities.at("roomG"))->SetNextPosition(static_cast<Room*>(entities.at("roomH")));
	static_cast<Room*>(entities.at("roomH"))->SetNextPosition(static_cast<Room*>(entities.at("roomI")));
	static_cast<Room*>(entities.at("roomI"))->SetNextPosition(static_cast<Room*>(entities.at("roomG")));
}

void World::CreateAndAssignExitsRoomA()
{
	entities["exitAC"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomC")));
	entities["exitAD"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomD")));
	entities["exitAI"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomI")));

	entities.at("roomA")->Add(entities.at("exitAC"));
	entities.at("roomA")->Add(entities.at("exitAD"));
	entities.at("roomA")->Add(entities.at("exitAI"));
}

void World::CreateAndAssignExitsRoomB()
{
	entities["exitBC1"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomC")));
	entities["exitBD"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomD")));
	entities["exitBC2"] = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomC")));
	entities["exitBG"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomG")));
	entities["exitBA"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomA")));

	entities.at("roomB")->Add(entities.at("exitBC1"));
	entities.at("roomB")->Add(entities.at("exitBD"));
	entities.at("roomB")->Add(entities.at("exitBC2"));
	entities.at("roomB")->Add(entities.at("exitBG"));
	entities.at("roomB")->Add(entities.at("exitBA"));
}

void World::CreateAndAssignExitsRoomC()
{
	entities["exitCA"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomA")));
	entities["exitCE"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomE")));
	entities["exitCB"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomB")));

	entities.at("roomC")->Add(entities.at("exitCA"));
	entities.at("roomC")->Add(entities.at("exitCE"));
	entities.at("roomC")->Add(entities.at("exitCB"));
}

void World::CreateAndAssignExitsRoomD()
{
	entities["exitDA"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomA")));
	entities["exitDB"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomB")));
	entities["exitDI"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomI")));
	entities["exitDF"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomF")));
	entities["exitDC"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomC")));

	entities.at("roomD")->Add(entities.at("exitDA"));
	entities.at("roomD")->Add(entities.at("exitDB"));
	entities.at("roomD")->Add(entities.at("exitDI"));
	entities.at("roomD")->Add(entities.at("exitDF"));
	entities.at("roomD")->Add(entities.at("exitDC"));
}

void World::CreateAndAssignExitsRoomE()
{
	entities["exitEC"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomC")));
	entities["exitEF"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomF")));
	entities["exitED"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomD")));

	entities.at("roomE")->Add(entities.at("exitEC"));
	entities.at("roomE")->Add(entities.at("exitEF"));
	entities.at("roomE")->Add(entities.at("exitED"));
}

void World::CreateAndAssignExitsRoomF()
{
	entities["exitFG1"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomG")));
	entities["exitFG2"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomG")));
	entities["exitFE1"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomE")));
	entities["exitFE2"] = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomE")));
	entities["exitFH"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomH")));

	entities.at("roomF")->Add(entities.at("exitFG1"));
	entities.at("roomF")->Add(entities.at("exitFG2"));
	entities.at("roomF")->Add(entities.at("exitFE1"));
	entities.at("roomF")->Add(entities.at("exitFE2"));
	entities.at("roomF")->Add(entities.at("exitFH"));
}

void World::CreateAndAssignExitsRoomG()
{
	entities["exitGI"] = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomI")));
	entities["exitGH"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomH")));
	entities["exitGF"] = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomF")));
	entities["exitGE"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomE")));
	entities["exitGB"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomB")));

	entities.at("roomG")->Add(entities.at("exitGI"));
	entities.at("roomG")->Add(entities.at("exitGH"));
	entities.at("roomG")->Add(entities.at("exitGF"));
	entities.at("roomG")->Add(entities.at("exitGE"));
	entities.at("roomG")->Add(entities.at("exitGB"));
}

void World::CreateAndAssignExitsRoomH()
{
	entities["exitHI"] = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomI")));
	entities["exitHF"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomF")));
	entities["exitHG"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomG")));
	entities["exitHEND"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomEND")));

	entities.at("roomH")->Add(entities.at("exitHI"));
	entities.at("roomH")->Add(entities.at("exitHF"));
	entities.at("roomH")->Add(entities.at("exitHG"));
	entities.at("roomH")->Add(entities.at("exitHEND"));
}

void World::CreateAndAssignExitsRoomI()
{
	entities["exitIH1"] = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomH")));
	entities["exitIH2"] = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomH")));
	entities["exitIA"] = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomA")));
	entities["exitID"] = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomD")));
	entities["exitIB"] = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", static_cast<Room*>(entities.at("roomB")));

	entities.at("roomI")->Add(entities.at("exitIH1"));
	entities.at("roomI")->Add(entities.at("exitIH2"));
	entities.at("roomI")->Add(entities.at("exitIA"));
	entities.at("roomI")->Add(entities.at("exitID"));
	entities.at("roomI")->Add(entities.at("exitIB"));
}

void World::AddExitsToRooms()
{
	CreateAndAssignExitsRoomA();
	CreateAndAssignExitsRoomB();
	CreateAndAssignExitsRoomC();
	CreateAndAssignExitsRoomD();
	CreateAndAssignExitsRoomE();
	CreateAndAssignExitsRoomF();
	CreateAndAssignExitsRoomG();
	CreateAndAssignExitsRoomH();
	CreateAndAssignExitsRoomI();
}

void World::CreateItems()
{
	entities["itemBag"] = new Item("Bag", "A bag that can contain other items.", CONTAINER);
	entities["itemCookies"] = new Item("Cookies", "Some cookies to remove hunger. (-30%)", HUNGRY, 30);
	entities["itemKit"] = new Item("Kit", "First-aid kit to heal minor injuries. (+40%)", HEALTH, 40);
	entities["itemNote"] = new Item("Note", "A note where it says \" 3'==-3 \".");
}

void World::AssignItems()
{
	entities.at("roomC")->Add(entities.at("itemBag"));
	entities.at("roomA")->Add(entities.at("itemCookies"));
	entities.at("roomD")->Add(entities.at("itemKit"));
	entities.at("roomC")->Add(entities.at("itemNote"));
}

void World::FillRoomChanges()
{
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomA")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomB")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomC")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomD")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomE")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomF")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomG")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomH")));
	roomsChanges.push_back(static_cast<Room*>(entities.at("roomI")));
}

void World::SaveExitsAllRooms() const
{
	vector<Entity*> allEntities = GetEntities();
	for (vector<Entity*>::iterator it = allEntities.begin(); it != allEntities.end(); ++it)
		if ((*it)->type == ROOM)
			(static_cast<Room*>(*it))->SaveAllExits();
}

void World::FillCommandMaps()
{
	commandMap1["look"] = &Player::Look;
	commandMap1["l"] = &Player::Look;
	commandMap1["inventory"] = &Player::ShowInventory;
	commandMap1["i"] = &Player::ShowInventory;
	commandMap1["diagnose"] = &Player::ShowStatus;
	commandMap1["help"] = &Player::ShowHelp;
	commandMap1["info"] = &Player::ShowInfo;

	commandMap2["goto"] = &Player::GoTo;
	commandMap2["take"] = &Player::Take;
	commandMap2["drop"] = &Player::Drop;
	commandMap2["use"] = &Player::Use;
	commandMap2["open"] = &Player::Open;

	commandMap3["putinside"] = &Player::PutInside;
}

vector<Entity*> World::GetEntities() const
{
	vector<Entity*> values;
	for (map<string, Entity*>::const_iterator it = entities.cbegin(); it != entities.cend(); ++it) {
		values.push_back(it->second);
	}
	return values;
}
