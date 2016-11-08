#include <iostream>
#include "room.h"

Room::Room(const string& name, const string& description) :
	Entity(name, description)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{
	cout << name << endl;
	cout << description << endl;
}

Exit* Room::GetExit(const string& direction) const
{
}


