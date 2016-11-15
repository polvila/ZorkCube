#ifndef __Globals__
#define __Globals__

#include <vector>

using namespace std;

void GetLowerCase(string& sentence);
void GetUpperCase(string& sentence);
void Split(string& command, const string& delimiter, vector<string> args);
void PrintColorNameWithColor(string& colorName);

#endif //__Globals__