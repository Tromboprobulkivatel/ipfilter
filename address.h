#ifndef IPFILTER_ADDRESS_H
#define IPFILTER_ADDRESS_H

#include <array>
#include "address.h"

struct address {
	static const unsigned char AddressPresentationSize { 16 };
	static const unsigned char AddressTriads { 4 };
	char presentation[AddressPresentationSize] {};
	std::array<unsigned char, AddressTriads> value {};
	unsigned int id;

	explicit address ( const std::string& String );
	bool operator> ( const address& Comparing ) const;
};

#endif
