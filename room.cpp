#include <iostream>
#include "room.h"
#include "exit.h"
#include "globals.h"

Room::Room(const string& name, const string& description, const string& color) :
	Entity(name, description), color(color), nextPosition(nullptr)
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

void Room::GoToNextPosition(vector<Room*> roomsChange)
{
	list<Entity*> nextPositionExits;
	RemoveAllExits();
	GetRoomNextPosition(roomsChange, this);
	nextPosition->PutAll(nextPositionExits);
	container.insert(container.end(), nextPositionExits.begin(), nextPositionExits.end());
	ChangeExitDestinations(roomsChange);
	GetRoomNextPosition(roomsChange, nextPosition);
}

void Room::SaveAllExits()
{
	exitsSaved.clear();
	for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
	{
		if((*it)->type == EXIT)
			exitsSaved.push_back((*it));
	}
}

void Room::SetNextPosition(Room* nextPosition)
{
	this->nextPosition = nextPosition;
}

void Room::RemoveAllExits()
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end();)
	{
		if ((*it)->type == EXIT)
			it = container.erase(it);
		else
			++it;
	}
}

void Room::PutAll(list<Entity*>& myExitsSaved) const
{
	for (list<Entity*>::const_iterator it = exitsSaved.cbegin(); it != exitsSaved.cend(); ++it)
	{
		myExitsSaved.push_back(*it);
	}
}

void Room::ChangeExitDestinations(vector<Room*> roomChanges) const
{
	for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			//Room* room = static_cast<Exit*>(*it)->destination;
			//cout << room->name << "\n";
			static_cast<Exit*>(*it)->destination = GetRoomNextPosition(roomChanges, static_cast<Exit*>(*it)->destination);
			//cout << room->name << "\n\n";
		}
	}
}

Room* Room::GetRoomNextPosition(vector<Room*> roomChanges, Room* destination)
{
	for (int i = 0; i < roomChanges.size() ; i++)
	{
		if (destination == roomChanges[i])
		{
			i = ((i / 3) * 3) + ((i + 2) % 3);
			//cout << destination->name << "\n";
			destination = roomChanges[i];
			//cout << destination->name << "\n\n";
		}
	}
	return destination;
}
