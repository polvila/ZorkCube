#include <ctype.h> 
#include "globals.h"
#include "windows.h"
#include <string>
#include <iostream>

using namespace std;

void GetLowerCase(string& sentence)
{
	for (string::iterator it = sentence.begin(); it < sentence.end(); ++it)
	{
		if(isupper(*it))
			*it = tolower(*it);
	}
}

void GetUpperCase(string& sentence)
{
	for (string::iterator it = sentence.begin(); it < sentence.end(); ++it)
	{
		if (islower(*it))
			*it = toupper(*it);
	}
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