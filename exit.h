#ifndef __Exit__
#define __Exit__

#include "room.h"
#include "entity.h"

class Exit : public Entity
{
public:
	Exit(const string& name, const string& description, Room* origin, Room* destination, bool blocked = false);
	~Exit();

	void Look() const;

public:
	
	Room* origin;
	Room* destination; 
	bool blocked;

};

#endif //__Exit__