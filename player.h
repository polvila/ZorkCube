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

	void Look() const;
	void GoTo(const string& direction);
	void Take(const string& object);
	void ShowInventory();

public:

	Room* location;
	
private:

	void TryToGoThrowThat(Exit* exit);
	void ChangePlayerLocationAndLook(Room* destination);

};

#endif //__Player__