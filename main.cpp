#include <iostream>
#include <ctime>
#include <iostream>
#include<string>
#include <functional>
#include "blockNode.h"
#include "cryptopp700/sha.h"
#include "cryptopp700/hex.h"
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1


using namespace CryptoPP;

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

Integer decodeHashValue(std::string hashInput)
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


int main()
{
	Block *b = new Block(1,"hello","hello","hello",1);

	std::string hash = FindHash(b);

	Integer s= decodeHashValue(hash);
	
	std::cout<<s<<std::endl;

	// BlockChain *chain = BlockChain::getInstance();

	chain-> Add("transaction");
	// chain->Add();
	// chain->Add();
	// chain->Add();
	// chain->printChain();

	// std::string message = "helo";
	// CryptoPP::SHA256 sha256;
	// CryptoPP::byte const* dataToBeHashed = (byte*) message.data();
	// CryptoPP::byte outputHash[CryptoPP::SHA256::DIGESTSIZE];
	// sha256.CalculateDigest(outputHash,dataToBeHashed,message.size());

	// for(int i =0; i<sizeof(outputHash); ++i)
	// {
	// 	std::cout<<(int)outputHash[i]<<std::endl;
	// }

	// CryptoPP::HexEncoder encoder;
	// std::string output;

	// encoder.Attach( new CryptoPP::StringSink( output ) );
	// encoder.Put( outputHash, sizeof(outputHash) );
	// encoder.MessageEnd();

	// std::cout<<output<<std::endl;

	// byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];
	// std::string message = "abcdfghijklmnopqrstuvwxyz";

	// CryptoPP::Weak::MD5 hash;
	// hash.CalculateDigest( digest, (const byte*)message.c_str(), message.length() );

	// CryptoPP::HexEncoder encoder;
	// std::string output;

	// encoder.Attach( new CryptoPP::StringSink( output ) );
	// encoder.Put( digest, sizeof(digest) );
	// encoder.MessageEnd();

	// std::cout << output << std::endl;


}

