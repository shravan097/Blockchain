#ifndef BLOCKCHAIN_BLOCKNODE_H
#define BLOCKCHAIN_BLOCKNODE_H
#include <ctime>
#include <iostream>
#include<string>
#include <functional>


// This class consists the definition of the block. It consists
// of previous block hash, timestamp, id, hash of its data and nonce(POW).

class Block
{

	public:
		Block(int id,std::string prevBlockHash,std::string data, std::string currentHash, int nonce):
		m_id(id),m_timestamp(time(0)),m_data(data),m_prevBlockHash(prevBlockHash),m_hash(currentHash),m_nonce(nonce)
		{ }


		friend std::ostream & operator << (std::ostream &out, const Block &c)
		{
			out<<"Id: "<<c.m_id<<"\n";
			out<<ctime(&c.m_timestamp);
			out<<"Hash: "<<c.m_hash;
			return out;
		}

		int GetId() const {return m_id;}
		time_t GetTimestamp() const {return m_timestamp;}
		std::string GetData() const { return m_data;}
		std::string GetPrevBlockHash() const {return m_prevBlockHash;}
		std::string GetHash() const {return m_hash;}
		int GetNonce() const {return m_nonce;}


	private: 
		int m_id;
		time_t m_timestamp;
		std::string m_data;
		std::string  m_prevBlockHash;
		std::string m_hash;
		int m_nonce;

};




#endif