#include <iostream>
#include <string>
#include <conio.h>
#include "world.h"
#include "globals.h"

using namespace std;

int main() 
{
	string input;
	
	World theCube;

	cout << theCube.EntryMessage();

	while(1)
	{
		if (_kbhit() != 0) {
			getline(cin, input);
			vector<string> args = Split(ToLowerCase(input), " ");
			if(args[0] == "quit")
				break;
			if (!theCube.Process(args))
				cout << "That's not a verb I recognise.\n";
		}

	}


}