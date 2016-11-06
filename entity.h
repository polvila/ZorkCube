#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ROOM,
	EXIT,
	ITEM,
	PLAYER
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Look() const;
	virtual void Update();

public:
	EntityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> container;
};

#endif //__Entity__