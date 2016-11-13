#include <iostream>
#include <string>
#include <conio.h>
#include "world.h"
#include "globals.h"

using namespace std;

int main() 
{
	string input;
	
	World* theCube = new World();

	while(true)
	{
		if (_kbhit() != 0) 
		{
			getline(cin, input);
			vector<string> args = Split(GetLowerCase(input), " ");
			if (args[0] == "quit" || args[0] == "q")
			{
				cout << "Are you sure you want to leave? (yes/no)\n\n";
				getline(cin, input);
				if (input == "yes")
					break;
				cout << "Resumed.\n\n";
			}else if (!theCube->Process(args))
				cout << "That's not a verb I recognise.\n\n";
		}

		if(theCube->GameLoop() == false)
		{
			cout << "Do you want to play again? (yes/no)\n\n";

			getline(cin, input);

			if (input == "yes")
			{
				system("cls");
				theCube = new World();
			}
			else 
				break;
		}
	}


}