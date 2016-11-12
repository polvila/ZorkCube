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
}

void Player::GoTo(const string& direction)
{	
	bool exitExists = false;
	for (list<Entity*>::const_iterator it = location->container.cbegin(); it != location->container.cend(); it++)
	{
		if( (*it)->type == EXIT )
		{
			Exit* exit = (Exit*)(*it);
			if (ToLowerCase(exit->name) == direction)
			{
				TryToGoThrowThat(exit);
				exitExists = true;
				break;
			}
		}
	}
	if(!exitExists) cout << "This exit is blocked.\n\n";
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