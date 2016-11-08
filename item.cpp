#include <iostream>
#include "item.h"

Item::Item(const string& name, const string& description, ItemType item_type = COMMON) :
	Entity(name, description)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::Look() const
{
	cout << name << endl;
	cout << description << endl;
}