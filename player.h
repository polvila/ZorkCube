#ifndef __Player__
#define __Player__

#include "room.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player(const string& name, const string& description, Room* location);
	~Player();

	string Look();

public:

	Room* location;
	

};

#endif //__Player__