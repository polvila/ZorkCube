#include <iostream>
#include "entity.h"

Entity::Entity(const string& name, const string& description):
	name(name), description(description)
{
	type = ENTITY;
}

Entity::~Entity()
{
}

void Entity::Look() const
{
	cout << name << endl;
	cout << description << endl;
}

void Entity::Update()
{

}