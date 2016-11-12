#include <iostream>
#include "room.h"
#include "globals.h"

Room::Room(const string& name, const string& description, const string& color) :
	Entity(name, description), color(color)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{
	cout << name << "\n" << description << "\n";
	if(!container.empty())
	{
		cout << "Items:\n";
		for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
		{
			if ((*it)->type == ITEM)
				(*it)->Look();
		}

		cout << "Exits:\n";
		for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
		{
			if ((*it)->type == EXIT)
				(*it)->Look();
		}
	}
}
