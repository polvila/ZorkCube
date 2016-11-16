#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	ROOM_WITH_TRAP,
	EXIT,
	ITEM,
	PLAYER
};

class Entity
{
public:
	Entity(const string& name, const string& description);
	virtual ~Entity();

	virtual bool Look();

	void Add(Entity* entity);

	EntityType type;
	string name;
	string description;
	list<Entity*> container;
};

#endif //__Entity__