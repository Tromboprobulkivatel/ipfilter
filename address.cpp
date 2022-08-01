#include <string>
#include <cassert>
#include "address.h"

address::address ( const std::string& String ) {
	auto triad { 0 };
	auto i { 0 };
	for ( const auto& c: String ) {
		if ( c == '.' ) {
			++triad;
			assert ( triad < AddressTriads );
		} else if ( c == '\t' ) {
			break;
		} else {
			value[ triad ] = value[ triad ] * 10 + ( c - '0' );
		}
		presentation[ i++ ] = c;
		assert ( i < AddressPresentationSize );
	}
	id = value[ 0 ] * 256 * 256 * 256
		 + value[ 1 ] * 256 * 256
		 + value[ 2 ] * 256
		 + value[ 3 ];
}

bool address::operator> ( const address& Comparing ) const {
	return id > Comparing.id;
}
