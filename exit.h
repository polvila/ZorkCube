#ifndef __Exit__
#define __Exit__

#include "room.h"
#include "entity.h"

enum Direction
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
	UP,
	DOWN
};

class Exit : public Entity
{
public:
	Exit(const string& name, const string& description, Direction direction, Room* destination, bool blocked = false);
	~Exit();

	string Look() const;

public:
	
	Direction direction;
	Room* destination; 
	bool blocked;

};

#endif //__Exit__