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

	bool Look() const override;
	void GoToNextPosition(vector<Room*> roomsChange);
	void SaveAllExits();
	void SetNextPosition(Room* nextPosition);
	void PrintColorRoom() const;
	
	const string color;
	list<Entity*> exitsSaved;
	Room* nextPosition;

private:

	void RemoveAllExits();
	void PutAll(list<Entity*>& exits) const;
	void ChangeExitDestinations(vector<Room*> roomChanges) const;
	static Room* GetRoomNextPosition(vector<Room*> roomChanges, Room* destination);
};

#endif //__Room__