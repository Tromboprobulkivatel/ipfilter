#include <iostream>
#include <vector>
#include <array>
#include <cassert>

const auto AddressPresentationSize { 16 };
const auto AddressTriads { 4 };

struct address {
	char presentation[AddressPresentationSize] {};
	std::array<unsigned char, AddressTriads> value {};
	unsigned int id;

	address ( const std::string& String ) {
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
	bool operator> ( const address& Comparing ) const {
		return id > Comparing.id;
	}
};

auto read () {
	std::vector<address> list;
	for ( std::string input; std::getline ( std::cin, input ); ) {
		list.push_back ( input );
	}
	return list;
}

void output ( const std::vector<address>& List ) {
	for ( auto& item: List ) {
		std::cout << item.presentation << std::endl;
	}
}

int main () {
	auto list = read ();
	std::sort ( list.begin (), list.end (), std::greater<address> () );
	output ( list );
	std::vector<address> filtered;
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( address& item ) { return item.value[ 0 ] == 1; } );
	output ( filtered );
	filtered.clear();
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( address& item ) { return item.value[ 0 ] == 46 && item.value[ 1 ] == 70; } );
	output ( filtered );
	filtered.clear();
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( address& item ) {
		return item.value[ 0 ] == 46
			   || item.value[ 1 ] == 46
			   || item.value[ 2 ] == 46
			   || item.value[ 3 ] == 46;
	} );
	output ( filtered );
	return 0;
}
