#include <iostream>
#include "exit.h"
#include "player.h"
#include "globals.h"


Player::Player(const string& name, const string& description, Room* location) :
	Entity(name, description), location(location)
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::Look() const
{
	location->Look();
	cout << "\n";
}

void Player::GoTo(const string& direction)
{	
	bool exitExists = false;
	for (list<Entity*>::const_iterator it = location->container.cbegin(); it != location->container.cend(); it++)
	{
		if( (*it)->type == EXIT )
		{
			Exit* exit = (Exit*)(*it);
			if (GetLowerCase(exit->name) == direction)
			{
				TryToGoThrowThat(exit);
				exitExists = true;
				break;
			}
		}
	}
	if(!exitExists) cout << "This exit is blocked.\n\n";
}

void Player::Take(const string& object)
{
	for (list<Entity*>::iterator it = location->container.begin(); it != location->container.end(); ++it)
	{
		if ((*it)->type == ITEM && GetLowerCase((*it)->name) == object)
		{
			Add(*it);
			cout << "The item " << (*it)->name << " has been added to your inventory.\n\n";
			location->container.remove(*it);
			break;
		}
	}
}

void Player::ShowInventory()
{
	if(container.empty())
		cout << "You are empty handed.\n\n";
	else
	{
		cout << "You are carrying:\n";
		for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
		{
			(*it)->Look();
		}
		cout << "\n";
	}
}

void Player::Drop(const string& object)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (GetLowerCase((*it)->name) == object)
		{
			location->Add(*it);
			cout << "The item " << (*it)->name << " has been dropped into the room.\n\n";
			container.remove(*it);
			break;
		}
	}
}

void Player::TryToGoThrowThat(Exit* exit) 
{
	string answer;
	if(exit->destination->name != "EXIT")
	{
		cout << "This tunnel has some written numbers (" << exit->destination->name << ") and leads to a " << exit->destination->color << " room."
			<< " Are you sure to go through this tunnel? (yes/no)\n\n";

		getline(cin, answer);

		if(answer == "yes")
			ChangePlayerLocationAndLook(exit->destination);
		else
			cout << "You are still in the same room.\n\n";
	}else
		ChangePlayerLocationAndLook(exit->destination);
}

void Player::ChangePlayerLocationAndLook(Room* destination)
{
	this->location = destination;
	this->Look();
}