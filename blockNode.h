#ifndef BLOCKCHAIN_BLOCKNODE_H
#define BLOCKCHAIN_BLOCKNODE_H
#include <ctime>
#include <iostream>


class Block
{

	public:
		Block(Block * prevBlock,int id)
		{
			_prevBlock = prevBlock;
			_timestamp = time(0);
			_id = id;

		}

		friend std::ostream & operator << (std::ostream &out, const Block &c)
		{
			out<<"Id: "<<c._id<<"\n";
			out<<ctime(&c._timestamp);
			return out;
		}

	private:
		int _id;
		time_t _timestamp;
		Block * _prevBlock;
		// Hash _hash;


};




#endif