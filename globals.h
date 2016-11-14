#ifndef __Globals__
#define __Globals__

#include <vector>

using namespace std;

void GetLowerCase(string& sentence);
void GetUpperCase(string& sentence);
vector<string> Split(string& command, const string& delimiter);
void PrintColorNameWithColor(string& colorName);

#endif //__Globals__