#include <ctype.h> 
#include "globals.h"

using namespace std;

string ToLowerCase(string sentence)
{
	for (string::iterator it = sentence.begin(); it < sentence.end(); ++it)
	{
		if(isupper(*it))
			*it = tolower(*it);
	}
	return sentence;
}

void ToBold(string& sentence)
{
	sentence = "\e[1m" + sentence + "\e[0m";
}

vector<string> Split(string& sentence, const string& delimiter)
{
	vector<string> args;
	size_t pos = 0;
	string token;
	while ((pos = sentence.find(delimiter)) != string::npos) {
		token = sentence.substr(0, pos);
		if (token != "")
			args.push_back(token);
		sentence.erase(0, pos + delimiter.length());
	}
	args.push_back(sentence);
	return args;
}
