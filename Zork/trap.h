#ifndef __Trap__
#define __Trap__

#include "entity.h"

class Player;
using namespace std;

class Trap : public Entity
{
public:
	Trap(const string& name, const string& description, int damage);
	~Trap();

	void MakeDamage(Player* player) const;

	string description;
	int damage;
};

#endif //__Trap__
