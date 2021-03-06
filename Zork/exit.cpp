#include <iostream>
#include "exit.h"

Exit::Exit(const string& name, const string& description, Room* destination) :
	Entity(name,description), destination(destination)
{
	type = EXIT;
}

Exit::~Exit()
{
}

bool Exit::Look() const
{
	cout << "\t" << name << "\n\t" << description << " " << destination->name << "\n";
	return true;
}
