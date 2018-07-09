#include "blockNode.h"
#include <iostream>


int main()
{
	int id = 0;
	Block *b = new Block(nullptr,++id);
	std::cout<<*b<<std::endl;
	Block *c = new Block(b,++id);
	std::cout<<*c<<std::endl;


}