#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H
#include "blockNode.h"
#include "cryptopp700/integer.h"
#include "cryptopp700/sha.h"
#include "cryptopp700/hex.h"
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <vector>
#include <limits.h>



class BlockChain
{
	public:

		static BlockChain& getInstance()
		{
			static BlockChain instance;
			return instance;
		}
		
		~BlockChain(){}

		// Adds a Block with data. Returns 0 if success else -1.
		//TODO: Throw exception rather than integer code value.
		int Add(std::string data)
		{
			Block * block = FindBlockWithProofOfWork(m_id,data);
			if(block!=nullptr)
			{
				m_chain.push_back(block);
				m_id++;
				return 0;
			}
			else 
			{
				std::cout<<"Adding Failed!...."<<std::endl;
				return -1;
			}

		}
		void printChain()
		{
			for(size_t i =0; i< m_chain.size(); ++i)
				std::cout<<*m_chain[i]<<std::endl;
		}



	private:

		// Private Constructor
		BlockChain():TARGET_BIT(10),m_id(0){ }

		//Private Methods

		Block* FindBlockWithProofOfWork(int id, std::string data)
		{
			const short SHA256_BIT_SIZE = 256;
			CryptoPP::Integer target(1);
			target = target<<(SHA256_BIT_SIZE-TARGET_BIT);
			if(m_id<1)
			{
				int nonce = 0;
				std::cout<<"Creating Genesis Block..."<<std::endl;
				Block *myBlock = new Block(id,"N/A",data,"N/A",nonce);

				while(nonce< INT_MAX)
				{
					myBlock->SetNonce(nonce);
					CryptoPP::byte* hashOfBlock = FindHash(myBlock);
					myBlock->SetHash(ConvertHashByteToString(hashOfBlock));

					if(DecodeHashToInt(hashOfBlock) < target)
					{
						std::cout<<"Block Creation Complete..."<<std::endl;
						return myBlock;
					}
					else{
						nonce++;
					}

				}
			}
			else
			{

				int nonce = 0;
				std::cout<<"Finding a Block..."<<std::endl;
				Block *myBlock = new Block(id,"N/A",data,m_chain[m_chain.size()-1]->GetHash(),nonce);
				
				while(nonce< INT_MAX)
				{
					myBlock->SetNonce(nonce);
					CryptoPP::byte* hashOfBlock = FindHash(myBlock);
					myBlock->SetHash(ConvertHashByteToString(hashOfBlock));

					if(DecodeHashToInt(hashOfBlock) < target)
					{
						std::cout<<"Block Creation Complete..."<<std::endl;
						return myBlock;
					}
					else{
						nonce++;
					}

				}


			}

			return nullptr;
		}

		//Finds SHA 256 Hash into array bytes. Hash( header + data + nonce )
		CryptoPP::byte* FindHash(Block* source)
		{
			std::string combined = std::to_string(source->GetId())+std::to_string(source->GetTimestamp())
									+ source->GetData()+ source->GetPrevBlockHash()
									+std::to_string(source->GetNonce());
			CryptoPP::SHA256 sha256;
			CryptoPP::byte const* dataToBeHashed = (CryptoPP::byte*) combined.data();
			CryptoPP::byte *outputHash = new CryptoPP::byte[CryptoPP::SHA256::DIGESTSIZE];
			sha256.CalculateDigest(outputHash,dataToBeHashed,combined.size());
			return outputHash;
		}

		
		// Converts SHA 256 Hash bytes array to string 
		std::string ConvertHashByteToString(CryptoPP::byte* hashData)
		{
			CryptoPP::HexEncoder encoder;
			std::string output;
			encoder.Attach( new CryptoPP::StringSink( output ) );
			encoder.Put( hashData, CryptoPP::SHA256::DIGESTSIZE );
			encoder.MessageEnd();
			return output;
		}



		// Decodes a hash as Integer(part of Crypto++ Integer class)
		CryptoPP::Integer DecodeHashToInt(CryptoPP::byte* hashData)
		{
			CryptoPP::Integer c(hashData,CryptoPP::SHA256::DIGESTSIZE);
			return c;
		}

		//Constants
		const int TARGET_BIT ;

		// Members
		std::vector<Block*> m_chain;
		int m_id;

};


#endif