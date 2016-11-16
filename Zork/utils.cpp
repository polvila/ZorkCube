#include <ctype.h> 
#include "utils.h"
#include "windows.h"
#include <string>
#include <iostream>

using namespace std;

string& LowerCase(const string& sentence, string& lowSentence)
{
	lowSentence = sentence;
	for (string::iterator it = lowSentence.begin(); it < lowSentence.end(); ++it)
	{
		if(isupper(*it))
			*it = tolower(*it);
	}
	return lowSentence;
}

string& UpperCase(const string& sentence, string& upperSentence)
{
	upperSentence = sentence;
	for (string::iterator it = upperSentence.begin(); it < upperSentence.end(); ++it)
	{
		if (islower(*it))
			*it = toupper(*it);
	}
	return upperSentence;
}

void Split(string& sentence, const string& delimiter, vector<string>& args)
{
	size_t pos = 0;
	string token;
	while ((pos = sentence.find(delimiter)) != string::npos) {
		token = sentence.substr(0, pos);
		if (token != "")
			args.push_back(token);
		sentence.erase(0, pos + delimiter.length());
	}
	args.push_back(sentence);
}

void PrintColorNameWithColor(string& colorName) {
	int color = 7;
	if (colorName == "GREEN")
		color = 2;
	else if (colorName == "RED")
		color = 4;
	else if (colorName == "ORANGE")
		color = 6;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << colorName;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

list<Entity*> JoinLists(list<Entity*> a, list<Entity*> b)
{
	list<Entity*> aPlusB;
	aPlusB = a;
	aPlusB.insert(aPlusB.end(), b.begin(), b.end());
	return aPlusB;
}

Entity* Find(list<Entity*> container, const EntityType& entityType, const string& entityName)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		string name;
		LowerCase((*it)->name, name);
		if ((*it)->type == entityType && name == entityName)
			return *it;
	}
	return nullptr;
}

Entity* FindAny(list<Entity*> container, const EntityType& entityType)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		if ((*it)->type == entityType)
			return *it;
	}
	return nullptr;
}