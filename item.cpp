#include <iostream>
#include "item.h"

Item::Item(const string& name, const string& description, ItemType item_type, int percentage) :
	Entity(name, description), item_type(item_type), percentage(percentage)
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