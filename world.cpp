#include <iostream>
#include "player.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"

World::World()
{
	Room* roomC = new Room("21'1 000 2'11", "You are in a cubic white room.");
	Room* roomE = new Room("31'0 41'1' 101'", "You are in a cubic red room identified with the following numbers:\n---31'0 41'1' 101'---");
	Room* roomA = new Room("3'21 000 101'", "You are in a cubic orange room identified with the following numbers:\n---3'21 000 101'---");

	Exit* exitCA = new Exit(
		"3'21 000 101'", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...",
		NORTH,
		roomA);

	Exit* exitCE = new Exit(
		"31'0 41'1' 101'", 
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...",
		EAST,
		roomE);

	Exit* exitEC = new Exit(
		"21'1 000 2'11",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...",
		WEST,
		roomC);
	
	Exit* exitAC = new Exit(
		"21'1 000 2'11",
		"Tunnel narrow leads to another room, nine numbers are written in the middle of the tunnel...",
		SOUTH, 
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
	return "You have awakened, you can not remember what has happened or how you got here.\n----------------\n";
}

void World::Check(string& input)
{
	vector<string> args = Split(input, " ");
	
	if(args.size() == 1)
	{
		if (args[0].compare("look") == 0)
		{
			cout << player->Look();
		}
		
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