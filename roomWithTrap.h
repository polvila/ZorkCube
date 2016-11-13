#pragma once
#include "room.h"
#include "trap.h"

class Trap;

class RoomWithTrap : public Room
{
public:
	RoomWithTrap(const string& name, const string& description, const string& color, Trap* trap);
	~RoomWithTrap();

	Trap* trap;
private:

	

};
