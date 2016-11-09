#include "player.h"

Player::Player(const string& name, const string& description, Room* location) :
	Entity(name, description), location(location)
{
	type = PLAYER;
}

Player::~Player()
{
}

string Player::Look()
{
	return location->Look();
}