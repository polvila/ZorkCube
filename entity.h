#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Look() const;

	void	ChangeParentTo(Entity* new_parent);

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif //__Entity__