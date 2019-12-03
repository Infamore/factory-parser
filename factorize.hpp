#include <string>
#include "base.hpp"
#include <vector>
#include "token_leech.hpp"
#include "returns.hpp"
#include "object.hpp"
#include <cstring>
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"
#include <stdio.h>


class Factory
{

private:
std::string str;
Base* receiver;
Base* right_n;
public:

Base* parse(char** input, int length)
{
	if (input[0] == " ")
		return nullptr;	

	char* charstr[1] = {};
	charstr[0] = input[0];
	const char* wtfcharstr = charstr[0];
	std::string tfcharstr = wtfcharstr;
tfcharstr.erase(std::remove_if(tfcharstr.begin(), tfcharstr.end(),::isspace), tfcharstr.end());
	std::vector<std::string> string_members;
	string_members.push_back(tfcharstr);
//part1---------------------------
	std::string str = "/+*-";
	std::string example;
	char* container = (char*)str.c_str();
	std::strcpy(container,str.c_str());
	std::vector<char> vects;
	vects = return__(string_members[0]);
	example = token_dropper(string_members[0], container);
	std::vector<int> the_selection;
	the_selection = objects(example);

//part2---------------------------		

int option_count = 1;
Base* left_n = new Op((double)the_selection[0]);

Base* right_n;
Base* receiver;
for (int i = 0; i < vects.size(); i++)
{
	std::cout << i << std::endl;
	if (vects[i] == '/')
	{
		right_n = new Op((double)the_selection[option_count]);
		receiver = new Div(left_n, right_n);
		left_n = receiver;
	}

	else if (vects[i] == '*')
	{
		right_n = new Op((double)the_selection[option_count]);
		receiver = new Mult(left_n, right_n);
		left_n = receiver;
	}

	else if (vects[i] == '+')
	{
		right_n = new Op((double)the_selection[option_count]);
		receiver = new Add(left_n, right_n);
		left_n = receiver;
	}

	else if (vects[i] == '-')
	{
		right_n = new Op((double)the_selection[option_count]);
		receiver = new Sub(left_n, right_n);
		left_n = receiver;
	}
	else
		throw "no tributes!";
	option_count++;
	
}
//part3---------------------------------------------

	return receiver;
}


};
