#ifndef __Exit__
#define __Exit__

#include "room.h"
#include "entity.h"

//enum Direction
//{
//	NORTH,
//	EAST,
//	WEST,
//	SOUTH,
//	UP,
//	DOWN
//};

class Exit : public Entity
{
public:
	Exit(const string& name, const string& description, Room* destination);
	~Exit();

	void Look() const;

public:
	
	Room* destination; 

};

#endif //__Exit__