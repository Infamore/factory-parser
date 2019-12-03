#include "factory.hpp"
#include "base.hpp"
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <iostream>

//using namespace std;

int main(int argc, char* argv[])
{
std::string exptree;
std::vector<std::string> vect;
std::vector<char*> vects;
char* vectchar[argc];

for(int count = 1; count < argc; count++) 
	vectchar[count - 1] = argv[count];

for (int count1 = 0; count1 < argc - 1; count1++)
	exptree += vectchar[count1];

vect.push_back(exptree);

for(int count2 = 0; count2 < vect.size() - 1; count2++)
	vect[count2].erase(std::remove_if(vect[count2].begin(), vect[count2].end(),::isspace), vect[count2].end());

for(int i = 0; i < vect.size(); i++)
	std::cout << vect[i] << std::endl;

char* charray[vect.size()];

charray[0] = (char*)vect[0].data();

//for(int i = 0; i < sizeof charray - 1; i++)
//	std::cout << charray[i] << std::endl;
/*
std::cout << "3" << std::endl;
for(int count2 = 0; count2 < vect.size() - 1; count2++) 
	vects[count2] = (char*)vect[count2].c_str();
std::cout << "4" << std::endl;
for(int count3 = 0; count3 < vects.size() - 1; count3++)
	std::cout << vects[count3] << std::endl;
*/
/*std::vector<char*> vectorse;
vectorse.push_back("3*45/1");
std::cout << "calculator" << std::endl;
Factory* fact;
std::cout << "about to parse" << std::endl;
*/

Factory* fact;
long lengths = sizeof charray;
Base* dependent = fact->parse(charray, (int)(lengths));
std::cout << "value: " << dependent->evaluate() << std::endl;
std::cout << dependent->stringify() << std::endl;
//return dependent->evaluate();			
 return 0;
}
