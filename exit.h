#ifndef __Exit__
#define __Exit__

#include "room.h"
#include "entity.h"

class Exit : public Entity
{
public:
	Exit(const string& name, const string& opposite_name, const string& description, Room* origin, Room* destination, bool blocked = false);
	~Exit();


public:
	bool blocked;

};

#endif //__Exit__