#include "blockChain.h"
#include <iostream>



int main()
{
	BlockChain *chain = BlockChain::getInstance();
	chain->Add();
	chain->Add();
	chain->Add();
	chain->printChain();



}