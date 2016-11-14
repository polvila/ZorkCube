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
	cout << name + "\n" + description + "\n";
}

void Entity::Add(Entity* entity)
{
	container.push_back(entity);
}

