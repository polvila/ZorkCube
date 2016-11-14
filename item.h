#ifndef __Item__
#define __Item__

#include "entity.h"

enum ItemType
{
	COMMON,
	EQUIPABLE,
	CONTAINER,
	HEALTH,
	HUNGRY
};

class Item : public Entity
{
public:
	Item(const string& name, const string& description, ItemType item_type = COMMON, int percentage = 0);
	~Item();

	void Look() const override;

	ItemType item_type;
	int percentage;
};

#endif //__Item__