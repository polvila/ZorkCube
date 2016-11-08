#ifndef __Room__
#define __Room__

#include <string>
#include "entity.h"

class Exit;

class Room : public Entity
{
public:
	Room(const string& name, const string& description);
	~Room();

	void Look() const;

	Exit* GetExit(const string& direction) const;
	

public:

};

#endif //__Room__