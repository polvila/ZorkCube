#ifndef __Player__
#define __Player__

#include "room.h"
#include "entity.h"

class Item;
using namespace std;

class Player : public Entity
{
public:
	Player(const string& name, const string& description, Room* location);
	~Player();

	bool Look() override;
	bool GoTo(const string& direction);
	bool Take(const string& object);
	bool ShowInventory() const;
	bool Drop(const string& object);
	bool PutInside(const string& object, const string& container);
	bool HasThisItem(const string& object) const;
	bool ShowStatus() const;
	bool Use(const string& object);
	bool DecreaseHealth(int percentage);
	void IncreaseHealth(int percentage);
	void DecreaseHungry(int percentage);
	bool IncreaseHungry(int percentage);
	bool Open(const string& object);

	Room* location;
	int health;
	int hungry;
	
private:

	void TryToGoThrowThat(Exit* exit);
	void ChangePlayerLocationAndLook(Room* destination);
	static Entity* Find(list<Entity*> container, const EntityType& entityType, const string& entityName);
	bool IsAPossible(string direction) const;
	void UseHealthIncrementer(Entity* entity);
	void UseHungryDecrementer(Entity* entity);
	void MoveItemsToInventory(Entity* itemContainer);
	void PutItemInsideItemContainer(Entity* item, Entity* itemContainer);
	void FillPossibleDirections();
	void TunnelConfirmation(Room* destination);
	
	vector<string> directions;
};

#endif //__Player__