#ifndef __Globals__
#define __Globals__

#include <vector>
#include <list>
#include "entity.h"

using namespace std;

void GetLowerCase(string& sentence);
void GetUpperCase(string& sentence);
void Split(string& command, const string& delimiter, vector<string>& args);
void PrintColorNameWithColor(string& colorName);
list<Entity*> JoinLists(list<Entity*> a, list<Entity*> b);

#endif //__Globals__