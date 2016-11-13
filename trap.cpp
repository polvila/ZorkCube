#include "trap.h"

Trap::Trap(const string& description, int damage) :
	description(description), damage(damage)
{
}

Trap::~Trap()
{
}
