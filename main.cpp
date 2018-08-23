#include <iostream>
#include <ctime>
#include <iostream>
#include<string>
#include <functional>
#include "blockNode.h"
#include "blockChain.h"
#include "cryptopp700/sha.h"
#include "cryptopp700/hex.h"
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1


using namespace CryptoPP;



int main()
{
	BlockChain blockChain = BlockChain::getInstance();
	blockChain.Add("I paid Alex $20!");
	blockChain.Add("Alex paid Charlie $100");
	blockChain.Add("Alex got 10 Coin!");

	blockChain.printChain();

}

