#ifndef __Room__
#define __Room__

#include <string>
#include <vector>
#include "entity.h"

class Exit;

class Room : public Entity
{
public:
	Room(const string& name, const string& description, const string& color);
	~Room();

	string Look() const;
	

public:
	
	/*Exit* GetExit(const string& direction) const;*/
	
	const string color;

};

#endif //__Room__