#ifndef __Trap__
#define __Trap__

#include <string>

using namespace std;

class Trap
{
public:
	Trap(const string& description, int damage);
	~Trap();

	string description;
	int damage;
};

#endif //__Trap__
