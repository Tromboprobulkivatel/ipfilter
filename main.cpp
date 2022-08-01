#include <iostream>
#include <vector>
#include "address.h"

auto read () {
	std::vector<address> list;
	list.reserve ( 100 );
	for ( std::string input; std::getline ( std::cin, input ); ) {
		list.emplace_back ( input );
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
	filtered.reserve ( list.size () );
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( const address& item ) { return item.value[ 0 ] == 1; } );
	output ( filtered );
	filtered.clear ();
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( const address& item ) { return item.value[ 0 ] == 46 && item.value[ 1 ] == 70; } );
	output ( filtered );
	filtered.clear ();
	std::copy_if ( list.begin (), list.end (), std::back_inserter ( filtered ),
				   [] ( const address& item ) {
					   return item.value[ 0 ] == 46
							  || item.value[ 1 ] == 46
							  || item.value[ 2 ] == 46
							  || item.value[ 3 ] == 46;
				   } );
	output ( filtered );
	return 0;
}
