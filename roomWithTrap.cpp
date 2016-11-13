#include "roomWithTrap.h"

RoomWithTrap::RoomWithTrap(const string& name, const string& description, const string& color, Trap* trap) :
	Room(name, description, color), trap(trap)
{
	type = ROOM_WITH_TRAP;
}

RoomWithTrap::~RoomWithTrap()
{
}



