#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <cstring>
#include <sstream>

//using namespace std;

std::vector<char> return__(std::string exp) //returns a vector of elements
{//has to be done before the other function
std::vector<char> charvector;
	std::string::iterator iterators = exp.begin();
	while (iterators != exp.end())
	{
		if (*iterators == '*' || *iterators == '+' || *iterators == '/' || *iterators == '-')
			charvector.push_back(*iterators);
		iterators++;
	}
	return charvector;
}
