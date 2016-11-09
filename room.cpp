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

string Room::Look() const
{
	string result = "", items = "", exits = "";
	result = 
		name + "\n"
		+ description + "\n"
		+ "Items:\n";
	
	for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
	{
		if ((*it)->type == ITEM)
			items += (*it)->Look();
		if( (*it)->type == EXIT )
			exits += (*it)->Look();
	}

	result += items + "Exits:\n" + exits;
	return result;
}

Exit* Room::GetExit(const string& direction) const
{
	//TODO
	return NULL;
}


