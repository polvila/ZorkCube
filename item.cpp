#include <iostream>
#include "item.h"

Item::Item(const string& name, const string& description, ItemType item_type) :
	Entity(name, description), item_type(item_type)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::Look() const
{
	cout << "\t" << name << "\n\t" << description << "\n";
}