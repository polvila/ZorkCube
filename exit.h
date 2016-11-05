#ifndef __Exit__
#define __Exit__

#include "entity.h"

class Exit : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination, bool blocked = false);
	~Exit();

	const string& GetNameFrom(const Room* room) const;
	Room* GetDestinationFrom(const Room* room) const;

public:
	bool blocked;
	string opposite_name;
	Room* destination;
};

#endif //__Exit__