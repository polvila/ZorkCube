#ifndef __Item__
#define __Item__

#include "entity.h"

enum ItemType
{
	COMMON,
	EQUIPABLE,
	CONSUMABLE
};

class Item : public Entity
{
public:
	Item(const string& name, const string& description, ItemType item_type = COMMON);
	~Item();

	void Look() const;

public:
	ItemType item_type;
};

#endif //__Item__