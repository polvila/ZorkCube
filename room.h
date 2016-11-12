#ifndef __Room__
#define __Room__

#include <vector>
#include "entity.h"

class Exit;

class Room : public Entity
{
public:
	Room(const string& name, const string& description, const string& color);
	~Room();

	void Look() const;
	

public:
	
	const string color;

};

#endif //__Room__