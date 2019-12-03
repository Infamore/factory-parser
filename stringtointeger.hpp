#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <cstring>
#include <sstream>

//using namespace std;


std::vector<int> objects(std::string parsed_str)
{
	int temp;
	std::vector<int> integers;
	std::vector<std::string> tributes;
	std::stringstream string_tokenizer(parsed_str);
	std::string sub_str;
	
	while (getline(string_tokenizer, sub_str, ' '))
	{
		tributes.push_back(sub_str);
	}
	
	for (int count = 0; count < tributes.size(); count++)
	{
		std::stringstream int_str(tributes[count]);
		int_str >> temp;
		integers.push_back(temp);
	}

	/*while (iter_pos != parsed_str.end())
 * 	{
 * 			if (*iter_pos == ' ') //if there are more than one space, check the calculator 
 * 					{
 * 						
 * 									sub_str = parsed_str.substr(start, distance(iterators, iter_pos + 1));
 * 												//stringstream int_str(sub_str); 
 * 															//int_str >> temp; //could be an error if space is in the sub_str
 * 																		//integers.push_back(temp);
 * 																					integers.push_back(sub_str);
 * 																								start = (iter_pos - parsed_str.begin()) + 2;
 * 																											iterators = iter_pos + 2;
 * 																														iter_pos = iterators;
 * 																																	iter_pos++;
 * 																																			}
 * 																																					iter_pos++;
 * 																																						}*/

return integers;
}
