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

string Entity::Look() const
{
	return name + "\n" + description + "\n";
}

void Entity::Update()
{

}

void Entity::Add(Entity* entity)
{
	container.push_back(entity);
}

