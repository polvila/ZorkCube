#include <iostream>
#include "player.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"

World::World()
{
	Room* roomC = new Room("Initial Room", "You are in a cubic white room.", "white");
	Room* roomE = new Room("31'0 41'1' 101'", "You are in a cubic red room.", "red");
	Room* roomA = new Room("3'21 000 101'", "You are in a cubic orange room.", "orange");

	Exit* exitCA = new Exit(
		"north", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel... 3'21 000 101'",
		roomA);

	Exit* exitCE = new Exit(
		"east", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel... 31'0 41'1' 101'",
		roomE);

	Exit* exitEC = new Exit(
		"west",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel... 21'1 000 2'11",
		roomC);
	
	Exit* exitAC = new Exit(
		"south",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel... 21'1 000 2'11",
		roomC);
	
	Item* boots = new Item("Boots", "A few commonly used boots.");

	roomC->Add(exitCA);
	roomC->Add(exitCE);
	roomE->Add(exitEC);
	roomA->Add(exitAC);

	roomC->Add(boots);

	player = new Player("Human", "You do not know how you got here.", roomC);

	this->Add(roomC);
	this->Add(roomE);
	this->Add(roomA);
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