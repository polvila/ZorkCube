#ifndef __Player__
#define __Player__

#include "room.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player(const string& name, const string& description, Room* room);
	~Player();

public:

};

#endif //__Player__