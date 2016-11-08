#include "player.h"

Player::Player(const string& name, const string& description) :
	Entity(name, description)
{
	type = PLAYER;
}

Player::~Player()
{
}