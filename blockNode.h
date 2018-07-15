#ifndef BLOCKCHAIN_BLOCKNODE_H
#define BLOCKCHAIN_BLOCKNODE_H
#include <ctime>
#include <iostream>
#include<string>
#include <functional>


class Block
{

	public:
		Block(Block * prevBlock,int id)
		{
			_prevBlock = prevBlock;
			_timestamp = time(0);
			_id = id;
			_hash=this->getHash();

		}


		friend std::ostream & operator << (std::ostream &out, const Block &c)
		{
			out<<"Id: "<<c._id<<"\n";
			out<<ctime(&c._timestamp);
			out<<"Hash: "<<c._hash;
			return out;
		}

	private: 
		std::string getHash()
		{

			std::string result = "";
			result+=std::to_string(hash(_id));
			result+=std::to_string(_timestamp);
			return result;
		}
		unsigned int hash(unsigned int x) 
		{
		    x = ((x >> 16) ^ x) * 0x45d9f3b;
		    x = ((x >> 16) ^ x) * 0x45d9f3b;
		    x = (x >> 16) ^ x;
		    return x;
		}

		int _id;
		time_t _timestamp;
		Block * _prevBlock;
		std::string _hash;


};




#endif