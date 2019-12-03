#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <cstring>
#include <sstream>

//using namespace std;

std::string token_dropper(std::string exp, char* delim)
{
	std::vector<char> chars;
	for (int i = 0; i < exp.length(); i++)
		chars.push_back(delim[i]);
	std::string::iterator iterators = exp.begin();
	while (iterators != exp.end())
	{
		for (int i = 0; i < chars.size(); i++)
		{
			if (*iterators == chars[i]) 
				*iterators = ' '; //bring forth the sacrificed tokens!
		}

		iterators++;
	}
	std::string tribute = exp; // >:D!!!

	return tribute; //namaste
}
