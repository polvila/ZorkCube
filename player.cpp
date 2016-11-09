#include <iostream>
#include "exit.h"
#include "player.h"


Player::Player(const string& name, const string& description, Room* location) :
	Entity(name, description), location(location)
{
	type = PLAYER;
}

Player::~Player()
{
}

string Player::Look() const
{
	return location->Look() + "\n";
}

string Player::GoTo(const string& direction)
{	
	for (list<Entity*>::const_iterator it = location->container.cbegin(); it != location->container.cend(); ++it)
	{
		if( (*it)->type == EXIT )
		{
			Exit* exit = (Exit*)(*it);
			if (exit->name == direction)
				return TryToGoThrowThat(exit);
		}
	}
	return string("This exit is blocked.\n\n");
}

string Player::TryToGoThrowThat(Exit* exit) 
{
	if (exit->blocked)
		return string("This exit is blocked.\n\n");
	else
	{
		string answer;
		cout << "This tunnel has some written numbers (" + exit->destination->name + ") and leads to a " + exit->destination->color + " room."
			+ " Are you sure to go through this tunnel? (yes/no)\n\n";
		getline(cin, answer);
		if(answer == "yes")
		{
			this->location = exit->destination;
			return this->Look();
		}
		return string("You are still in the same room.\n\n");
	}
}