#ifndef __Player__
#define __Player__

#include "room.h"
#include "entity.h"

using namespace std;

class Player : public Entity
{
public:
	Player(const string& name, const string& description, Room* location);
	~Player();

	string Look() const;
	string GoTo(const string& direction);

public:

	Room* location;
	
private:
	
	string TryToGoThrowThat(Exit* exit);
	string ChangePlayerLocationAndLook(Room* destination);

};

#endif //__Player__