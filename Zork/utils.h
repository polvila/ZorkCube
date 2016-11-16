#ifndef __Utils__
#define __Utils__

#include <vector>
#include <list>
#include "entity.h"

using namespace std;

string& LowerCase(const string& sentence, string& lowSentence);
string& UpperCase(const string& sentence, string& upperSentence);
void Split(string& command, const string& delimiter, vector<string>& args);
void PrintColorNameWithColor(string& colorName);
list<Entity*> JoinLists(list<Entity*> a, list<Entity*> b);
Entity* Find(list<Entity*> container, const EntityType& entityType, const string& entityName);
Entity* FindAny(list<Entity*> container, const EntityType& entityType);

#endif //__Utils__