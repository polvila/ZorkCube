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

	void Look() const override;
	void GoTo(const string& direction);
	void Take(const string& object);
	void ShowInventory();
	void Drop(const string& object);
	void PutInside(const string& object, const string& container);
	bool HasThisItem(const string& object);
	void ShowStatus() const;
	void Use(const string& object);
	bool DecreaseHealth(int percentage);
	void IncreaseHealth(int percentage);
	void DecreaseHungry(int percentage);
	bool IncreaseHungry(int percentage);
	void Open(const string& object);

	Room* location;
	int health;
	int hungry;
	
private:

	void TryToGoThrowThat(Exit* exit);
	void ChangePlayerLocationAndLook(Room* destination);
};

#endif //__Player__