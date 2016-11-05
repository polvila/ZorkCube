#ifndef __Creature__
#define __Creature__

#include "entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	Room* GetRoom() const;

public:


};

#endif //__Creature__