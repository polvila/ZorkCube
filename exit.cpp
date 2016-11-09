#include <iostream>
#include "exit.h"

Exit::Exit(const string& name, const string& description, Room* destination,  bool blocked) :
	Entity(name,description), destination(destination), blocked(blocked)
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