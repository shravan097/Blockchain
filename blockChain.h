#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H
#include "blockNode.h"
#include <vector>



class BlockChain
{
	public:
		static BlockChain * _instance;

		static BlockChain* getInstance()
		{
			if(_instance==nullptr)
				_instance = new BlockChain();
			return _instance;
		}

		void Add()
		{
			//If this is very first block
			if(_chain.size()==0)
			{
				_id +=1;
				Block *block = new Block(nullptr,_id);
				_chain.push_back(block);
			}else
			{
				_id +=1;
				Block *block = new Block(_chain[_chain.size()-1],_id);
				_chain.push_back(block);
			}
		}
		void printChain()
		{
			for(int i =0; i< _chain.size(); ++i)
				std::cout<<*_chain[i]<<std::endl;
		}

	private:
		BlockChain(){_id=0; }
		std::vector<Block*> _chain;
		int _id;


};
BlockChain* BlockChain::_instance= nullptr;


#endif