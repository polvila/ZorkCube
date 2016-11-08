#include <iostream>
#include "player.h"
#include "room.h"
#include "exit.h"
#include "world.h"

World::World()
{
	Room* roomC = new Room("21'1 000 2'11", "You are in a cubic white room.");
	Room* roomE = new Room("31'0 41'1' 101'", "You are in a cubic red room identified with the following numbers:\n---31'0 41'1' 101'---");
	Room* roomA = new Room("3'21 000 101'", "You are in a cubic orange room identified with the following numbers:\n---3'21 000 101'---");

	Exit* exitCA = new Exit(
		"3'21 000 101'", 
		"Tunnel narrow leads to another room, in the middle of the tunnel appear written numbers:\n---3'21 000 101'---",
		roomC, roomA);

	Exit* exitCE = new Exit(
		"31'0 41'1' 101'", 
		"Tunnel narrow leads to another room, in the middle of the tunnel appear written numbers:\n---31'0 41'1' 101'---",
		roomC, roomE);

	Exit* exitEC = new Exit(
		"21'1 000 2'11",
		"Tunnel narrow leads to another room, in the middle of the tunnel appear written numbers:\n---21'1 000 2'11---",
		roomE, roomC);
	
	Exit* exitAC = new Exit(
		"21'1 000 2'11",
		"Tunnel narrow leads to another room, in the middle of the tunnel appear written numbers:\n---21'1 000 2'11---",
		roomA, roomC);

	player = new Player("Human", "You do not know how you got here.");

	entities.push_back(roomC);
	entities.push_back(roomE);
	entities.push_back(roomA);
	entities.push_back(player);

	cout << "You have awakened, you can not remember what has happened or how you got here.\n";
	cout << "----------------\n";
}

World::~World()
{
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}