#include <iostream>
#include <string>
#include <conio.h>
#include "world.h"

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
			theCube.Check(input);
		}

	}
}