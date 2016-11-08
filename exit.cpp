#include <iostream>
#include "exit.h"

Exit::Exit(const string& name, const string& description, Room* origin, Room* destination, bool blocked = false) :
	Entity(name,description)
{
	type = EXIT;
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << name << endl;
	cout << description << endl;
}