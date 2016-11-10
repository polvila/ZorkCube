#include <iostream>
#include "player.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"

World::World()
{
	Room* roomA = new Room("3'21 000 101'", "You are in a cubic ORANGE room.", "orange");
	Room* roomB = new Room("41'2' 000 21'0", "You are in a cubic GREEN room.", "green");
	Room* roomC = new Room("21'1 000 2'11", "You are in a cubic WHITE room.", "white");
	Room* roomD = new Room("201' 010 2'11", "You are in a cubic ORANGE room.", "orange");
	Room* roomE = new Room("31'0 41'1' 101'", "You are in a cubic RED room.", "red");
	Room* roomF = new Room("1'11 101 21'0", "You are in a cubic ORANGE room.", "orange");
	Room* roomG = new Room("21'0 201' 41'1'", "You are in a cubic GREEN room.", "green");
	Room* roomH = new Room("2'11 31'0 101", "You are in a cubic RED room.", "red");
	Room* roomI = new Room("101' 1'11 010", "You are in a cubic WHITE room.", "white");
	Room* roomEND = new Room("EXIT", "You have found the exit of the big cube, but you do not have anything to do out there. There is only unlimited human stupidity.\nTHE END\n", "white");

	//-----------EXITS ROOM A-------------

	Exit* exitAC = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitAD = new Exit("east",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitAI = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);

	roomA->Add(exitAC);
	roomA->Add(exitAD);
	roomA->Add(exitAI);

	//-----------EXITS ROOM B-------------

	Exit* exitBC1 = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitBD = new Exit("east",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitBC2 = new Exit("down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitBG = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitBA = new Exit("north",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);

	roomB->Add(exitBC1);
	roomB->Add(exitBD);
	roomB->Add(exitBC2);
	roomB->Add(exitBG);
	roomB->Add(exitBA);

	//-----------EXITS ROOM C-------------

	Exit* exitCA = new Exit( "north", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitCE = new Exit( "east", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitCB = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomC->Add(exitCA);
	roomC->Add(exitCE);
	roomC->Add(exitCB);

	//-----------EXITS ROOM D-------------

	Exit* exitDA = new Exit("west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitDB = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);
	Exit* exitDI = new Exit("north",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitDF = new Exit("east",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitDC = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);

	roomD->Add(exitDA);
	roomD->Add(exitDB);
	roomD->Add(exitDI);
	roomD->Add(exitDF);
	roomD->Add(exitDC);

	//-----------EXITS ROOM E-------------

	Exit* exitEC = new Exit( "west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomC);
	Exit* exitEF = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitED = new Exit("north",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);

	roomE->Add(exitEC);
	roomE->Add(exitEF);
	roomE->Add(exitED);

	//-----------EXITS ROOM F-------------

	Exit* exitFG1 = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitFG2 = new Exit("west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitFE1 = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitFE2 = new Exit("down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitFH = new Exit("north",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);

	roomF->Add(exitFG1);
	roomF->Add(exitFG2);
	roomF->Add(exitFE1);
	roomF->Add(exitFE2);
	roomF->Add(exitFH);

	//-----------EXITS ROOM G-------------

	Exit* exitGI = new Exit("north",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitGH = new Exit("east",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitGF = new Exit("down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitGE = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomE);
	Exit* exitGB = new Exit("west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomG->Add(exitGI);
	roomG->Add(exitGH);
	roomG->Add(exitGF);
	roomG->Add(exitGE);
	roomG->Add(exitGB);

	//-----------EXITS ROOM H-------------

	Exit* exitHI = new Exit("down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomI);
	Exit* exitHF = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomF);
	Exit* exitHG = new Exit("west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomG);
	Exit* exitH = new Exit("east",
		"Tunnel narrow leads to the white light, there are no longer written numbers! It is the", roomEND);

	roomH->Add(exitHI);
	roomH->Add(exitHF);
	roomH->Add(exitHG);
	roomH->Add(exitH);

	//-----------EXITS ROOM I-------------

	Exit* exitIH1 = new Exit("up",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitIH2 = new Exit("east",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomH);
	Exit* exitIA = new Exit("down",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomA);
	Exit* exitID = new Exit("south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomD);
	Exit* exitIB = new Exit("west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...", roomB);

	roomI->Add(exitIH1);
	roomI->Add(exitIH2);
	roomI->Add(exitIA);
	roomI->Add(exitID);
	roomI->Add(exitIB);
	
	Item* boots = new Item("Boots", "A few commonly used boots.");
	roomC->Add(boots);

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
	this->Add(roomEND);
	this->Add(player);
}

World::~World()
{
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

void World::Add(Entity* entity)
{
	entities.push_back(entity);
}

string World::EntryMessage()
{
	return "You have awakened, you can not remember what has happened or how you got here.\n----------------\n\n";
}

void World::Process(string& input)
{
	vector<string> args = Split(input, " ");
	
	if(args.size() == 1)
	{
		if (args[0] == "look")
		{
			cout << player->Look();
		}
		
	}else if(args.size() == 2)
	{
		if (args[0] == "goto")
			cout << player->GoTo(args[1]);
	}

	//for (std::vector<string>::const_iterator i = args.begin(); i != args.end(); ++i)
	//	cout << *i << "...";
	//cout << args.size() << endl;
}

vector<string> World::Split(string& command, const string& delimiter)
{
	vector<string> args;
	size_t pos = 0;
	string token;
	while ((pos = command.find(delimiter)) != string::npos) {
		token = command.substr(0, pos);
		if(token != "")
			args.push_back(token);
		command.erase(0, pos + delimiter.length());
	}
	args.push_back(command);
	return args;
}