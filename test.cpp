#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "address.h"

TEST_CASE( "Testing the address class" ) {
	address localhost ( "127.0.0.1" );
	address server ( "1.0.0.10" );
	CHECK( ( localhost > server ) );
}
