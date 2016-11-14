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
			GetLowerCase(input);
			vector<string> args = Split(input, " ");
			if (args[0] == "quit" || args[0] == "q")
			{
				cout << "Are you sure you want to leave? (yes/no)\n\n>";
				getline(cin, input);
				if (input == "yes")
					break;
				cout << "Resumed.\n\n>";
			}else if (!theCube->Process(args))
				cout << "Sorry, I do not understand your command.\n\n>";
		}

		if(theCube->GameLoop() == false)
		{
			cout << "Do you want to play again? (yes/no)\n\n>";

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