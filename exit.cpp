#include <iostream>
#include "exit.h"

Exit::Exit(const string& name, const string& description, Direction direction, Room* destination,  bool blocked) :
	Entity(name,description), direction(direction), destination(destination), blocked(blocked)
{
	type = EXIT;
}

Exit::~Exit()
{
}

string Exit::Look() const
{
	return "\t" + name + "\n\t" + description + "\n";

}