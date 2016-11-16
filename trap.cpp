#include "trap.h"
#include "player.h"
#include <iostream>

Trap::Trap(const string& name, const string& description, int damage) :
	Entity(name, description), damage(damage)
{
	type = TRAP;
}

Trap::~Trap()
{
}

void Trap::MakeDamage(Player* player) const
{
	cout << "\n" << description << "\n\n>";
	player->DecreaseHealth(damage);
}
