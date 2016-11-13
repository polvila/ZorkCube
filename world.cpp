#include <iostream>
#include "player.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"
#include "globals.h"
#include "roomWithTrap.h"

World::World()
{
	timer = clock();

	Trap* fire = new Trap("The room is filled with fire. (Damage: -100%)", 100);
	Trap* acid = new Trap("It is raining acid. (Damage: -20%)", 20);
	Trap* poison = new Trap("You are breathing poison. (Damage: -20%)", 20);
	Trap* lasers = new Trap("A grid of lasers has chopped you. (Damage: -100%)", 100);

	Room* roomA = new Room("3'21 000 101'(A)", "You are in a cubic ORANGE room.", "orange");
	Room* roomB = new RoomWithTrap("41'2' 000 21'0(B)", "You are in a cubic GREEN room.", "green", poison);
	Room* roomC = new Room("21'1 000 2'11(C)", "You are in a cubic WHITE room.", "white");
	Room* roomD = new Room("201' 010 2'11(D)", "You are in a cubic ORANGE room.", "orange");
	Room* roomE = new RoomWithTrap("31'0 41'1' 101'(E)", "You are in a cubic RED room.", "red", fire);
	Room* roomF = new Room("1'11 101 21'0(F)", "You are in a cubic ORANGE room.", "orange");
	Room* roomG = new RoomWithTrap("21'0 201' 41'1'(G)", "You are in a cubic GREEN room.", "green", acid);
	Room* roomH = new RoomWithTrap("2'11 31'0 101(H)", "You are in a cubic RED room.", "red", lasers);
	Room* roomI = new Room("101' 1'11 010(I)", "You are in a cubic ORANGE room.", "orange");
	Room* roomEND = new Room("EXIT!", "You have found the exit of the big cube, but you do not have anything to do out there. There is only unlimited human stupidity.\n\nTHE END\n", "white");

	roomA->SetNextPosition(roomB);
	roomB->SetNextPosition(roomC);
	roomC->SetNextPosition(roomA);

	roomD->SetNextPosition(roomE);
	roomE->SetNextPosition(roomF);
	roomF->SetNextPosition(roomD);

	roomG->SetNextPosition(roomH);
	roomH->SetNextPosition(roomI);
	roomI->SetNextPosition(roomG);

	//-----------EXITS ROOM A-------------

	Exit* exitAC = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitAD = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitAI = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);

	roomA->Add(exitAC);
	roomA->Add(exitAD);
	roomA->Add(exitAI);

	//-----------EXITS ROOM B-------------

	Exit* exitBC1 = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitBD = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitBC2 = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitBG = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitBA = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);

	roomB->Add(exitBC1);
	roomB->Add(exitBD);
	roomB->Add(exitBC2);
	roomB->Add(exitBG);
	roomB->Add(exitBA);

	//-----------EXITS ROOM C-------------

	Exit* exitCA = new Exit( "North", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitCE = new Exit( "East", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitCB = new Exit( "Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomC->Add(exitCA);
	roomC->Add(exitCE);
	roomC->Add(exitCB);

	//-----------EXITS ROOM D-------------

	Exit* exitDA = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitDB = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);
	Exit* exitDI = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitDF = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitDC = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);

	roomD->Add(exitDA);
	roomD->Add(exitDB);
	roomD->Add(exitDI);
	roomD->Add(exitDF);
	roomD->Add(exitDC);

	//-----------EXITS ROOM E-------------

	Exit* exitEC = new Exit( "West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitEF = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitED = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);

	roomE->Add(exitEC);
	roomE->Add(exitEF);
	roomE->Add(exitED);

	//-----------EXITS ROOM F-------------

	Exit* exitFG1 = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitFG2 = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitFE1 = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitFE2 = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitFH = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);

	roomF->Add(exitFG1);
	roomF->Add(exitFG2);
	roomF->Add(exitFE1);
	roomF->Add(exitFE2);
	roomF->Add(exitFH);

	//-----------EXITS ROOM G-------------

	Exit* exitGI = new Exit("North",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitGH = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitGF = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitGE = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitGB = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomG->Add(exitGI);
	roomG->Add(exitGH);
	roomG->Add(exitGF);
	roomG->Add(exitGE);
	roomG->Add(exitGB);

	//-----------EXITS ROOM H-------------

	Exit* exitHI = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitHF = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitHG = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitH = new Exit("East",
		"Tunnel narrow leads to the white light, there are no longer written numbers! It is the", roomEND);

	roomH->Add(exitHI);
	roomH->Add(exitHF);
	roomH->Add(exitHG);
	roomH->Add(exitH);

	//-----------EXITS ROOM I-------------

	Exit* exitIH1 = new Exit("Up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitIH2 = new Exit("East",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitIA = new Exit("Down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitID = new Exit("South",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitIB = new Exit("West",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomI->Add(exitIH1);
	roomI->Add(exitIH2);
	roomI->Add(exitIA);
	roomI->Add(exitID);
	roomI->Add(exitIB);
	
	Item* bag = new Item("Bag", "A bag that can contain other items.", CONTAINER);
	Item* cookies = new Item("Cookies", "Some cookies to remove hunger. (-30%)", HUNGRY, 30);
	Item* medicalKit = new Item("Kit", "First-aid kit to heal minor injuries. (+40%)", HEALTH, 40);
	Item* note = new Item("Note", "A note where it says \" 3'==-3 \".");
	roomC->Add(bag);
	roomC->Add(cookies);
	roomC->Add(medicalKit);
	roomC->Add(note);

	player = new Player("Human", "You do not know how you got here.", roomC);

	this->Add(roomA);
	this->Add(roomB);
	this->Add(roomC);
	this->Add(roomD);
	this->Add(roomE);
	this->Add(roomF);
	this->Add(roomG);
	this->Add(roomH);
	this->Add(roomI);
	this->Add(player);

	roomsChanges.push_back(roomA);
	roomsChanges.push_back(roomB);
	roomsChanges.push_back(roomC);
	roomsChanges.push_back(roomD);
	roomsChanges.push_back(roomE);
	roomsChanges.push_back(roomF);
	roomsChanges.push_back(roomG);
	roomsChanges.push_back(roomH);
	roomsChanges.push_back(roomI);

	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		if ((*it)->type == ROOM)
			(static_cast<Room*>(*it))->SaveAllExits();

	EntryMessage();
}

World::~World()
{
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

bool World::Process(vector<string> args)
{	
	if(args.size() == 1)
	{
		if (args[0] == "look" || args[0] == "l")
		{
			player->Look();
			return true;
		}else if(args[0] == "inventory" || args[0] == "i")
		{
			player->ShowInventory();
			return true;
		}else if(args[0] == "diagnose") 
		{
			player->ShowStatus();
			return true;
		}
			
	}else if(args.size() == 2)
	{
		if (args[0] == "goto" && (args[1] == "north" || args[1] == "south" || args[1] == "east" || args[1] == "west" || args[1] == "up" || args[1] == "down"))
		{
			player->GoTo(args[1]);
			return true;
		}else if(args[0] == "take")
		{
			player->Take(args[1]);
			return true;
		}else if(args[0] == "drop")
		{
			player->Drop(args[1]);
			return true;
		}else if (args[0] == "use")
		{
			player->Use(args[1]);
			return true;
		}
		else if (args[0] == "open")
		{
			player->Open(args[1]);
			return true;
		}

	}else if(args.size() == 4)
	{
		if (args[0] == "put" && args[2] == "inside")
		{
			if(player->HasThisItem(args[1]))
				player->PutInside(args[1], args[3]);
			else
				cout << "You do not have the item " << args[1] << " in your inventory.\n\n";
			return true;
		}
	}
	return false;
}

bool World::GameLoop()
{
	clock_t now = clock();

	if ((now - timer) / CLOCKS_PER_SEC > ROOM_CHANGE_FREQUENCY)
	{
		ChangeRoomsPosition();
		timer = now;
	}

	if (player->location->type == ROOM_WITH_TRAP)
	{
		RoomWithTrap* roomWithTrap = static_cast<RoomWithTrap*>(player->location);
		if ((now - timer) / CLOCKS_PER_SEC > ROOM_TRAP_FREQUENCY)
		{
			cout << roomWithTrap->trap->description << "\n\n";
			player->DecreaseHealth(roomWithTrap->trap->damage);
		}
		if (player->health == 0)
		{
			cout << "You are dead.\nGAME OVER!\n\n";
			return false;
		}
	}

	if (player->location->name == "EXIT!")
		return false;

	return true;
}

void World::Add(Entity* entity)
{
	entities.push_back(entity);
}

void World::EntryMessage() const
{
	cout << "You have awakened, you can not remember what has happened or how you got here.\n----------------\n\n";
	player->Look();
}

void World::ChangeRoomsPosition()
{
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		if ((*it)->type == ROOM)
			static_cast<Room*>(*it)->GoToNextPosition(roomsChanges);

	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		if ((*it)->type == ROOM)
			static_cast<Room*>(*it)->SaveAllExits();

	cout << "The room is shaking, it seems that the exits have changed.\n\n";
}
