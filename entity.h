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
	PLAYER
};

class Entity
{
public:
	Entity(const string& name, const string& description);
	virtual ~Entity();

	virtual string Look() const;
	virtual void Update();

	void Add(Entity* entity);

public:
	EntityType type;
	string name;
	string description;
	list<Entity*> container;
};

#endif //__Entity__