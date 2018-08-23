#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H
#include "blockNode.h"
#include "cryptopp700/integer.h"
#include <vector>



class BlockChain
{
	public:

		static BlockChain* getInstance()
		{
			static BlockChain instance;
			return instance;
		}
		
		~BlockChain(){}

		void Add()
		{
			//If this is very first block
			if(m_chain.size()==0)
			{
				_id +=1;
				Block *block = new Block(nullptr,_id);
				m_chain.push_back(block);
			}else
			{
				_id +=1;
				Block *block = new Block(_chain[_chain.size()-1],_id);
				_chain.push_back(block);
			}
		}
		void printChain()
		{
			for(int i =0; i< m_chain.size(); ++i)
				std::cout<<*m_chain[i]<<std::endl;
		}



	private:

		// Private Constructor
		BlockChain():_id(0){ }

		//Private Methods

		int StartMining()
		{
			int nonce = 0;
			
			Block 
		}



		
		// Cacluates SHA 256 Hash of the Header+Data 
		std::string FindHash(Block* source)
		{

			std::string combined = std::to_string(source->GetId())+std::to_string(source->GetTimestamp())
									+ source->GetData()+ source->GetPrevBlockHash()+ source->GetHash()
									+std::to_string(source->GetNonce());
			CryptoPP::SHA256 sha256;
			CryptoPP::byte const* dataToBeHashed = (byte*) combined.data();
			CryptoPP::byte outputHash[CryptoPP::SHA256::DIGESTSIZE];
			sha256.CalculateDigest(outputHash,dataToBeHashed,combined.size());

			CryptoPP::HexEncoder encoder;
			std::string output;

			encoder.Attach( new CryptoPP::StringSink( output ) );
			encoder.Put( outputHash, sizeof(outputHash) );
			encoder.MessageEnd();

			return output;

		}


		// Decodes a hash as Integer(part of Crypto++ Integer class)
		CryptoPP::Integer DecodeHash(std::string hash)
		{
			HexDecoder decoder;
			std::string decoded;
			decoder.Attach(new CryptoPP::StringSink(decoded));
			decoder.Put( (byte*)hashInput.data(), hashInput.size() );
			decoder.MessageEnd();
			byte *data = (byte*)decoded.data();
			Integer c(data,sizeof(data));
			return c;
		}

		//Constants
		const int targetBit = 24;

		// Members
		std::vector<Block*> m_chain;
		int m_id;



};
BlockChain* BlockChain::_instance= nullptr;


#endif